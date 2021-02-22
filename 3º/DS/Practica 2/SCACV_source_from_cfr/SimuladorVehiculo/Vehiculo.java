/*
 * Decompiled with CFR 0_123.
 */
package SimuladorVehiculo;

import InterfazGrafica.InterfazGrafica;

public class Vehiculo
extends Thread {
    public final int PARADO = 0;
    public final int ARRANCADO = 1;
    final int maxInyector = 100;
    private double velocidad;
    private double inyector;
    private double combustible;
    private int estado;
    private double frenado;
    private double distancia;
    private double rozamientoAire;
    private double rozamientoSuelo;
    private boolean salir;
    private InterfazGrafica interfaz;

    public Vehiculo(InterfazGrafica interfaz) {
        this.interfaz = interfaz;
        this.velocidad = 0.0;
        this.inyector = 0.0;
        this.combustible = 100.0;
        this.estado = 0;
        this.frenado = 0.0;
        this.distancia = 0.0;
        this.rozamientoAire = 0.004318;
        this.rozamientoSuelo = 0.05;
        this.salir = false;
    }

    public double getInyector() {
        return this.inyector;
    }

    public double getCombustible() {
        return this.combustible;
    }

    public double getDistancia() {
        return this.distancia;
    }

    public double getVelocidad() {
        return this.velocidad;
    }

    public int getEstadoMotor() {
        return this.estado;
    }

    public void repostar() {
        this.combustible = 100.0;
    }

    public void cerrarInyector() {
        this.inyector = 0.0;
    }

    public void frenar(int CteFRENADO) {
        this.frenado = CteFRENADO;
    }

    public void soltarFreno() {
        this.frenado = 0.0;
    }

    public void aumentarInyector(double CteACELERACION) {
        if (this.inyector < 100.0) {
            this.inyector += CteACELERACION;
        }
        if (this.inyector > 100.0) {
            this.inyector = 100.0;
        }
    }

    public void disminuirInyector(double CteACELERACION) {
        if (this.inyector > 0.0) {
            this.inyector -= CteACELERACION;
        }
        if (this.inyector < 0.0) {
            this.inyector = 0.0;
        }
    }

    public void arrancar() {
        this.estado = 1;
        this.salir = false;
        if (!this.isAlive()) {
            this.start();
        }
    }

    public void pararMotor() {
        this.estado = 0;
    }

    public void salirHebra() {
        this.estado = 0;
        this.salir = true;
        this.interfaz.repintar();
    }

    @Override
    public void run() {
        while (!this.salir) {
            try {
                this.velocidad += this.inyector * 0.01 - this.frenado - this.rozamientoSuelo - this.rozamientoAire * this.velocidad;
                if (this.velocidad < 0.0) {
                    this.velocidad = 0.0;
                }
                this.distancia += this.velocidad * 2.78E-5;
                this.combustible -= this.inyector * 1.0E-5;
                if (this.combustible < 0.0) {
                    this.combustible = 0.0;
                }
                this.interfaz.repintar();
                Vehiculo.sleep(100);
            }
            catch (InterruptedException interruptedException) {
                // empty catch block
            }
        }
    }
}

