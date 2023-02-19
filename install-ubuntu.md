# Install Ubuntu Operating System


## Download iso file
you can download Ubuntu iso file from [here](https://ubuntu.com/download/desktop#download)

## Create a bootable USB Flash Drive
first you should insert your USB Flash Drive into you Linux/Unix PC and use `lsblk` or `df` to check which device is your drive.  
then use Linux command `dd` (say `/dev/sdc` is your USB Flash Drive):  
> sudo dd if=artful-desktop-amd64.iso of=/dev/sdc bs=1M status=progress

## Boot from your bootable USB Flash Drive
Press `F12` or `F2`, select boot from USB Flash Drive.  

