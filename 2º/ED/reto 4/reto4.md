##Reto 4: Árboles
#####Por: Rubén Mogica Garrido y Arturo Cortés Sánchez

####Idea:
Nuestra idea está pensada para almacenar un árbol binario cuyos nodos contienen un numero del 0 al 9. Para guardar en disco un árbol de estas características hemos ideado el siguiente formato:

 * La primera linea del archivo consta del recorrido preorden del árbol.
 
 * La segunda consiste en un array de bits que indican si un nodo tiene hijos según el siguiente esquema: un `0` significa que el nodo tiene dos hijos, un `10` que tiene un solo hijo y un `11` significa que no tiene hijos.

Así este árbol `n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x` se representaría de la siguiente forma:
```
12458367
0011101101111
```
Pero los bits no se guardan directamente como caracteres `0` o `1`, son reunidos en grupos de 8 y guardados en un carácter. Por consiguiente el archivo del árbol anterior quedaría así.
```
12458367
;x
```
En base a esto calculamos que nuestro formato puede almacenar un árbol de `n` nodos en aproximadamente `1,2n` caracteres.

####Implementación:

Para la implementación nos hemos basado en el código del árbol sin iteradores que había en prado. 

Primero hemos diseñado una función `comprimir()` la cual recibe un string que contiene un árbol usando el formato que se usa en el código base y devuelve un string que contiene el árbol con nuestro formato. 

Después hemos diseñado una función `descomprimir()`. Recibe dos strings, uno con el recorrido preorden del árbol y otro string con el array de bits centinelas "compactado" en caracteres y devuelve un string que contiene el árbol usando el formato del código base.

Finalmente hemos definido una función llamada`cin_inverso()` que recibe un string y lo introduce en el `istream`. El propósito de esta función es facilitar la reutilización del código del árbol sin iteradores.

####Uso del programa

Para generar un archivo a partir de un arbol llamamos al programa de la siguiente forma `./reto4 2`y a continuación introducimos un arbol con el siguiente formato por la entrada estándar `n 1 n 2 n 4 x x n 5 x n 8 x x n 3 n 6 x x n 7 x x`. El programa generará un archivo llamado `archivo_arbol` que contiene el árbol almacenado con nuestro formato.
Para leer el archivo generado llamamos al programa de la siguiente forma `./reto4 1 < archivo_arbol`.