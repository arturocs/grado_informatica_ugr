# Ejercicios Autónomos 2
#### Por: Arturo Cortés Sánchez

2. **Discuta por qué el servicio DNS utiliza la arquitectura jerárquica.**
```l
El servicio DNS se organiza de dicha manera porque un nombre de dominio
consiste en la concatenación de las distintas etiquetas (Raíz, TLD,
dominio y host), para formar dicho nombre se parte de la raiz, se
recorre el árbol hasta llegar al host.
```

3. **Discuta por qué el servicio de correo tiene una estructura con al menos dos servidores.**
```l
Es necesario un servidor al que el usuario pueda acceder para ver los correos
recibidos así como un servidor desde el que enviar los correos. En el primer
caso se usaría un servidor IMAP o POP, y en el segundo un servidor SMTP.
```

4. **Discuta por qué es necesario mantener la integridad en un protocolo seguro.**
```l
Dado que un protocolo seguro usa un cifrado, un error en la integridad de la
información transmitida haría que fuera imposible descifrarla.
```
