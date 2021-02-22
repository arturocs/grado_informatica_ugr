package PruebasUnitarias;

import Coche.Coche;

import InterfazGrafica.Interfaz;
import junit.framework.TestCase;

public class PruebaCoche extends TestCase {

  public void testCoche() {
    Interfaz interfaz = new Interfaz();
    Coche coche1 = new Coche(interfaz);
    Coche coche2 = new Coche(interfaz);   

    coche1.aumentarAcelerador(3);
    coche2.aumentarAcelerador(3);
    
    coche1.pararAcelerador();
    coche2.pararAcelerador();
    
    assertEquals(coche1.toString(), coche2.toString());
  }
}