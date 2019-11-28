#!/bin/csh
@ inicio = 2
@ fin = 700
@ incremento = 5
set ejecutable = multiplicacion
set salida = tiempos.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
