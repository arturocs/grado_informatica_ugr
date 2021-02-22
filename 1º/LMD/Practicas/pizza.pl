/* Base de datos para la Practica de Introducción a Prolog */

/* Estructura para persona: persona(nombre, edad, género) */

persona(alba,     16, mujer).
persona(bernardo, 21, hombre).
persona(carlos,   33, hombre).
persona(diana,    24, mujer).
persona(emi,      45, mujer).
persona(fina,     13, mujer).
persona(guille,   24, hombre).
persona(hipolito, 30, hombre).
persona(ines,     18, mujer).

/* Estructura para frecuenta: frecuenta(nombre, pizzeria) */

frecuenta(alba,     pizza_metro).
frecuenta(bernardo, pizza_metro).
frecuenta(bernardo, mamma_mia).
frecuenta(carlos,   gondoliere).
frecuenta(carlos,   telepizza).
frecuenta(diana,    gondoliere).
frecuenta(diana,    telepizza).
frecuenta(emi,      gondoliere).
frecuenta(emi,      mamma_mia).
frecuenta(fina,     dominos).
frecuenta(fina,     pizza_hut).
frecuenta(guille,   mamma_mia).
frecuenta(guille,   pizza_metro).
frecuenta(hipolito, dominos).
frecuenta(hipolito, gondoliere).
frecuenta(hipolito, pizza_metro).
frecuenta(ines,     telepizza).
frecuenta(ines,     gondoliere).
frecuenta(ines,     dominos).

/* Estructura para come: come(nombre, pizza) */

come(alba,     pepperoni).
come(alba,     funghi).
come(bernardo, pepperoni).
come(bernardo, cuatro_quesos).
come(carlos,   primavera).
come(diana,    pepperoni).
come(diana,    cuatro_quesos).
come(diana,    prosciutto).
come(diana,    primavera).
come(diana,    funghi).
come(emi,      primavera).
come(emi,      cuatro_quesos).
come(fina,     funghi).
come(guille,   funghi).
come(guille,   primavera).
come(guille,   cuatro_quesos).
come(hipolito, primavera).
come(hipolito, cuatro_quesos).
come(ines,     primavera).
come(ines,     pepperoni).

/* Estructura para sirve: sirve(pizzeria, pizza, precio) */

sirve(pizza_metro, pepperoni,     12).
sirve(pizza_metro, prosciutto,    12).
sirve(pizza_metro, cuatro_quesos, 9).
sirve(pizza_metro, primavera,     12).
sirve(pizza_hut,   pepperoni,     9.75).
sirve(pizza_hut,   prosciutto,    12).
sirve(pizza_hut,   cuatro_quesos, 7).
sirve(pizza_hut,   funghi,        9.25).
sirve(dominos,     cuatro_quesos, 9.75).
sirve(dominos,     funghi,        11).
sirve(gondoliere,  pepperoni,     8).
sirve(gondoliere,  cuatro_quesos, 9.25).
sirve(gondoliere,  prosciutto,    9.75).
sirve(telepizza,   pepperoni,     8).
sirve(telepizza,   cuatro_quesos, 7).
sirve(telepizza,   primavera,     8.5).
sirve(mamma_mia,   cuatro_quesos, 7.75).
sirve(mamma_mia,   primavera,     8.5).
