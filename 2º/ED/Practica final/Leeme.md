# Práctica Final ED:  Letras
##### Por:  Rubén Mogica Garrido y Arturo Cortés Sánchez

### Introducción: 

En esta práctica hemos desarrollado cuatro clases: 

* Letras: Clase que agrupa los métodos para el funcionamiento del juego.

* Diccionario: Clase que contiene palabras ordenadas de forma alfabética y algunos métodos para su manejo. 

* BolsaLetras: Clase que agrupa los métodos para generar los archivos de frecuencias y puntuaciones.

* mainwindow: Clase usada para una interfaz que hemos desarrollado en Qt como un extra.

Estas clases se usan en los siguientes ejecutables:

----------------------------------------------------------------------------------------------------------------

### Uso:
* Compilar TestDiccionario, UsoBolsaLetras y el Juego, : `make`

* Compilar la interfaz: 
	* Instalar Qt5, en el caso de Ubuntu es el paquete  `qt5-default`
	* Ejecutar `qmake && make -f Makefile_interfaz`

* Genear documentación: `make documentacion`

* Limpiar archivos de compilación: `make clean`

* Limpiar archivos de compilación y documentación: `make mrproper`

----------------------------------------------------------------------------------------------------------------

Las clases previamente mencionadas se usan en los siguientes ejecutables:

* **Testdiccionario:**
Testdiccionario simplemente sirve para comprobar que la clase Diccionario funciona bien. Carga el diccionario pasado como argumento y nos lo muestra, luego nos dice si la palabra que introducimos está en el diccionario, y finalmente nos muestra una lista con las palabras de tamaño menor o igual que el introducido.
Ejemplo:
` ./bin/TestDiccionario datos/diccionario1.txt `

* **UsoBolsaLetras:**
Antes de poder jugar al juego hay que generar el archivo con las puntuaciones, este sirve tanto para el juego por puntos como para el juego por tamaño, ya que de este archivo se extraen las letras que se pueden usar. Para generarlo usamos el programa UsoBolsaLetras, que dado un diccionario y un archivo lista de letras, nos generará tanto el archivo de puntuaciones como el archivo en el que se listan las frecuencias de cada letra.
 Ejemplo:
`./bin/UsoBolsaLetras datos/diccionario80000.txt datos/letras.txt datos/frecuencias.txt datos/puntuaciones.txt `

* **Juego:**
Para ejecutar el juego llamamos al binario y le pasamos de primer argumento el diccionario a usar, de segundo argumento el archivo con las puntuaciones generado a partir de dicho diccionario, de tercer argumento el tamaño de palabra máximo y de cuarto argumento el modo de juego.
Si el tercer argumento es superor al tamaño de la bolsa de letras (suma de todos los elementos de la columna cantidad de puntuaciones.txt) el programa mostrará un mensaje de error y se cerrará. 
Además Juego admite un quinto argumento opcional para decidir si admite palabra que no estén recogidas en el diccionario. Si queremos jugar así debemos pasar una `s` como quinto argumento. Si no se pasa un quinto argumento, el juego solo admitirá palabras del diccionario.
Ejemplo:
`./bin/Juego datos/diccionario80000.txt datos/puntuaciones.txt 8 P`

* **Interfaz:**
Hemos optado por añadir una interfaz sencilla al juego usando Qt y aprovechando la clase Letras que habiamos creado. Para usarla basta con ejecutar el archivo `Interfaz_letras` y pulsar el botón de cargar archivos, a continuación saldrán dos dialogos de seleccionar archivos uno detrás de otro, en el primero debemos seleccionar el archivo del diccionario, en el segundo en de puntuaciones. Una vez cargados podemos jugar introduciendo una palabra y pulsando comprobar. También podemos cambiar el modo de juego y el tamaño máximo de la palabra con los correspondientes botones.

