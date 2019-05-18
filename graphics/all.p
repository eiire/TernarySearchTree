#!/usr/bin/gnuplot -persist

set terminal png size 1000,600 linewidth 4 font "Verdana,14"
set termoption dash
set output "search.png"

set logscale
set grid x y
set key left top
unset log
set xlabel "Количество слов"
set ylabel "Время в секундах"
set xrange [0 : 25000]
set yrange [0 : 0.04]

plot "v1.txt" using 1:2 with linespoints linecolor 6 title "Отсортированные", "v2.txt" using 1:2 with linespoints linecolor 4 title "Неотсортированные"

