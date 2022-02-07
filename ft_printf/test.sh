#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette
echo -e "\033[32;1m"printf42_mandatorytester"\033[m"
read $a
git clone https://github.com/chronikum/printf42_mandatorytester
make
cd printf42_mandatorytester/
mv main.c tmp
echo "#include <stdio.h>" >> main.c
cat tmp >> main.c
cp ../*.a .
cp ../include/ft_printf.h .
gcc -L./ -lftprintf main.c 2> /dev/null
./a.out
cd ..
echo -e "\033[32;1m"ft_printf_tester"\033[m"
read $a
git clone https://github.com/paulo-santana/ft_printf_tester.git
make bonus
cd ft_printf_tester/
cp ../*.a .
sh test
cd ..
echo -e "\033[32;1m"printfTester"\033[m"
read $a
git clone https://github.com/Tripouille/printfTester.git
cd printfTester/
make a
cd ..
make fclean
rm -rf printf42_mandatorytester/ ft_printf_tester/ printfTester/
echo -e "\033[32;1m"DONE"\033[m"
