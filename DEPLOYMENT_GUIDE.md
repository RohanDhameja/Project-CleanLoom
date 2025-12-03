# 🚀 Deployment Guide: Getting CleanLoom Online

## Overview

This guide will help you:
1. ✅ Push your project to GitHub (version control + backup)
2. ✅ Deploy as a website (GitHub Pages - free and automatic)
3. ✅ Allow team to view and update directly online

---

## Step 1: Create GitHub Account (if needed)

1. Go to https://github.com
2. Sign up (free account is perfect)
3. Verify your email

---

## Step 2: Create a New Repository on GitHub

### Option A: Using GitHub Website (Easier)

1. **Go to GitHub** and log in
2. **Click the "+" icon** in top right → "New repository"
3. **Fill in details**:
   - Repository name: `Project-CleanLoom` or `cleanloom`
   - Description: `Low-cost lint reduction solution for small weaving workshops`
   - Privacy: 
     - ✅ **Public** (recommended - free GitHub Pages)
     - Or **Private** (if you want to keep it internal for now)
   - ❌ **DO NOT** check "Add README" (we already have one)
   - ❌ **DO NOT** add .gitignore (we already have one)
4. **Click "Create repository"**

### Option B: Using GitHub CLI (Advanced)

```bash
# Install GitHub CLI first (if not installed)
# Mac: brew install gh
# Then:
gh repo create Project-CleanLoom --public --source=. --remote=origin --push
```

---

## Step 3: Connect Your Local Project to GitHub

After creating the repository on GitHub, you'll see instructions. Use these commands:

```bash
cd /Users/rhuria/Project_CleanLoom

# Add GitHub as remote (replace USERNAME with your GitHub username)
git remote add origin https://github.com/USERNAME/Project-CleanLoom.git

# Push to GitHub
git branch -M main
git push -u origin main
```

**Your project is now on GitHub!** 🎉

---

## Step 4: Enable GitHub Pages (Free Website)

### Method 1: Through GitHub Settings (Easiest)

1. **Go to your repository** on GitHub
2. **Click "Settings"** tab (at the top)
3. **Scroll to "Pages"** in left sidebar (or click "Pages")
4. **Under "Source"**:
   - Branch: Select `main`
   - Folder: Select `/ (root)`
5. **Click "Save"**
6. **Wait 1-2 minutes** for deployment
7. **Your website URL** will appear: `https://USERNAME.github.io/Project-CleanLoom/`

### Method 2: Using Actions (Automatic - Already Configured)

GitHub will automatically deploy your `index.html` file!

---

## Step 5: Access Your Website

After 1-2 minutes, visit:

```
https://YOUR-USERNAME.github.io/Project-CleanLoom/
```

**That's it!** Your team can now access the project through a beautiful web interface.

---

## 📱 Sharing with Your Team

### Share These Links:

**Main Website:**
```
https://YOUR-USERNAME.github.io/Project-CleanLoom/
```

**Start Here Page:**
```
https://YOUR-USERNAME.github.io/Project-CleanLoom/START_HERE.md
```

**GitHub Repository (to edit):**
```
https://github.com/YOUR-USERNAME/Project-CleanLoom
```

---

## 👥 Giving Team Members Access

### If Repository is Private:

1. Go to repository **Settings** → **Collaborators**
2. Click **"Add people"**
3. Enter their GitHub username or email
4. They'll get an invitation email

### If Repository is Public:

Anyone can view. For editing:
- Add them as collaborators (same as above)
- Or they can "fork" and submit pull requests

---

## ✏️ How Team Can Edit Documents

### Method 1: Edit on GitHub (Easiest for Non-Technical)

1. **Navigate to the file** on GitHub
2. **Click the pencil icon** (Edit this file)
3. **Make changes**
4. **Scroll down** to "Commit changes"
5. **Add description** of what you changed
6. **Click "Commit changes"**

✨ Website updates automatically in 1-2 minutes!

### Method 2: Edit Locally & Push (For Technical Users)

```bash
# Make changes to files locally
# Then:
git add -A
git commit -m "Description of changes"
git push
```

### Method 3: Use GitHub Desktop (User-Friendly App)

1. Download **GitHub Desktop**: https://desktop.github.com/
2. Clone your repository
3. Edit files normally
4. Use app to commit and push

---

## 📖 Reading Documents on the Website

GitHub automatically renders Markdown files beautifully:

- Click any `.md` file → Formatted view
- Images embedded in markdown will show
- Links between documents work automatically

**Your `index.html` provides a beautiful homepage with easy navigation!**

---

## 🔄 Workflow for Team Updates

### Daily Work:

1. **View** → Visit the website
2. **Edit** → Go to GitHub, click file, click pencil icon
3. **Save** → Commit changes
4. **Automatic** → Website updates in 1-2 minutes

### Weekly Workflow:

1. **Monday**: Review current status on website
2. **During week**: Team members add observations, photos, notes
3. **Friday**: Update weekly checklist
4. **Automatic backup**: Everything is saved on GitHub

---

## 📸 Adding Photos/Assets

### Method 1: Upload via GitHub

1. Navigate to appropriate folder (e.g., `08_Assets/Photos/Workshop_Photos/`)
2. Click **"Add file"** → **"Upload files"**
3. Drag and drop photos
4. Commit changes

### Method 2: Use Git LFS for Large Files (Advanced)

If photos are very large:

```bash
# Install Git LFS
brew install git-lfs  # Mac
# Or download from: https://git-lfs.github.com/

# Initialize
git lfs install
git lfs track "*.jpg" "*.png" "*.mp4"
git add .gitattributes
git commit -m "Configure Git LFS"
git push
```

---

## 🔒 Security & Privacy Considerations

### What's Public (if using public repo):
- All documents
- All photos you upload
- Team member GitHub usernames
- Commit history

### What to Keep Private:
- Don't commit sensitive workshop owner information
- Blur faces in photos if privacy requested
- Don't commit personal contact information
- Use private repo if confidentiality is important

### Making Repository Private Later:
- Settings → Danger Zone → Change visibility → Make private

---

## 💡 Pro Tips

### For Your Team:

1. **Bookmark the website** - Main access point for everyone
2. **Learn basic Markdown** - 5 minutes, super easy: https://guides.github.com/features/mastering-markdown/
3. **Start small** - Edit a few words, see it work, build confidence
4. **Use "Preview" tab** when editing to see formatting
5. **Don't worry about breaking things** - Every change is saved, can be undone

### For You (Admin):

1. **Watch the repository** - Get email notifications of changes
2. **Review pull requests** if team submits them
3. **Weekly backup** - GitHub IS your backup, but download occasionally
4. **Mobile access** - GitHub mobile app works great for quick views

---

## 🆘 Troubleshooting

### "Page not found" when visiting website
- Wait 2-3 minutes after enabling Pages
- Check Settings → Pages shows green success message
- Verify URL is correct (check for typos)

### "Changes not showing on website"
- Wait 1-2 minutes for GitHub Actions to rebuild
- Hard refresh: Ctrl+Shift+R (Windows) or Cmd+Shift+R (Mac)
- Check Actions tab for build status

### "Can't push to GitHub"
- Make sure you're added as collaborator
- Check you're logged into correct account
- Try personal access token instead of password

### "Files too large"
- Use Git LFS for files >50MB
- Or upload photos to Google Drive and link
- Compress images before uploading

---

## 📞 Need Help?

### Resources:
- **GitHub Docs**: https://docs.github.com/
- **GitHub Pages Guide**: https://pages.github.com/
- **Markdown Guide**: https://www.markdownguide.org/
- **GitHub Community**: https://github.community/

### Contact:
- Ask in your team chat
- GitHub has great support docs
- YouTube has tons of tutorials: "GitHub Pages tutorial"

---

## ✅ Quick Checklist

After following this guide, you should have:

- [x] Git repository initialized locally
- [ ] GitHub account created
- [ ] Repository created on GitHub
- [ ] Local project pushed to GitHub
- [ ] GitHub Pages enabled
- [ ] Website accessible at username.github.io/Project-CleanLoom
- [ ] Team members added as collaborators
- [ ] Website URL shared with team

---

## 🎉 Success!

Your team now has:
- ✅ **Beautiful website** to view the project
- ✅ **Easy editing** through GitHub's web interface
- ✅ **Automatic backups** - everything saved in the cloud
- ✅ **Version control** - see who changed what and when
- ✅ **Mobile access** - view and edit from phones
- ✅ **Free hosting** - no costs, no servers to manage

**Now your team can focus on solving the problem, not managing documents!**

---

*Last Updated: December 3, 2025*
