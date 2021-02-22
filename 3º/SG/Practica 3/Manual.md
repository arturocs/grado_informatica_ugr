##Manual de usuario de VR-microgames
####por:Arturo Cortés Sánchez

###Instrucciones de uso:
1. Iniciar un servidor HTTP en la carpeta raiz del proyecto con: `python -m SimpleHTTPServer` o `python -m http.server` dependiendo de la version de python instalada.
2. Acceder desde un navegardor web a la dirección: `localhost:8000`  y seleccionar el minijuego deseado. Para mover la cámara basta con hacer click y arrastrar y para seleccionar un minijuego hay que poner el circulo del centro de la pantalla sobre uno de los nombres.
3. Para acceder al modo VR hay que hacer uso de un móvil e introducir en el navegador la IP y puerto del servidor montado. En este caso la cámara gira con el movimiento del móvil y el mecanismo de selección es el mismo.

**Anotaciones:**
La práctica ha sido desarrollada sobre Firefox, tanto la versión de escritorio como la móvil.

###Instrucciones de cada minijuego

**Buscar:**
Al inicio del minijuego se mostrará un mensaje diciendo que personaje debe de encontrar el jugador (Superman, Homer Simpson, un monstruo o Wally) , basta con girar la cámara hasta encontrar dicho personaje.

**Ordenar:**
El jugador tiene delante 6 números desordenados los cuales debe mirar en orden, manteniendo la mirada un breve periodo de tiempo en cada uno de ellos en el orden correspondiente, cuando un numero es mirado este gira. 

**Esquivar:**
El jugador avanza hacia donde mira y debe esquivar unas esferas que se interponen en su camino hacia un anillo verde.

**Encestar:**
El jugador tiene una pelota que debe canastar en un anillo que tiene delante. La pelota se lanzará en la dirección de mirada cuando el cursor acabe de encogerse. 

