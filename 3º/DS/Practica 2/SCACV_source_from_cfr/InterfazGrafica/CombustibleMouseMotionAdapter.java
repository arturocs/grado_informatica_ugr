/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.PanelAcelerador;
import SimuladorVehiculo.Vehiculo;
import java.awt.Cursor;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

class CombustibleMouseMotionAdapter
extends MouseMotionAdapter {
    PanelAcelerador panel;
    Vehiculo vehiculo;

    public CombustibleMouseMotionAdapter(PanelAcelerador panel, Vehiculo vehiculo) {
        this.panel = panel;
        this.vehiculo = vehiculo;
    }

    @Override
    public void mouseMoved(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        this.vehiculo.getClass();
        if (this.vehiculo.getEstadoMotor() == 0 && this.vehiculo.getVelocidad() == 0.0) {
            if (y > 120 && y < 146 && x > 20 && x < 120) {
                this.panel.setCursor(new Cursor(12));
            } else {
                this.panel.setCursor(new Cursor(0));
            }
        }
    }
}

