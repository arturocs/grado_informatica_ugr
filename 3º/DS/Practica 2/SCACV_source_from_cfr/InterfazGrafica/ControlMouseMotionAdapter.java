/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.PanelControlAutomatico;
import java.awt.Cursor;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

class ControlMouseMotionAdapter
extends MouseMotionAdapter {
    PanelControlAutomatico panel;

    public ControlMouseMotionAdapter(PanelControlAutomatico panel) {
        this.panel = panel;
    }

    @Override
    public void mouseMoved(MouseEvent event) {
        int x = event.getX();
        int y = event.getY();
        if (y > 240 && y < 275 && x > 25 && x < 145) {
            this.panel.setCursor(new Cursor(12));
        } else if (y > 289 && y < 325 && x > 25 && x < 145) {
            this.panel.setCursor(new Cursor(12));
        } else {
            this.panel.setCursor(new Cursor(0));
        }
    }
}

