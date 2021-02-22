/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.PanelAcelerador;
import SimuladorVehiculo.Vehiculo;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class CombustibleMouseAdapter
extends MouseAdapter {
    PanelAcelerador panel;
    Vehiculo vehiculo;

    public CombustibleMouseAdapter(PanelAcelerador panel, Vehiculo vehiculo) {
        this.panel = panel;
        this.vehiculo = vehiculo;
    }

    @Override
    public void mouseClicked(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        if (y > 120 && y < 146 && x > 20 && x < 120) {
            this.vehiculo.getClass();
            if (this.vehiculo.getEstadoMotor() == 0 && this.vehiculo.getVelocidad() == 0.0) {
                this.vehiculo.repostar();
            }
        }
    }
}

