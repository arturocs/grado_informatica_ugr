/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import ControlAutomatico.Palanca;
import InterfazGrafica.PalancaMouseAdapter;
import InterfazGrafica.PalancaMouseMotionAdapter;
import SimuladorVehiculo.Vehiculo;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Shape;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;
import javax.swing.JPanel;

public class PanelPalanca
extends JPanel {
    private Rectangle2D rectVertical;
    private Rectangle2D rectHorizontal;
    private RoundRectangle2D botonAcelerar;
    private RoundRectangle2D botonParar;
    private RoundRectangle2D botonMantener;
    private RoundRectangle2D botonReiniciar;
    private Ellipse2D bola;
    private AffineTransform t;
    private Vehiculo vehiculo;
    private Palanca palanca;

    public PanelPalanca(Vehiculo vehiculo, Palanca palanca) {
        this.vehiculo = vehiculo;
        this.palanca = palanca;
        this.setSize(140, 140);
        this.setBackground(new Color(0, 0, 102));
        this.rectVertical = new Rectangle2D.Double(-15.0, (- this.getHeight()) / 3, 30.0, 2 * this.getHeight() / 3);
        this.rectHorizontal = new Rectangle2D.Double((- this.getWidth()) / 3, -15.0, this.getWidth() / 3 + 15, 30.0);
        this.botonAcelerar = new RoundRectangle2D.Double(-30.0, (- this.getHeight()) / 3 - 22, 60.0, 20.0, 5.0, 5.0);
        this.botonParar = new RoundRectangle2D.Double((- this.getWidth()) / 3 - 42, -10.0, 40.0, 20.0, 5.0, 5.0);
        this.botonMantener = new RoundRectangle2D.Double(17.0, -10.0, 60.0, 20.0, 5.0, 5.0);
        this.botonReiniciar = new RoundRectangle2D.Double(-30.0, this.getHeight() / 3 + 2, 60.0, 20.0, 5.0, 5.0);
        this.bola = new Ellipse2D.Double(-15.0, -15.0, 30.0, 30.0);
        this.t = new AffineTransform();
        this.t.setToTranslation((- this.getWidth()) / 3 + 15, 0.0);
        this.addMouseListener(new PalancaMouseAdapter(this, vehiculo));
        this.addMouseMotionListener(new PalancaMouseMotionAdapter(this, vehiculo));
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.translate(this.getWidth() / 2 + 5, this.getHeight() / 2);
        g2.setPaint(Color.gray);
        g2.fill(this.rectVertical);
        g2.fill(this.rectHorizontal);
        this.vehiculo.getClass();
        if (this.vehiculo.getEstadoMotor() == 1) {
            g2.setPaint(Color.yellow);
        } else {
            g2.setPaint(new Color(30, 144, 255));
        }
        g2.fill(this.botonAcelerar);
        g2.fill(this.botonMantener);
        g2.fill(this.botonReiniciar);
        g2.fill(this.botonParar);
        g2.setPaint(Color.white);
        g2.draw(this.botonAcelerar);
        g2.draw(this.botonMantener);
        g2.draw(this.botonReiniciar);
        g2.draw(this.botonParar);
        g2.setPaint(Color.black);
        g2.setFont(new Font("TimesRoman", 1, 12));
        g2.drawString("Parar", (- this.getWidth()) / 3 - g2.getFontMetrics().stringWidth("Parar"), 6);
        g2.drawString("Mantener", 20, 6);
        g2.drawString("Acelerar", (- g2.getFontMetrics().stringWidth("Acelerar")) / 2, (- this.getHeight()) / 3);
        g2.drawString("Reiniciar", (- g2.getFontMetrics().stringWidth("Reiniciar")) / 2, this.getHeight() / 3 + 10);
        g2.transform(this.t);
        g2.fill(this.bola);
    }

    public void posMantener() {
        this.palanca.setPosicion(1);
        this.repintar();
    }

    public void posParar() {
        this.palanca.setPosicion(3);
        this.repintar();
    }

    public void posAcelerar() {
        this.palanca.setPosicion(0);
        this.repintar();
    }

    public void posReiniciar() {
        this.palanca.setPosicion(2);
        this.repintar();
    }

    public void repintar() {
        switch (this.palanca.getPosicion()) {
            case 0: {
                this.t.setToTranslation(0.0, (- this.getHeight()) / 3 + 15);
                break;
            }
            case 1: {
                this.t.setToTranslation(0.0, 0.0);
                break;
            }
            case 3: {
                this.t.setToTranslation((- this.getWidth()) / 3 + 15, 0.0);
                break;
            }
            case 2: {
                this.t.setToTranslation(0.0, this.getHeight() / 3 - 15);
            }
        }
        this.repaint();
    }
}

