package PruebasUnitarias;


import Coche.Coche;
import Coche.MonitorizarCoche;
import InterfazGrafica.Interfaz;
import junit.framework.TestCase;

class PruebaMonitorizarCoche extends TestCase {


	  public void testCoche()  {
	    Interfaz interfaz = new Interfaz();
	    Coche coche = new Coche(interfaz);
	    MonitorizarCoche monitor1 = new MonitorizarCoche(coche);
	    MonitorizarCoche monitor2 = new MonitorizarCoche(coche);
	    coche.aumentarAcelerador(3);
	    
	    assertEquals(monitor1.getVelocidad(),monitor2.getVelocidad());
	    
	}

}
