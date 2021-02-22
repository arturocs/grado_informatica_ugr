/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Freno;
import InterfazGrafica.PanelControlAutomatico;
import SimuladorVehiculo.Vehiculo;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class ControlMouseAdapter
extends MouseAdapter {
    PanelControlAutomatico panel;
    Vehiculo vehiculo;
    ControlAutomatico controlAutomatico;
    Freno freno;

    public ControlMouseAdapter(PanelControlAutomatico panel, Vehiculo vehiculo, ControlAutomatico controlAutomatico, Freno freno) {
        this.panel = panel;
        this.vehiculo = vehiculo;
        this.controlAutomatico = controlAutomatico;
        this.freno = freno;
    }

    @Override
    public void mouseClicked(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        if (y > 240 && y < 275 && x > 25 && x < 145) {
            this.vehiculo.getClass();
            if (this.vehiculo.getEstadoMotor() == 0) {
                this.vehiculo.arrancar();
                this.controlAutomatico.iniciarHebra();
            } else if (this.controlAutomatico.getEstado() == 3) {
                this.vehiculo.pararMotor();
                this.controlAutomatico.apagarMotor();
            }
        }
    }

    @Override
    public void mousePressed(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        if (y > 289 && y < 325 && x > 25 && x < 145) {
            this.freno.frenar();
        }
    }

    @Override
    public void mouseReleased(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        if (y > 289 && y < 325 && x > 25 && x < 145) {
            this.freno.soltarFreno();
        }
    }
}

