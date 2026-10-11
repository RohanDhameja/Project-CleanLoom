// =====================================================
// GP2Y10 DUST SENSOR
// + POTENTIOMETER THRESHOLD
// + 16x2 I2C LCD
// + WARNING LED
// + PUSH BUTTON
// + MOTOR CONTROL
// =====================================================
// Arduino Nano
// =====================================================

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// =====================================================
// LCD
// =====================================================

#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

// =====================================================
// GP2Y10 DUST SENSOR
// =====================================================

#define GP2Y10_LED_PIN 6
#define GP2Y10_VOUT_PIN A0

// =====================================================
// POTENTIOMETER
// =====================================================

#define POT_PIN A1

// Adjustable threshold: 0 to 25 mg/m3
float dustThreshold = 0.0;

// =====================================================
// WARNING LED
// =====================================================

#define WARNING_LED_PIN 2

// =====================================================
// PUSH BUTTON
// =====================================================

#define PUSH_BUTTON_PIN 4

// =====================================================
// MOTOR PINS
// =====================================================

#define LEFT_MOTOR_PIN 9
#define LEFT_MOTOR_PIN2 12
#define RIGHT_MOTOR_PIN 8

// =====================================================
// WARNING SETTINGS
// =====================================================

// Dust must remain above threshold for 2 seconds
const unsigned long WARNING_ON_TIME = 2000UL;

// Dust must remain below threshold for 8 seconds
// before warning turns OFF
const unsigned long WARNING_OFF_TIME = 8000UL;

// =====================================================
// MOTOR SETTINGS
// =====================================================

// 12 hours
const unsigned long MOTOR_CYCLE_TIME = 43200000UL;

// Left motor automatic ON time
const unsigned long LEFT_MOTOR_ON_TIME = 1046UL;

// Right motor automatic ON time
const unsigned long RIGHT_MOTOR_ON_TIME = 2000UL;

// =====================================================
// SENSOR UPDATE
// =====================================================

const unsigned long SENSOR_INTERVAL = 100UL;

// =====================================================
// VARIABLES
// =====================================================

bool warningLEDState = false;

bool leftMotorState = false;
bool rightMotorState = false;

unsigned long warningHighStart = 0;
unsigned long warningLowStart = 0;

unsigned long motorCycleStart = 0;

unsigned long lastSensorRead = 0;

// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(9600);

  // =================================================
  // LCD
  // =================================================

  lcd.init();
  lcd.backlight();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Dust Monitor");

  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  delay(2000);

  lcd.clear();

  // =================================================
  // GP2Y10
  // =================================================

  pinMode(GP2Y10_LED_PIN, OUTPUT);
  pinMode(GP2Y10_VOUT_PIN, INPUT);

  // =================================================
  // POTENTIOMETER
  // =================================================

  pinMode(POT_PIN, INPUT);

  // =================================================
  // WARNING LED
  // =================================================

  pinMode(WARNING_LED_PIN, OUTPUT);

  // =================================================
  // PUSH BUTTON
  // =================================================

  pinMode(PUSH_BUTTON_PIN, INPUT);

  // =================================================
  // MOTORS
  // =================================================

  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);

  // =================================================
  // INITIAL STATES
  // =================================================

  // GP2Y10 IR LED OFF
  digitalWrite(GP2Y10_LED_PIN, HIGH);

  // Warning LED OFF
  // Your warning LED is active LOW
  digitalWrite(WARNING_LED_PIN, HIGH);

  // =================================================
  // START AUTOMATIC MOTOR CYCLE
  // =================================================

  leftMotorState = true;
  rightMotorState = true;

  digitalWrite(LEFT_MOTOR_PIN, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);

  digitalWrite(RIGHT_MOTOR_PIN, HIGH);

  motorCycleStart = millis();

  // =================================================
  // SERIAL STARTUP
  // =================================================

  Serial.println();
  Serial.println("======================================");
  Serial.println("         DUST MONITOR STARTED");
  Serial.println("======================================");

  Serial.println("GP2Y10       : READY");
  Serial.println("Potentiometer: A1");
  Serial.println("LCD          : READY");
  Serial.println("Warning LED  : D2");
  Serial.println("Push Button  : D4");
  Serial.println("Left Motor   : D9");
  Serial.println("Right Motor  : D8");

  Serial.println("--------------------------------------");

  Serial.println("Sensor range : 0.000 - 25.000 mg/m3");
  Serial.println("Threshold    : 0.000 - 25.000 mg/m3");
  Serial.println("Motor cycle  : 12 hours");

  Serial.println("======================================");
  Serial.println();

  Serial.println(">>> MOTOR CYCLE START");
  Serial.println(">>> LEFT MOTOR  : ON");
  Serial.println(">>> RIGHT MOTOR : ON");
}

// =====================================================
// READ GP2Y10
// =====================================================

int readDustSensor()
{
  // Turn GP2Y10 IR LED ON
  digitalWrite(GP2Y10_LED_PIN, LOW);

  delayMicroseconds(280);

  // Read analog output
  int adcValue = analogRead(GP2Y10_VOUT_PIN);

  delayMicroseconds(40);

  // Turn GP2Y10 IR LED OFF
  digitalWrite(GP2Y10_LED_PIN, HIGH);

  delayMicroseconds(9680);

  return adcValue;
}

// =====================================================
// CALCULATE DUST DENSITY
// =====================================================

float calculateDustDensity(int adcValue)
{
  // Convert ADC to voltage
  float voltage = adcValue * (5.0 / 1023.0);

  // Existing GP2Y10 calculation
  float rawDust = (0.17 * voltage) - 0.1;

  // Prevent negative value
  if (rawDust < 0)
  {
    rawDust = 0;
  }

  // =================================================
  // MAP SENSOR VALUE TO 0 - 25 mg/m3
  //
  // Existing raw calculation:
  // 0.000 -> 0 mg/m3
  // 0.750 -> 25 mg/m3
  // =================================================

  float dustDensity = (rawDust / 0.75) * 25.0;

  // Limit maximum to 25
  if (dustDensity > 25.0)
  {
    dustDensity = 25.0;
  }

  return dustDensity;
}

// =====================================================
// READ POTENTIOMETER
// =====================================================

void updateThreshold()
{
  int potValue = analogRead(POT_PIN);

  // =================================================
  // POTENTIOMETER RANGE
  //
  // 0    -> 0 mg/m3
  // 1023 -> 25 mg/m3
  // =================================================

  int thresholdValue = map(
    potValue,
    0,
    1023,
    0,
    25
  );

  dustThreshold = thresholdValue;
}

// =====================================================
// WARNING LED CONTROL
// =====================================================

void updateWarningLED(float dustDensity)
{
  unsigned long now = millis();

  // =================================================
  // WARNING CURRENTLY OFF
  // =================================================

  if (warningLEDState == false)
  {
    if (dustDensity > dustThreshold)
    {
      if (warningHighStart == 0)
      {
        warningHighStart = now;
      }

      warningLowStart = 0;

      // Dust above threshold for 2 seconds
      if (now - warningHighStart >= WARNING_ON_TIME)
      {
        warningLEDState = true;

        warningHighStart = 0;

        // Active LOW
        digitalWrite(WARNING_LED_PIN, LOW);

        Serial.println();
        Serial.println(">>> WARNING LED: ON");
      }
    }
    else
    {
      warningHighStart = 0;
    }
  }

  // =================================================
  // WARNING CURRENTLY ON
  // =================================================

  else
  {
    if (dustDensity <= dustThreshold)
    {
      if (warningLowStart == 0)
      {
        warningLowStart = now;
      }

      warningHighStart = 0;

      // Dust below threshold for 8 seconds
      if (now - warningLowStart >= WARNING_OFF_TIME)
      {
        warningLEDState = false;

        warningLowStart = 0;

        // Active LOW
        digitalWrite(WARNING_LED_PIN, HIGH);

        Serial.println();
        Serial.println(">>> WARNING LED: OFF");
      }
    }
    else
    {
      warningLowStart = 0;
    }
  }
}

// =====================================================
// UPDATE LCD
// =====================================================

void updateLCD(float dustDensity)
{
  // =================================================
  // LINE 1 - DUST VALUE
  // =================================================

  lcd.setCursor(0, 0);

  lcd.print("Dust:");

  lcd.print(dustDensity, 2);

  lcd.print(" mg/m3");

  // Clear remaining characters
  lcd.print(" ");

  // =================================================
  // LINE 2 - STATUS
  // =================================================

  lcd.setCursor(0, 1);

    lcd.print("Th:");

    lcd.print(dustThreshold, 2);

    lcd.print(" mg/m3");

  // Clear unused characters
  lcd.print("   ");
}

// =====================================================
// SERIAL STATUS
// =====================================================

void printStatus(
  int adcValue,
  float dustDensity
)
{
  float voltage = adcValue * (5.0 / 1023.0);

  int potValue = analogRead(POT_PIN);

  // =================================================
  // ADC
  // =================================================

  Serial.print("ADC = ");
  Serial.print(adcValue);

  // =================================================
  // POTENTIOMETER
  // =================================================

  Serial.print(" | Pot = ");
  Serial.print(potValue);

  // =================================================
  // THRESHOLD
  // =================================================

  Serial.print(" | Threshold = ");
  Serial.print(dustThreshold, 2);
  Serial.print(" mg/m3");

  // =================================================
  // VOLTAGE
  // =================================================

  Serial.print(" | Voltage = ");
  Serial.print(voltage, 3);
  Serial.print(" V");

  // =================================================
  // DUST
  // =================================================

  Serial.print(" | Dust = ");
  Serial.print(dustDensity, 2);
  Serial.print(" mg/m3");

  // =================================================
  // WARNING
  // =================================================

  Serial.print(" | Warning = ");

  if (warningLEDState == true)
  {
    Serial.print("ON");
  }
  else
  {
    Serial.print("OFF");
  }

  // =================================================
  // BUTTON
  // =================================================

  Serial.print(" | Button = ");

  if (digitalRead(PUSH_BUTTON_PIN) == HIGH)
  {
    Serial.print("HIGH");
  }
  else
  {
    Serial.print("LOW");
  }

  // =================================================
  // LEFT MOTOR
  // =================================================

  Serial.print(" | Left Motor = ");

  if (digitalRead(LEFT_MOTOR_PIN) == HIGH)
  {
    Serial.print("ON");
  }
  else
  {
    Serial.print("OFF");
  }

  // =================================================
  // RIGHT MOTOR
  // =================================================

  Serial.print(" | Right Motor = ");

  if (digitalRead(RIGHT_MOTOR_PIN) == HIGH)
  {
    Serial.println("ON");
  }
  else
  {
    Serial.println("OFF");
  }
}

// =====================================================
// MOTOR CONTROL
// =====================================================

void updateMotors()
{
  unsigned long now = millis();

  unsigned long elapsed = now - motorCycleStart;

  // =================================================
  // START NEW 12-HOUR MOTOR CYCLE
  // =================================================

  if (elapsed >= MOTOR_CYCLE_TIME)
  {
    // Restart timer
    motorCycleStart = now;

    // Start both motors
    leftMotorState = true;
    rightMotorState = true;

    Serial.println();
    Serial.println("======================================");
    Serial.println(">>> MOTOR CYCLE START");
    Serial.println(">>> LEFT MOTOR  : ON");
    Serial.println(">>> RIGHT MOTOR : ON");
    Serial.println("======================================");
  }

  // =================================================
  // AUTOMATIC LEFT MOTOR OFF
  // =================================================

  if (leftMotorState == true)
  {
    if (now - motorCycleStart >= LEFT_MOTOR_ON_TIME)
    {
      leftMotorState = false;

      Serial.println(">>> AUTO LEFT MOTOR : OFF");
    }
  }

  // =================================================
  // AUTOMATIC RIGHT MOTOR OFF
  // =================================================

  if (rightMotorState == true)
  {
    if (now - motorCycleStart >= RIGHT_MOTOR_ON_TIME)
    {
      rightMotorState = false;

      Serial.println(">>> AUTO RIGHT MOTOR : OFF");
    }
  }

  // =================================================
  // LEFT MOTOR OUTPUT
  // =================================================

  int buttonState = digitalRead(PUSH_BUTTON_PIN);

  if (buttonState == HIGH)
  {
    // Button HIGH = LEFT MOTOR ON
    digitalWrite(LEFT_MOTOR_PIN, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, HIGH);
  }
  else
  {
    // Button LOW = automatic control

    if (leftMotorState == true)
    {
      digitalWrite(LEFT_MOTOR_PIN, HIGH);
      digitalWrite(LEFT_MOTOR_PIN2, LOW);
    }
    else
    {
      digitalWrite(LEFT_MOTOR_PIN, LOW);
      digitalWrite(LEFT_MOTOR_PIN2, LOW);
    }
  }

  // =================================================
  // RIGHT MOTOR OUTPUT
  // =================================================

  if (rightMotorState == true)
  {
    digitalWrite(RIGHT_MOTOR_PIN, HIGH);
  }
  else
  {
    digitalWrite(RIGHT_MOTOR_PIN, LOW);
  }
}

// =====================================================
// MAIN LOOP
// =====================================================

void loop()
{
  unsigned long now = millis();

  // =================================================
  // SENSOR + POTENTIOMETER + LCD
  // =================================================

  if (now - lastSensorRead >= SENSOR_INTERVAL)
  {
    lastSensorRead = now;

    // -----------------------------------------------
    // READ DUST SENSOR
    // -----------------------------------------------

    int adcValue = readDustSensor();

    // -----------------------------------------------
    // CALCULATE DUST IN 0-25 mg/m3
    // -----------------------------------------------

    float dustDensity = calculateDustDensity(adcValue);

    // -----------------------------------------------
    // READ POTENTIOMETER
    // -----------------------------------------------

    updateThreshold();

    // -----------------------------------------------
    // UPDATE WARNING
    // -----------------------------------------------

    updateWarningLED(dustDensity);

    // -----------------------------------------------
    // UPDATE LCD
    // -----------------------------------------------

    updateLCD(dustDensity);

    // -----------------------------------------------
    // SERIAL MONITOR
    // -----------------------------------------------

    printStatus(
      adcValue,
      dustDensity
    );
  }

  // =================================================
  // MOTOR CONTROL
  // =================================================

  updateMotors();
}
