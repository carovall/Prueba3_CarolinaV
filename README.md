# Copiar y pegar comandos en terminal para ejecutar:
    make
# 
    make run
# 
# Se muestra por terminal el factor de empaquetamiento y la evolución de los pasos de la simulación. Se generan 1 archivo ("equilibrio.dat") con los valores de posicion y velocidad
# de cada partícula en el último paso, y un archivo ("magnitud.dat") que contiene la magnitud de la velocidad de cada partícula en el último paso. Con estos se contruyen los histogramas
# de velocidad en X, velocidad en Y, velocidad en Z y magnitud ed velocidad (vel_x.png, vel_y.png, vel_z.png y magnitud.png, respectivamente).
# 
# Resultados:
# El código contempla en la inicialización de las velocidades que sus componentes sigan una distribución gaussiana con media mu=0 y desviacion estandar= T, 
# en concordancia se observa en las respectivas gráficas que los componentes de la velocidad en cada eje se distribuyen normalmente, con media cero.
# Luego, de acuerdo a lo esperado teóricamente para la suma del cuadrado de 3 variables aleatorias independientes con distribución normal estándar, se observa que la
# magnitud de la velocidad sigue una distribucion de Maxwell-Boltzmann (asimétrica, descentralizada, con desplazamiento hacia a la izquierda en comparación con distribución Normal).
