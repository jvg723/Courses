set terminal pngcairo size 500, 300 enhanced font "arial,10"
#set fontscale 1.0
#set output 'Prob3_a_098.png'
#set output 'Prob3_a_09.png'
#set output 'Prob3_=b_098.png'
set output 'Prob3_=b_09.png'
#set title 'a=0.98'
#set title 'Part (b) - a=0.98'
set title 'Part (b) - a=0.9'
set xlabel 'x'
set ylabel 'phi''
set xrange [-1:1]
set yrange [-8:8]
plot 'data.dat' using 1:2 title 'Exact Derivative' with lines ls 6 lc 7, \
     'data.dat' using 3:4 title 'Central Difference' with lines ls 6 lc 8, \
     'data.dat' using 3:5 title 'Coordinate Transform' with lines ls 6 lc 9
