# PushStart 
## To-do
- Use a potentiometer to control the speed of the motor & figure out optimal speed of motor
- **Integrate display:**
  - To guide user on startup (implement LED's as well)
  - To display helpful debugging information during runtime (for now we can display % power or voltage supplied) 
    - For now we can display % power or voltage supplied to motor, ...
    - In the end we would want rate of compressions, depth of compressions (?), remaining battery life   
- Calculate distance traveled using a ultrasonic sensor that is in the kit


## Github Repository Guide
#### Cloning this repo
See [link](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository#cloning-a-repository-using-the-command-line).

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

#### Push changes:
``` $ git push ```

#### Merge conflicts
When saving your work into a shared repository, you might have two people trying to update the same branch at the same time. See [link](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/resolving-a-merge-conflict-on-github) above to resolve this issue. 
