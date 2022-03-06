#!/bin/bash
printf "#Architecture: "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
free --mega | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3 / $2 * 100.0}'

printf "#Disk Usage: "
df -a -BM | grep /dev/mapper | awk '{sum1+=$3;sum2+=$4}END {printf "%d/%dGB (%d%%)\n", sum1, sum2 / 1024, sum1 / sum2 * 100}'

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.1f%%\n", 100.0 - $13}'

printf "#Last boot: "
who -b | awk '{printf "%s %s\n", $3, $4}'

printf "#LVM use: "
lsblk | grep lvm | wc -l | awk '{printf "%s\n", ($1 > 0 ? "yes" : "no")}'

printf "#Connexions TCP : "
ss | grep -i tcp | wc -l | awk '{printf "%d ESTABLISHED\n", $1}'

printf "#User log: "
who | wc -l

printf "#Network: IP "
hostname -I | awk '{printf "%s ", $1}'
ip link show | grep -w 'ether' | head -n 1 | awk '{printf "(%s)\n", $2}'

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | awk '{printf "%d cmd\n", $1}'
