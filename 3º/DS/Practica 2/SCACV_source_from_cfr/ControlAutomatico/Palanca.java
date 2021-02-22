/*
 * Decompiled with CFR 0_123.
 */
package ControlAutomatico;

import ControlAutomatico.ControlAutomatico;

public class Palanca {
    public static final int ACELERAR = 0;
    public static final int MANTENER = 1;
    public static final int REINICIAR = 2;
    public static final int APAGAR = 3;
    private ControlAutomatico controlAutomatico;
    private int posicion;

    public Palanca(ControlAutomatico controlAutomatico) {
        this.controlAutomatico = controlAutomatico;
        this.posicion = 3;
    }

    public void setPosicion(int cambio) {
        if (cambio == 1 && this.controlAutomatico.getEstado() == 0) {
            this.controlAutomatico.setVelocidadAutomatica();
            this.controlAutomatico.cambiaEstado(cambio);
            this.posicion = cambio;
        }
        if (cambio == 2 && this.controlAutomatico.getEstado() == 3 && this.controlAutomatico.getVelocidadAutomatica() > 0.0) {
            this.controlAutomatico.cambiaEstado(cambio);
            this.posicion = cambio;
        }
        if (cambio == 3 && this.controlAutomatico.getEstado() != 0) {
            this.controlAutomatico.cambiaEstado(cambio);
            this.posicion = cambio;
        }
        if (cambio == 0) {
            this.controlAutomatico.cambiaEstado(cambio);
            this.posicion = cambio;
        }
    }

    public void cambiaPosicion(int cambio) {
        this.posicion = cambio;
    }

    public int getPosicion() {
        return this.posicion;
    }
}

