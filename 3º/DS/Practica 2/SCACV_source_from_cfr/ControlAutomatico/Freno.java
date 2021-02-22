/*
 * Decompiled with CFR 0_123.
 */
package ControlAutomatico;

import ControlAutomatico.ControlAutomatico;
import SimuladorVehiculo.Vehiculo;

public class Freno {
    public static final int frenoPISADO = 4;
    public static final int frenoLIBRE = 5;
    public static final int CteFRENADO = 5;
    private Vehiculo vehiculo;
    private ControlAutomatico controlAutomatico;
    private int estado;

    public Freno(Vehiculo vehiculo, ControlAutomatico controlAutomatico) {
        this.vehiculo = vehiculo;
        this.controlAutomatico = controlAutomatico;
        this.estado = 5;
    }

    public int getEstado() {
        return this.estado;
    }

    void setEstado() {
        this.estado = this.estado == 5 ? 4 : 5;
        this.controlAutomatico.cambiaEstado(this.estado);
    }

    public void frenar() {
        this.estado = 4;
        this.controlAutomatico.cambiaEstado(4);
        this.vehiculo.frenar(5);
    }

    public void soltarFreno() {
        this.estado = 5;
        this.controlAutomatico.recuperarEstado();
        this.vehiculo.soltarFreno();
    }
}

