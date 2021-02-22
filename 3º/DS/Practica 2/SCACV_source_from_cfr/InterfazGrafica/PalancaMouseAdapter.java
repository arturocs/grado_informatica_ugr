/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.PanelPalanca;
import SimuladorVehiculo.Vehiculo;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class PalancaMouseAdapter
extends MouseAdapter {
    PanelPalanca panel;
    Vehiculo vehiculo;

    public PalancaMouseAdapter(PanelPalanca panel, Vehiculo vehiculo) {
        this.panel = panel;
        this.vehiculo = vehiculo;
    }

    @Override
    public void mouseClicked(MouseEvent event) {
        if (this.vehiculo.getEstadoMotor() == 1) {
            int x = event.getX();
            int y = event.getY();
            if (y > 17 && y < 38 && x > 60 && x < 121) {
                this.panel.posAcelerar();
            }
            if (y > 75 && y < 96 && x > 1 && x < 44) {
                this.panel.posParar();
            }
            if (y > 75 && y < 96 && x > 107 && x < 168) {
                this.panel.posMantener();
            }
            if (y > 133 && y < 154 && x > 60 && x < 121) {
                this.panel.posReiniciar();
            }
        }
    }
}

