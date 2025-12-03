# Project Folder Structure

## Complete Directory Tree

```
Project_CleanLoom/
│
├── README.md                              # Start here - Project overview
├── PROJECT_GUIDE.md                       # How to use this project structure
├── GETTING_STARTED.md                     # Quick start guide for new members
├── FOLDER_STRUCTURE.md                    # This file - directory reference
├── .gitignore                             # Git ignore patterns
│
├── 01_Project_Plan/                       # Planning & tracking
│   ├── PROJECT_ROADMAP.md                 # Detailed timeline (26 week plan)
│   ├── WEEKLY_CHECKLIST.md                # Weekly progress tracker
│   └── Weekly_Checklists/                 # Archive of completed checklists
│
├── 02_Problem_Research/                   # Problem understanding
│   ├── PROBLEM_STATEMENT.md               # Comprehensive problem definition
│   ├── INITIAL_EVIDENCE.md                # Your evidence (photos, observations)
│   ├── INTERVIEW_TEMPLATE.md              # For stakeholder interviews
│   ├── FIELD_OBSERVATION_TEMPLATE.md      # For workshop visits
│   ├── Interviews/                        # Completed interview forms
│   └── Observations/                      # Completed observation forms
│
├── 03_Solution_Ideation/                  # Brainstorming & concept development
│   ├── IDEATION_FRAMEWORK.md              # How to generate solution ideas
│   ├── EVALUATION_FRAMEWORK.md            # How to evaluate and select concepts
│   ├── Ideas/                             # All brainstormed concepts
│   └── Selected_Concepts/                 # Top concepts moving to prototyping
│
├── 04_Prototypes/                         # Prototype builds
│   ├── PROTOTYPE_DOCUMENTATION_TEMPLATE.md
│   └── [PrototypeName]/                   # One folder per prototype
│       ├── Documentation/                 # Build docs, BOMs, instructions
│       ├── Photos/                        # Build process photos
│       └── Test_Results/                  # Performance data
│
├── 05_Testing/                            # Field testing & validation
│   ├── FIELD_TEST_PROTOCOL.md             # Standardized testing process
│   └── [PrototypeName]/                   # Test results per prototype
│       ├── Site_1/                        # Results from each test location
│       ├── Site_2/
│       └── Summary_Report.md
│
├── 06_Documentation/                      # End-user documentation
│   ├── USER_MANUAL_TEMPLATE.md            # Template for user manuals
│   └── [ProductName]/                     # Final documentation per product
│       ├── User_Manual.md
│       ├── Installation_Guide.md
│       ├── Maintenance_Guide.md
│       └── Troubleshooting_Guide.md
│
├── 07_Business/                           # Business planning & analysis
│   ├── COST_ANALYSIS_TEMPLATE.md          # Financial analysis framework
│   └── [PrototypeName]/                   # Cost analysis per solution
│       ├── Cost_Analysis.md
│       ├── ROI_Calculation.md
│       └── Pricing_Strategy.md
│
└── 08_Assets/                             # Media & visual assets
    ├── README.md                          # Asset management guide
    ├── Photos/                            # All project photos
    │   ├── Workshop_Photos/               # Workshop documentation
    │   ├── Prototype_Photos/              # Prototype builds & tests
    │   ├── Before_After/                  # Impact comparison photos
    │   └── Team_Photos/                   # Team & stakeholder photos
    ├── Diagrams/                          # Technical drawings & infographics
    │   ├── Technical_Drawings/
    │   ├── Infographics/
    │   └── Flow_Diagrams/
    ├── Videos/                            # Video documentation
    │   ├── Workshop_Videos/
    │   ├── Prototype_Demos/
    │   └── Training_Videos/
    ├── Presentations/                     # Slide decks & pitch materials
    │   └── Pitch_Decks/
    └── Brand_Assets/                      # Logos & branding
        └── Logos/
```

---

## Folder Purposes - Quick Reference

| Folder | Purpose | Key Files |
|--------|---------|-----------|
| **01_Project_Plan** | Timeline, milestones, tracking | PROJECT_ROADMAP.md, WEEKLY_CHECKLIST.md |
| **02_Problem_Research** | Understanding the problem | PROBLEM_STATEMENT.md, Templates |
| **03_Solution_Ideation** | Generating & selecting ideas | IDEATION_FRAMEWORK.md, EVALUATION_FRAMEWORK.md |
| **04_Prototypes** | Building & documenting prototypes | PROTOTYPE_DOCUMENTATION_TEMPLATE.md |
| **05_Testing** | Field testing & validation | FIELD_TEST_PROTOCOL.md |
| **06_Documentation** | End-user manuals & guides | USER_MANUAL_TEMPLATE.md |
| **07_Business** | Costs, pricing, ROI | COST_ANALYSIS_TEMPLATE.md |
| **08_Assets** | Photos, videos, diagrams | All media files |

---

## Where to Save What?

### Interviews
**Location**: `02_Problem_Research/Interviews/`  
**Format**: `YYYYMMDD_Location_Interviewee.md`

### Field Observations
**Location**: `02_Problem_Research/Observations/`  
**Format**: `YYYYMMDD_Location_Workshop.md`

### Solution Ideas
**Location**: `03_Solution_Ideation/Ideas/`  
**Format**: `IdeaName_v01.md` or sketches

### Prototype Documentation
**Location**: `04_Prototypes/[PrototypeName]/`  
**Files**: Documentation/, Photos/, Test_Results/

### Test Results
**Location**: `05_Testing/[PrototypeName]/Site_#/`  
**Files**: Daily logs, weekly reports, photos

### Photos
**Location**: `08_Assets/Photos/[Category]/`  
**Format**: `YYYYMMDD_Location_Subject_###.jpg`

### Videos
**Location**: `08_Assets/Videos/[Category]/`  
**Format**: `YYYYMMDD_Location_Subject.mp4`

### Diagrams
**Location**: `08_Assets/Diagrams/[Category]/`  
**Format**: `Type_Description_v##.pdf/png`

### Weekly Checklists
**Location**: `01_Project_Plan/Weekly_Checklists/`  
**Format**: `YYYY_Week##_Checklist.md`

---

## File Naming Conventions

### Dates
Always use: `YYYYMMDD` (e.g., 20251203 for Dec 3, 2025)

### Versions
Use: `v01`, `v02`, `v03`, etc.

### Photos
Format: `YYYYMMDD_Location_Subject_###.jpg`
- Example: `20251203_Workshop_A_LoomCloseup_001.jpg`

### Documents
Format: `Title_v##.md` or `Title.md` (if only one version)
- Example: `Solution_A_Evaluation_v02.md`

### Videos
Format: `YYYYMMDD_Location_Subject.mp4`
- Example: `20251210_Workshop_B_Interview.mp4`

---

## Adding New Content

### When creating a new prototype
1. Create folder: `04_Prototypes/[PrototypeName]/`
2. Add subfolders: `Documentation/`, `Photos/`, `Test_Results/`
3. Use PROTOTYPE_DOCUMENTATION_TEMPLATE.md
4. Store photos in prototype's Photos/ folder

### When conducting a test
1. Create folder: `05_Testing/[PrototypeName]/Site_#/`
2. Follow FIELD_TEST_PROTOCOL.md
3. Save daily logs, weekly reports in site folder
4. Copy key photos to `08_Assets/Photos/Before_After/`

### When creating documentation
1. Create folder: `06_Documentation/[ProductName]/`
2. Start with USER_MANUAL_TEMPLATE.md
3. Add supporting documents (installation, maintenance, etc.)
4. Include diagrams from `08_Assets/Diagrams/`

---

## What NOT to Track in Git

The `.gitignore` file excludes:
- OS files (.DS_Store, Thumbs.db)
- Temporary files (*.tmp, ~$*, *.swp)
- Large video files (optional)
- Backup files (*.bak, *_backup.*)
- Personal notes (PERSONAL_NOTES.md, drafts/)
- Sensitive information (*_CONFIDENTIAL.*)

---

## Maintaining Organization

### Daily
- Save files in correct folders
- Use proper naming conventions
- Take photos as you work

### Weekly
- Archive completed weekly checklist
- Review folder organization
- Delete unnecessary files
- Backup to cloud

### Monthly
- Review entire structure
- Archive old versions if needed
- Update this document if structure changes
- Ensure all assets are documented

---

## Navigation Tips

### Finding Something Quickly

**Looking for timeline?**  
→ `01_Project_Plan/PROJECT_ROADMAP.md`

**Need an interview template?**  
→ `02_Problem_Research/INTERVIEW_TEMPLATE.md`

**Want to brainstorm solutions?**  
→ `03_Solution_Ideation/IDEATION_FRAMEWORK.md`

**Building a prototype?**  
→ `04_Prototypes/PROTOTYPE_DOCUMENTATION_TEMPLATE.md`

**Planning a field test?**  
→ `05_Testing/FIELD_TEST_PROTOCOL.md`

**Writing user documentation?**  
→ `06_Documentation/USER_MANUAL_TEMPLATE.md`

**Calculating costs?**  
→ `07_Business/COST_ANALYSIS_TEMPLATE.md`

**Looking for a photo?**  
→ `08_Assets/Photos/[appropriate category]/`

---

## Expanding the Structure

As the project grows, you might add:

- `09_Partnerships/` - For collaborations and MOUs
- `10_Funding/` - Grant applications and funding docs
- `11_Publications/` - Research papers, case studies
- `12_Training/` - Training programs and materials
- `13_Scale/` - Scaling strategy and implementation

**When adding folders, update this document!**

---

## Questions?

- **General navigation**: See PROJECT_GUIDE.md
- **Getting started**: See GETTING_STARTED.md
- **Project timeline**: See 01_Project_Plan/PROJECT_ROADMAP.md
- **Asset management**: See 08_Assets/README.md

---

*This structure is designed to scale with your project from research through implementation*

---

*Last Updated: December 3, 2025*  
*Document Version: 1.0*


