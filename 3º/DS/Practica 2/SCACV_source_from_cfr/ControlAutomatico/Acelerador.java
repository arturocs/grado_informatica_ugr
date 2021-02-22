/*
 * Decompiled with CFR 0_123.
 */
package ControlAutomatico;

import SimuladorVehiculo.Vehiculo;

public class Acelerador {
    private Vehiculo vehiculo;

    public Acelerador(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
    }

    void acelerar(double CteACELERACION) {
        this.vehiculo.aumentarInyector(CteACELERACION);
    }

    void desacelerar(double CteACELERACION) {
        this.vehiculo.disminuirInyector(CteACELERACION);
    }

    void apagar() {
        this.vehiculo.cerrarInyector();
    }
}

