# git branch >> 'develop'
cd src/ai_help

git checkout -b key-branch
cp main.key main-2.key
git add main-2.key && git commit -m "add main-2.key"

git checkout -b feature/3-key    
cp main.key main-3.key

git checkout key-branch
git merge feature/3-key

git checkout develop
git checkout -b release/1.0

git checkout develop
git merge key-branch

git checkout release/1.0
git merge develop
