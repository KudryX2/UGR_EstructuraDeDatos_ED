#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = peor
set salida = peor.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
