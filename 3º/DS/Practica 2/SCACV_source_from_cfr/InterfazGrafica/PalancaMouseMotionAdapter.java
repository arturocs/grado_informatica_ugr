/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.PanelPalanca;
import SimuladorVehiculo.Vehiculo;
import java.awt.Cursor;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

class PalancaMouseMotionAdapter
extends MouseMotionAdapter {
    PanelPalanca panel;
    Vehiculo vehiculo;

    public PalancaMouseMotionAdapter(PanelPalanca panel, Vehiculo vehiculo) {
        this.panel = panel;
        this.vehiculo = vehiculo;
    }

    @Override
    public void mouseMoved(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        this.vehiculo.getClass();
        if (this.vehiculo.getEstadoMotor() == 1) {
            if (y > 17 && y < 38 && x > 60 && x < 121) {
                this.panel.setCursor(new Cursor(12));
            } else if (y > 75 && y < 96 && x > 1 && x < 44) {
                this.panel.setCursor(new Cursor(12));
            } else if (y > 75 && y < 96 && x > 107 && x < 168) {
                this.panel.setCursor(new Cursor(12));
            } else if (y > 133 && y < 154 && x > 60 && x < 121) {
                this.panel.setCursor(new Cursor(12));
            } else {
                this.panel.setCursor(new Cursor(0));
            }
        }
    }
}

