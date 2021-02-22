# Memoria seminario 2

##### Por: Arturo Cortés Sánchez

**1. Modificar el programa solución del ejercicio 3.2 Send Receive del tutorial para que el proceso 0 difunda su identificador de proceso (0) al resto de procesos con identificadores pares, siguiendo un anillo de procesos pares, y el proceso 1 haga lo mismo con los procesos impares. Se deben tener en cuenta soluciones con cualquier número de procesos.**

Para este ejercicio he considerado que ya que la progresión de los números pares y la de los impares tienen la misma diferencia entre dos elementos consecutivos, puedo ahorrarme repetir código si hago que tanto el proceso 0 como el proceso 1 envien su identificador al proceso 2 y 3 respectivamente, y que el resto de procesos envíen el mensaje al proceso cuyo identificador sea el identificador actual mas dos. Y que de la misma forma reciban un mensaje de un proceso cuyo identificador sea el identificador actual menos dos.

**2. Modificar el programa solución del cálculo paralelo del número π (3.3 Cálculo de PI) para que los subintervalos de trabajo sean distribuidos por bloques en lugar de cı́clicamente entre los procesos. Por ejemplo, si tuviéramos 3 procesos y n = 11 (número de subintervalos), el proceso 0 deberı́a aproximar las integrales numéricas en los primeros 4 subintervalos consecutivos (1,2,3,4), el proceso 1 calcuları́a las integrales en los siguientes 4 subintervalos (5,6,7,8,) y el proceso 2 calcuları́a los últimos tres (9,10,11). Se recomienda empezar derivando matemáticamente un método general para repartir por bloques n subintervalos entre P procesos para cualquier n entero positivo. Modificarlo también la solución para que la aproximación a π se obtenga en todos los procesos.**

Durante el tutorial he resuelto el ejercicio con el enfoque descrito en el ejercicio, por tanto no he realizado ninguna modificación. Pero observando la solución del tutorial veo que se esperaba que en lugar de agrupar los cálculos por subintervalos consecutivos, cada proceso realiza los cálculos del intervalo total pero saltando de size en size, siendo size el numero de procesos con el que el programa ha sido lanzado.


**3. Modificar el programa solución del cálculo del producto escalar de dos vectores (4.1 Producto Escalar) para que cada proceso inicialice por su cuenta su parte correspondiente del vector B de forma local, de tal forma que no haya necesidad de inicializar todo el vector B en el proceso 0 y repartir sus bloques entre los procesos.**

Para este ejercicio he tomado como base la solución del tutorial ya que mi solución no daba el resultado correcto. He eliminado la llamada a `MPI_Scatter()`   sobre `VectorB` y la he sustituido por el siguiente bucle:

```
  for (int i = tama / size * rank; VectorBLocal.size() < tama / size; i++) {
    VectorBLocal.push_back((i + 1) * 10);
  }
```

Este bucle es ejecutado por cada proceso y el VectorBLocal es rellenado con los valores adecuados.


**4. Modificar el programa solución del ejercicio 4.4 Comunicadores para que también se realice un Scatter de un vector de enteros desde el proceso 1 del comunicador global a todos los procesos impares de dicho comunicador. Los valores de este vector se escogen arbitrariamente en el proceso 0 (ojo, en el proceso con rango 0 del comunicador de rangos impares que es el proceso 1 de MPI Comm World), pero su tamaño debe ser igual número de procesos impares en el comunicador global. El reparto asignará un elemento de dicho vector a cada proceso impar del comunicador global. Se recomienda usar el comunicador de impares para realizar esta tarea.**

En este caso he vuelto a tomar como base la solución del tutorial ya que al compararla con la mía he visto que era erronea.
Para cumplir con lo que pedía el ejercicio he añadido un vector de enteros `vec`  que he rellenado con los números naturales así como una variable `num` para recibir los elementos del vector tras el `MPI_Scatter()`. Luego cada proceso impar imprime el elemento del vector que le ha sido asignado.


