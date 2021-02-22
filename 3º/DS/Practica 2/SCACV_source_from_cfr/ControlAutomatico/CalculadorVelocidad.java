/*
 * Decompiled with CFR 0_123.
 */
package ControlAutomatico;

import SimuladorVehiculo.Vehiculo;

public class CalculadorVelocidad {
    private Vehiculo vehiculo;
    private double velocidad;

    public CalculadorVelocidad(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
        this.velocidad = 0.0;
    }

    double getVelocidad() {
        this.velocidad = this.vehiculo.getVelocidad();
        return this.velocidad;
    }
}

