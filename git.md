

* create a new branch and switch to it
> git branch <branch_name>
> git checkout <branch_name>
or  
> git checkout -b <branch_name>

* merge some commit to current branch
> git cherry-pick <some-commit-hash>

* create new branch based on a specific commit
> git checkout -b <new-branch-name> <specific-commit-hash>

* delete branch
> git branch -d <local_branch_name>
> git push <remote> --delete <remote_branch_name>

* stash
> git stash list
> git stash show -p stash@{idx}


* get remote url
git config --get remote.origin.url
