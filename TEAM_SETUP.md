# Team Setup & Collaboration Guide

## For Non-Technical Team Members

Don't worry if you're not technical! This guide will help you collaborate on this project easily.

---

## Option 1: Use GitHub (Recommended)

### What is GitHub?
- A website where we store all project files
- Everyone can view files online (no software needed!)
- You can add files through the website
- Free for our use

### Setup Steps (One-time, 15 minutes)

#### Step 1: Create GitHub Account
1. Go to https://github.com
2. Click "Sign Up"
3. Choose a username and password
4. Verify your email

#### Step 2: Get Access to Project
Your project admin will:
1. Push the project to GitHub
2. Invite you as a collaborator
3. Send you the link

#### Step 3: Access the Project
1. Click the link your admin sends
2. You'll see all files and folders online
3. You can read any file by clicking it
4. **That's it!**

### How to Add Files (Easy Way)

1. **Open the project on GitHub**
2. **Navigate to the folder** where you want to add files (e.g., `08_Assets/Photos/Workshop_Photos/`)
3. **Click "Add file" → "Upload files"**
4. **Drag and drop your photos or documents**
5. **Click "Commit changes"**

**Done!** Everyone can now see your files.

### How to Edit a Document

1. **Find the file** on GitHub (click through folders)
2. **Click the file** to open it
3. **Click the pencil icon** (✏️) at top right
4. **Make your edits**
5. **Scroll down and click "Commit changes"**

**That's it!** No software installation needed.

---

## Option 2: Use Notion (Very User-Friendly)

### What is Notion?
- Like Google Docs but better organized
- Very easy to use (no technical knowledge needed)
- Everyone can edit in real-time
- Can embed photos and videos easily

### Setup Steps (15 minutes)

1. Project admin creates a Notion workspace
2. Admin copies all documents to Notion
3. Admin invites team members
4. Everyone gets link to access

### Advantages
- ✅ Very visual and easy to use
- ✅ Can comment and discuss
- ✅ Mobile app available
- ✅ Can organize tasks and track progress
- ✅ Non-technical people love it!

**Downside**: Files need to be copied from local folders to Notion

---

## Option 3: Use Google Drive (Simplest)

### What is Google Drive?
- Like online folders - same as your computer
- Everyone with Google account can use it
- Very familiar interface

### Setup Steps (10 minutes)

1. Project admin uploads entire folder to Google Drive
2. Admin shares folder with team (with edit access)
3. Everyone can:
   - View files in browser
   - Edit directly
   - Upload photos
   - Add comments

### Advantages
- ✅ Everyone knows how to use it
- ✅ No learning curve
- ✅ Edit documents like Google Docs
- ✅ Easy to upload photos

**Downside**: Not as good for tracking versions

---

## Option 4: Use GitBook (Beautiful Documentation Website)

### What is GitBook?
- Creates a beautiful website from your markdown files
- Easy to read and navigate
- Can sync with GitHub automatically

### Setup Steps (Admin only)

1. Connect GitHub repository to GitBook
2. GitBook creates a website automatically
3. Team members just visit the website to read
4. Updates on GitHub automatically show on website

### Advantages
- ✅ Beautiful, professional-looking website
- ✅ Very easy to read and navigate
- ✅ Search functionality
- ✅ Can be public or private

**Best for**: Sharing with stakeholders or making documentation look professional

---

## Our Recommendation

### For Small Teams (2-5 people)
**→ Use Google Drive**
- Easiest to start
- Everyone knows how to use it
- Can migrate later if needed

### For Technical Teams
**→ Use GitHub**
- Best for version control
- Professional workflow
- Free

### For Mixed Teams (Technical + Non-Technical)
**→ Use GitHub + GitBook**
- Technical people use GitHub
- Non-technical people read on GitBook website
- Best of both worlds

### For Maximum Ease of Use
**→ Use Notion**
- Most user-friendly
- Great for collaboration
- Everyone can contribute easily

---

## What Your Project Admin Needs to Do

### If Using GitHub:

```bash
# Navigate to project folder
cd /Users/rhuria/Project_CleanLoom

# Initialize git (if not done)
git init

# Add all files
git add .

# Create first commit
git commit -m "Initial project setup"

# Create repository on GitHub (do this on GitHub.com first)
# Then connect and push:
git remote add origin https://github.com/YourUsername/CleanLoom.git
git branch -M main
git push -u origin main
```

### If Using Google Drive:
1. Upload `Project_CleanLoom` folder to Google Drive
2. Right-click folder → Share
3. Add team members' emails
4. Give "Editor" access
5. Send link to team

### If Using Notion:
1. Create new workspace in Notion
2. Copy/paste markdown files as Notion pages
3. Upload photos to respective pages
4. Invite team members
5. Share workspace link

---

## For Team Members: Quick Access

Once set up, you'll get a link like:

**GitHub**: `https://github.com/username/CleanLoom`  
**Google Drive**: `https://drive.google.com/drive/folders/...`  
**Notion**: `https://notion.so/workspace/CleanLoom`  
**GitBook**: `https://cleanloom.gitbook.io/`

**Bookmark this link!** This is where you'll access everything.

---

## Tips for Non-Technical Team Members

### If Using GitHub
- You don't need to install anything
- Just use the website
- Click "Upload files" to add photos
- Click pencil icon to edit documents

### If Files Look Weird (All Text)
- These are "Markdown" files (.md)
- GitHub displays them nicely - just click to view
- When you edit, you're editing text that becomes formatted

### Don't Worry About "Git" Stuff
- You don't need to learn Git commands
- Just use the website buttons
- The admin can help if you get stuck

---

## Mobile Access

### GitHub Mobile App
- Available for iOS and Android
- Can view all files
- Can take photos and upload directly

### Notion Mobile App
- Very easy to use
- Can add notes and photos from phone
- Syncs automatically

### Google Drive App
- Everyone already has it
- Easy photo uploads
- Works offline

---

## Questions?

**"How do I add my workshop photos?"**
→ Navigate to `08_Assets/Photos/Workshop_Photos/` and click "Upload files"

**"How do I share my interview notes?"**
→ Create a new file in `02_Problem_Research/Interviews/` or upload a document

**"Can I work offline?"**
→ With Google Drive or GitHub Desktop (app), yes. Pure web-based, no.

**"What if I make a mistake?"**
→ Don't worry! Everything is backed up. Your admin can restore previous versions.

**"I'm not technical, which option should I use?"**
→ Google Drive or Notion - both are very user-friendly!

---

## Next Steps

1. **Admin**: Choose a platform (see recommendations above)
2. **Admin**: Set up the project on that platform
3. **Admin**: Invite all team members
4. **Team**: Access the link and bookmark it
5. **Everyone**: Start collaborating!

---

**Remember: The goal is to work together easily, not to be perfect with technology!**

