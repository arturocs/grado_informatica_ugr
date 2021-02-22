## Reto 5: Tabla Hash
##### Por: Arturo Cortés Sánchez

Para empezar he realizado una versión iterativa de la función `di`, he decidido implementarla así porque simplifica bastante el trabajo con un vector de la stl además de que es mas fácil seguir su funcionamiento.

Luego he implementado una función `comprobar()` para la que dado un `M` imprime todas las parejas de `a` y `c` que generan una secuencia válida.

En el main he llamado a la función `comprobar()` para todos los primos del 1 al 101.

### Conclusiones

Para un `M` primo las parejas `(a, c)` que generan una secuencia válida siempre son de la misma forma:

 * `a` siempre vale 1
 * `c` toma un valor entre 1 y `M-1`

 