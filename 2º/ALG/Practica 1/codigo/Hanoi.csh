#!/bin/csh
@ inicio = 1
@ fin = 100
@ incremento = 1
set ejecutable = hanoi_nano
set salida = tiempos_hanoi.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
