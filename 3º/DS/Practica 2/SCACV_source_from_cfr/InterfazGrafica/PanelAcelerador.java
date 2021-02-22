/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import InterfazGrafica.CombustibleMouseAdapter;
import InterfazGrafica.CombustibleMouseMotionAdapter;
import SimuladorVehiculo.Vehiculo;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Shape;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.Arc2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;
import javax.swing.JPanel;

public class PanelAcelerador
extends JPanel {
    private Rectangle2D cuadroInyector;
    private Rectangle2D rellenoInyector;
    private RoundRectangle2D botonRepostar;
    private Arc2D visorCombustible;
    private Line2D segmentoLargo;
    private Line2D segmentoCorto;
    private GeneralPath aguja;
    private AffineTransform t;
    private double combustible;
    private double inyector;
    private Vehiculo vehiculo;

    public PanelAcelerador(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
        this.combustible = 0.0;
        this.inyector = 0.0;
        this.setSize(330, 170);
        this.visorCombustible = new Arc2D.Double(20.0, 55.0, 100.0, 100.0, 0.0, 180.0, 1);
        this.botonRepostar = new RoundRectangle2D.Double(20.0, 120.0, 100.0, 25.0, 10.0, 10.0);
        this.cuadroInyector = new Rectangle2D.Double(200.0, 50.0, 45.0, 80.0);
        this.rellenoInyector = new Rectangle2D.Double(200.0, 50.0, 45.0, 80.0);
        this.segmentoLargo = new Line2D.Double(-50.0, 0.0, -40.0, 0.0);
        this.segmentoCorto = new Line2D.Double(-50.0, 0.0, -45.0, 0.0);
        this.aguja = new GeneralPath();
        this.aguja.moveTo(5.0f, 0.0f);
        this.aguja.lineTo(0.0f, 5.0f);
        this.aguja.lineTo(-50.0f, 0.0f);
        this.aguja.lineTo(0.0f, -5.0f);
        this.aguja.closePath();
        this.t = new AffineTransform();
        this.setBackground(new Color(0, 0, 102));
        this.addMouseListener(new CombustibleMouseAdapter(this, vehiculo));
        this.addMouseMotionListener(new CombustibleMouseMotionAdapter(this, vehiculo));
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setPaint(Color.red);
        if (this.inyector > 0.0) {
            this.rellenoInyector.setRect(200.0, 130.0 - this.inyector * 80.0 / 100.0, 45.0, this.inyector * 80.0 / 100.0);
            g2.fill(this.rellenoInyector);
        }
        this.vehiculo.getClass();
        if (this.vehiculo.getEstadoMotor() == 0 && this.vehiculo.getVelocidad() == 0.0) {
            g2.setPaint(Color.yellow);
        } else {
            g2.setPaint(new Color(30, 144, 255));
        }
        g2.fill(this.botonRepostar);
        g2.setFont(new Font("TimesRoman", 0, 16));
        g2.setPaint(Color.BLACK);
        g2.drawString("Repostar", 35, 140);
        g2.setPaint(Color.white);
        g2.draw(this.visorCombustible);
        g2.draw(this.cuadroInyector);
        g2.draw(this.cuadroInyector);
        g2.draw(this.botonRepostar);
        g2.drawString("Combustible", 25, 35);
        g2.drawString("Inyector", 200, 35);
        g2.drawString("R", 10, 108);
        g2.drawString("1/4", 21, 66);
        g2.drawString("1/2", 63, 51);
        g2.drawString("3/4", 102, 63);
        g2.drawString("1", 120, 108);
        g2.translate(70, 105);
        int angulo = 1;
        while (angulo <= 4) {
            this.t.setToRotation(Math.toRadians(15.0));
            g2.transform(this.t);
            g2.draw(this.segmentoCorto);
            this.t.setToRotation(Math.toRadians(15.0));
            g2.transform(this.t);
            g2.draw(this.segmentoCorto);
            this.t.setToRotation(Math.toRadians(15.0));
            g2.transform(this.t);
            g2.draw(this.segmentoLargo);
            ++angulo;
        }
        this.t.setToRotation(Math.toRadians(180.0 + this.combustible * 180.0 / 100.0));
        g2.transform(this.t);
        g2.setPaint(Color.red);
        g2.fill(this.aguja);
    }

    public void repintar() {
        this.combustible = this.vehiculo.getCombustible();
        this.inyector = this.vehiculo.getInyector();
        this.repaint();
    }
}

