set terminal pngcairo enhanced size 640, 640
#grafico 1: magnitud velocidad
set output 'magnitud.png'

set style data histogram
set style fill solid
set title "Distribucion Magnitud Velocidad"
set xlabel "velocidad"
set ylabel "cuentas"
binwidth=0.1
bin(x,width) = width*floor(x/width)
plot 'magnitud.dat' using (bin($1,binwidth)):(1.0) smooth freq with boxes notitle

# grafico 2: velocidad en x
reset
set output 'vel_x.png'

set style data histogram
set style fill solid
set title "Distribucion Velocidad en X"
set xlabel "velocidad"
set ylabel "cuentas"
set xrange [-4:4]
binwidth=0.1
bin(x,width) = width*floor(x/width)
plot 'equilibrio.dat' using (bin($5,binwidth)):(1.0) smooth freq with boxes notitle

# grafico 3: velocidad en y
reset
set output 'vel_y.png'

set style data histogram
set style fill solid
set title "Distribucion Velocidad en Y"
set xlabel "velocidad"
set ylabel "cuentas"
binwidth=0.1
bin(x,width) = width*floor(x/width)
plot 'equilibrio.dat' using (bin($6,binwidth)):(1.0) smooth freq with boxes notitle

# grafico 4: velocidad en z
reset
set output 'vel_z.png'

set style data histogram
set style fill solid
set title "Distribucion Velocidad en Z"
set xlabel "velocidad"
set ylabel "cuentas"
binwidth=0.1
bin(x,width) = width*floor(x/width)
plot 'equilibrio.dat' using (bin($7,binwidth)):(1.0) smooth freq with boxes notitle
