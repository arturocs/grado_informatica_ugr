package PruebasUnitarias;

import Coche.Coche;
import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Motor;
import ControlAutomatico.Palanca;
import InterfazGrafica.Interfaz;
import junit.framework.TestCase;

public class PruebaPalanca extends TestCase{
  public void testPalanca() {
    Motor motor;
    Coche coche;
    ControlAutomatico ca = null;
    Interfaz interfaz = new Interfaz();
    Palanca palanca1;
    Palanca palanca2;
    
    coche = new Coche(interfaz);
    motor = new Motor(coche, ca);
    ca = new ControlAutomatico(motor, coche);
    palanca1 = new Palanca(ca);
    palanca2 = new Palanca(ca);
    
    palanca1.moverPalanca(4);
    palanca2.moverPalanca(4);
    
    assertEquals(palanca1.toString(), palanca2.toString());
  }
  
}