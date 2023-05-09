
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


## wireshark
> (((ip.src == 172.25.18.175 && rtp) && !(rtp.p_type == 9)) && (rtp.p_type == 109)) && !(ip.dst == 172.25.18.175)

## tcpdump
> tcpdump host 172.25.18.175 -w hello.cap
