set terminal pngcairo size 500, 300 enhanced font "arial,10"
#set fontscale 1.0
set output 'Prob1_b.png'
# set title 'Runge Function (10th order)'
set title 'Runge Function (20th order)'
set xlabel 'x'
set ylabel 'y'
set xrange [-1:1]
set yrange [-0.5:2]
plot 'data.dat' using 1:2 title 'Runge function - y(x)' with lines ls 6 lc 7, \
     'data.dat' using 1:3 title 'Lagrange interpolation - P(x)' with lines ls 6 lc 8
