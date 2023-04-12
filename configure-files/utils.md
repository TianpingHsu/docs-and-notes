
## archlinux adjust volumes
alsamixer

## makepkg

## pacman
> sudo pacman -Rs $(pacman -Qdtq) 
> sudo rm /var/lib/pacman/db.lck


## rsync
* fetch file from remote host to current directory
> rsync -r huaizhi@192.168.1.102:/home/huaizhi/README.md .  

* transfer files to remote host
> rsync -a ./hello.txt h@12.12.12.12:~


## git command
useful git commands  
* merge some commit to current branch
> git cherry-pick <some-commit-hash>  

* create new branch based on a specific commit
> git checkout -b <new-branch-name> <specific-commit-hash>  

* Hard reset of a single file
> git checkout HEAD -- my-file.txt
or 
> git checkout @ -- myfile.ext  # @ is short for HEAD
or
> git checkout upstream/master -- myfile.txt

* undo `git add`
> git reset <file>
or 
> git reset 
or 
> git rm --cached <file>

## wireshark
> (((ip.src == 172.25.18.175 && rtp) && !(rtp.p_type == 9)) && (rtp.p_type == 109)) && !(ip.dst == 172.25.18.175)

## tcpdump
> tcpdump host 172.25.18.175 -w hello.cap
