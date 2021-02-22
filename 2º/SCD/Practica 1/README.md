# Documentación Pŕactica 1 SCD
##### Por: Arturo Cortés Sánchez

### Productor-consumidor

**Semáforos usados**:

*  puede_producir:
	* Uso: Pausa la `hebra_productora` cuando el buffer está lleno
	* Valor inicial: tamaño del buffer, en este caso 10
	* `hebra_produtora` hace `sem_wait()` sobre este semáforo y `hebra_consumidora` hace `sem_signal()`

*  puede_consumir:
	* Uso: Evita que la hebra_consumidora consuma datos del buffer cuando este está vacío
	* Valor inicial: 0
	* `hebra_produtora` hace `sem_signal()` sobre este semáforo y `hebra_consumidora` hace `sem_wait()`

*  s_mutex:
	* Uso: Evita accesos simultaneos al buffer y al contador
	* Valor inicial: 1
	* Tanto `hebra_productora` como `hebra_consumidora` hacen `sem_wait()` y `sem_signal()` sobre este semáforo


---

### Fumadores

**Semáforos usados**:

* mostr_vacio:
	* Uso: Evitar que el estanquero coloque un ingrediente si hay otro en el mostrador
	* Valor inicial: 1
	* La hebra `estanquero`hace `sem_wait()` sobre este semáforo y cada hebra `fumador[i]` hace `sem_signal`
	
* ingr_disp[3]
	* Uso: Regula cuando un fumador puede fumar
	* Valor inicial: 0
	* La hebra `fumador[i]` hace `sem_signal()` y la hebra `estanquero` hace `sem_wait()` sobre este semáforo