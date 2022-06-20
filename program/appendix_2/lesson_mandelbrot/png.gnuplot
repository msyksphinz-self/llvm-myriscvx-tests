set term png size 900, 900
set output "mandelbrot.png"
set grid
set pm3d map
set size square
set palette defined (0 "#000000", 2 "#c00000", 7 "#ffff00", 9 "#ffffff")
splot "data.txt"