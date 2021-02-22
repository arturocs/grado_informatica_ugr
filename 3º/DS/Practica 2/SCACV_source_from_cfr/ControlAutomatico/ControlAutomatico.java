/*
 * Decompiled with CFR 0_123.
 */
package ControlAutomatico;

import ControlAutomatico.Acelerador;
import ControlAutomatico.CalculadorVelocidad;

public class ControlAutomatico
extends Thread {
    public static final int ACELERANDO = 0;
    public static final int MANTENIENDO = 1;
    public static final int REINICIANDO = 2;
    public static final int APAGADO = 3;
    public static final int FRENANDO = 4;
    public final double CteACELERACION = 5.0;
    private Acelerador acelerador;
    private CalculadorVelocidad calculadorVelocidad;
    private int estado;
    private int historico;
    private double velocidadAutomatica;
    private boolean salir;

    public ControlAutomatico(Acelerador acelerador, CalculadorVelocidad calculadorVelocidad) {
        this.acelerador = acelerador;
        this.calculadorVelocidad = calculadorVelocidad;
        this.estado = 3;
        this.historico = 3;
        this.velocidadAutomatica = 0.0;
    }

    public double getVelocidadAutomatica() {
        return this.velocidadAutomatica;
    }

    public int getEstado() {
        return this.estado;
    }

    public void setVelocidadAutomatica() {
        this.velocidadAutomatica = this.calculadorVelocidad.getVelocidad();
    }

    public void cambiaEstado(int cambio) {
        this.historico = this.estado;
        this.estado = cambio;
    }

    public void recuperarEstado() {
        this.estado = this.historico == 0 ? this.historico : 3;
    }

    public void mantener() {
        double errorVelocidad = this.calculadorVelocidad.getVelocidad() - this.velocidadAutomatica;
        if (errorVelocidad > 0.0) {
            this.acelerador.desacelerar(errorVelocidad * 5.0);
        }
        if (errorVelocidad < 0.0) {
            this.acelerador.acelerar((- errorVelocidad) * 5.0);
        }
    }

    public void iniciarHebra() {
        this.salir = false;
        if (!this.isAlive()) {
            this.start();
        }
    }

    public void salirHebra() {
        this.salir = true;
    }

    public void apagarMotor() {
        this.velocidadAutomatica = 0.0;
    }

    /*
     * Exception decompiling
     */
    @Override
    public void run()
    {
      while (!salir)
      {
        switch (estado)
        {
        case 0: 
          while (estado == 0)
          {
            try
            {
              acelerador.acelerar(5.0D);
              sleep(200L);
            } catch (InterruptedException localInterruptedException) {}
          }
          break;
        case 1: 
          while (estado == 1)
          {
            try
            {
              mantener();
              sleep(100L);
            } catch (InterruptedException localInterruptedException1) {}
          }
          break;
        case 2: 
          while (estado == 2)
          {
            try
            {
              do
              {
                acelerador.acelerar(5.0D);
                sleep(200L);
              } while ((calculadorVelocidad.getVelocidad() <= velocidadAutomatica) && (estado == 2));
              



              if (estado == 2) {
                cambiaEstado(1);
              }
            } catch (InterruptedException localInterruptedException2) {}
          }
          break;
        case 3: 
          acelerador.apagar();
          while (estado == 3)
          {
            try
            {

              sleep(1000L);
            } catch (InterruptedException localInterruptedException3) {}
          }
          break;
        case 4: 
          acelerador.apagar();
          while (estado == 4)
          {
            try
            {

              sleep(1000L);
            }
            catch (InterruptedException localInterruptedException4) {}
          }
        }
      }
    }
  }