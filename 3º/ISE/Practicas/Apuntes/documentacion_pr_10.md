# Documentación Práctica 4
##### por: Arturo Cortés Sánchez

## Phoronix test suite

1. Instalamos phoronix-test-suite desde los repositorios.
2. Ejecutamos `phoronix-test-suite list-available-tests` y elegimos dos tests, por ejemplo cachebench y sudokut.
3. Ejecutamos `phoronix-test-suite install pts/cachebench` para instalar el test.
4. Ejecutamos `phoronix-test-suite run pts/cachebench` elegimos test 1. Denegamos guardar los resultados ya que luego se mostrarán por pantalla.
5. Cuando finalicen las tres rondas del test, se nos mostrará por pantalla el resultado, unos ~1900 MB/S de media.
6. Repetimos los pasos con `pts/sudokut`, el cual dará de resultado unos ~30 S de media.

## Benchmaks web
Uso la maquina de zabbix ya que tiene servidor HTTP accesible desde el anfitrión.

### ab
```l
ab -n 10000 -c 2 http://192.168.56.106/
```

-n : Número de peticiones.
-c : Número de hebras.

### jmeter

1. Botón derecho sobre plan de pruebas -> Añadir -> Hilos (Usuarios) -> Grupo de hilos.
2. Introducimos un número de hilos (en mi caso 5) y un número de peticiones (contador de bucle), por ejemplo 10.
3. Botón derecho sobre el grupo de hilos -> Añadir -> Elemento de configuración -> valores por defecto para petición HTTP.
4. En el nombre de servidor ponemos la IP de la máquina.
5. Botón derecho sobre el grupo de hilos -> Añadir -> Elemento de configuración -> Gestor de cookies HTTP.
6. Botón derecho sobre el grupo de hilos -> Añadir -> Muestreador -> Petición HTTP.
7. Botón derecho sobre el grupo de hilos -> Añadir -> Receptor -> Gráfico.
8. Pulsar botón de play

### Comparación de ab y jmeter

Cuando a ab se le pide que use multiples hebras, este solo genera un proceso, mientras que jtmetes abre tantos procesos como hebras le digas.
Supongo que debido a esto es por lo que jmeter es capaz de hacer ~140000 peticiones por minuto mientras que ab solo llega a ~90000 peticiones.

## Optimización web

1. Hacemos `ab -n 100000 -c 1 http://192.168.56.106/` y comprobamos que da un tiempo medio por petición de 0.956 ms

2. Editamos los parámetros de apache `/etc/apache2/mods-available/mpm_prefork.conf` y cambiamos MaxRequestsWorkers a 256

3. Volvemos a repetir el primer paso y comprobamos como el tiempo de cada petición ha bajado a 0.869 ms


## Referencias

https://httpd.apache.org/docs/2.4/programs/ab.html
http://jmeter.apache.org/usermanual/build-web-test-plan.html
https://blog.diacode.com/testeando-el-rendimiento-de-tu-aplicacion-con-apache-bench
https://serverfault.com/questions/684424/how-to-tune-apache-on-ubuntu-14-04-server
https://docs.moodle.org/33/en/Performance_recommendations
