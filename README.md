# PushStart

### Github setup
#### Cloning this repo
See [link](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository#cloning-a-repository-using-the-command-line) above.

#### Check out a new branch
``` $ git checkout branchName ```

#### Keep your branch up to date
``` $ git status```
This command tells you if your remote workspace is up to date with the online repository. If you had updates to make use:
``` $ git pull```

#### Saving your work
In order to save and push your commits:
```
$ git add .  // add all changes (you can select the changes you want to make as well)
$ git commit -m 'some commit message'

```
#### (if first time using branch) Connect local branch to remote branch, then push:
``` $ git push --set-upstream origin branchName ```

#### (if local and remote branch are connected) Push changes:
``` $ git push ```

#### Create pull request on Github from branch into master:
Ask other team members to review and merge code

#### Merge conflicts
When saving your work into a shared repository, you might have two people trying to update the same branch at the same time. See [link](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/resolving-a-merge-conflict-on-github) above to resolve this issue. 