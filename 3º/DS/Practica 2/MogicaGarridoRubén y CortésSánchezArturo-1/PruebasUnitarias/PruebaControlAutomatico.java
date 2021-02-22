package PruebasUnitarias;

import Coche.Coche;
import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Motor;
import InterfazGrafica.Interfaz;
import junit.framework.TestCase;

public class PruebaControlAutomatico extends TestCase {
	ControlAutomatico controlAutomatico;
	Motor motor;

	public void testControl() {
			Interfaz interfaz = new Interfaz();
			Coche coche= new Coche(interfaz);
			controlAutomatico = new ControlAutomatico(motor, coche);
			motor = new Motor(coche, controlAutomatico);
			
			controlAutomatico.cambiarEstado(3);
			assertEquals(3,controlAutomatico.getEstado());

	  }

	}

