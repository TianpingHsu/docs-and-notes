# Usage of grep

## search pattern with ignoring certain files
> grep target-pattern -Irn --exclude="*.{dtf,obj}" .
* `-I`  -- ignore binary files  
check [here](https://stackoverflow.com/questions/221921/use-grep-exclude-include-syntax-to-not-grep-through-certain-files) for more information.  


## grep for "patternA" and exclude "patternB"
> grep "patternA" -rn . | grep -v "patternB"
* `-v` -- invert-match
check:  
* https://www.tutorialspoint.com/exclude-multiple-patterns-with-grep-on-linux
* https://stackoverflow.com/questions/4538253/how-can-i-exclude-one-word-with-grep
