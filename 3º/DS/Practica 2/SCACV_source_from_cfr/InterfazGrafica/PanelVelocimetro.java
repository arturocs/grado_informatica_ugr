/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import SimuladorVehiculo.Vehiculo;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JPanel;

public class PanelVelocimetro
extends JPanel {
    private double velocidad;
    private double distancia;
    private Ellipse2D velocimetro;
    private Line2D segmentoCorto;
    private Line2D segmentoLargo;
    private Rectangle2D cuadroDistancia;
    private GeneralPath aguja;
    private AffineTransform t;
    private Vehiculo vehiculo;

    public PanelVelocimetro(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
        this.velocidad = 0.0;
        this.distancia = 0.0;
        this.setSize(290, 290);
        this.setBackground(new Color(0, 0, 102));
        this.velocimetro = new Ellipse2D.Double(-135.0, -135.0, 270.0, 270.0);
        this.segmentoCorto = new Line2D.Double(-135.0, 0.0, -127.0, 0.0);
        this.segmentoLargo = new Line2D.Double(-135.0, 0.0, -119.0, 0.0);
        this.cuadroDistancia = new Rectangle2D.Double(148.0, 230.0, 50.0, 20.0);
        this.aguja = new GeneralPath();
        this.aguja.moveTo(10.0f, 0.0f);
        this.aguja.lineTo(0.0f, 10.0f);
        this.aguja.lineTo(-130.0f, 0.0f);
        this.aguja.lineTo(0.0f, -10.0f);
        this.aguja.closePath();
        this.t = new AffineTransform();
    }

    @Override
    public void paintComponent(Graphics g) {
        String kilometros = String.valueOf(Math.rint(this.distancia * 10.0) / 10.0);
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setPaint(Color.white);
        g2.setFont(new Font("TimesRoman", 0, 20));
        g2.drawString("0", 31, 243);
        g2.drawString("20", 12, 195);
        g2.drawString("40", 12, 144);
        g2.drawString("60", 28, 100);
        g2.drawString("80", 61, 59);
        g2.drawString("100", 102, 34);
        g2.drawString("120", 156, 24);
        g2.drawString("140", 206, 32);
        g2.drawString("160", 251, 56);
        g2.drawString("180", 284, 93);
        g2.drawString("200", 302, 140);
        g2.drawString("220", 301, 192);
        g2.drawString("240", 283, 241);
        g2.drawString("KM/H", 147, 198);
        g2.drawString(kilometros, 197 - g2.getFontMetrics().stringWidth(kilometros), 248);
        g2.drawString("km", 205, 248);
        g2.draw(this.cuadroDistancia);
        g2.translate(this.getWidth() / 2, this.getHeight() / 2);
        g2.draw(this.velocimetro);
        this.t.setToRotation(Math.toRadians(-30.0));
        g2.transform(this.t);
        g2.draw(this.segmentoLargo);
        double angulo = 1.0;
        while (angulo <= 12.0) {
            this.t.setToRotation(Math.toRadians(10.0));
            g2.transform(this.t);
            g2.draw(this.segmentoCorto);
            this.t.setToRotation(Math.toRadians(10.0));
            g2.transform(this.t);
            g2.draw(this.segmentoLargo);
            angulo += 1.0;
        }
        this.t.setToRotation(Math.toRadians(120.0 + this.velocidad));
        g2.transform(this.t);
        g2.setPaint(Color.red);
        g2.fill(this.aguja);
    }

    public void repintar() {
        this.velocidad = this.vehiculo.getVelocidad();
        this.distancia = this.vehiculo.getDistancia();
        this.repaint();
    }
}

