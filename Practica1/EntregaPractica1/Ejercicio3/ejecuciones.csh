#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 100
set ejecutable = solucion
set salida = tiempos.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
