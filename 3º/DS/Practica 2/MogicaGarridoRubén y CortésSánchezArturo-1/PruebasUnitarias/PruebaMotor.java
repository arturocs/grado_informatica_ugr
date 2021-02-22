package PruebasUnitarias;

import Coche.Coche;
import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Motor;
import InterfazGrafica.Interfaz;
import junit.framework.TestCase;

public class PruebaMotor extends TestCase{
  public void testPalanca() {
    Motor motor1 = null;
    Motor motor2;
    Coche coche;
    ControlAutomatico ca = null;
    Interfaz interfaz = new Interfaz();
    
    coche = new Coche(interfaz);
    ca = new ControlAutomatico(motor1, coche);
    motor1 = new Motor(coche, ca);
    motor2 = new Motor(coche, ca);
    
    motor1.frenar();
    motor2.frenar();
    
    assertEquals(motor1.toString(), motor2.toString());

  }
  
}