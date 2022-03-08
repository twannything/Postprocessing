#!/bin/bash

gcc -o post_process post_process.c ./clock/clock.c ./slow_clock/slow_clock.c ./flag_clock/flag_clock.c ./fast_clock/fast_clock.c ./time_difference/time_diff.c ./sample/interval/interval.c

#./post_process

#read -p "Enter the file name: " file
#mkdir $file
#mv $file*.bin ./$file/
#rm temp.txt
