/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Freno;
import InterfazGrafica.ControlMouseAdapter;
import InterfazGrafica.ControlMouseMotionAdapter;
import SimuladorVehiculo.Vehiculo;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Paint;
import java.awt.Shape;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;
import javax.swing.JPanel;

public class PanelControlAutomatico
extends JPanel {
    private RoundRectangle2D marco;
    private RoundRectangle2D marcoEstado;
    private RoundRectangle2D botonFrenar;
    private RoundRectangle2D botonArrancar;
    private Rectangle2D cuadro;
    private final String[] tablaEstado;
    private int estado;
    private double velocidadAutomatica;
    private boolean arrancado;
    private Vehiculo vehiculo;
    private ControlAutomatico controlAutomatico;
    private Freno freno;

    public PanelControlAutomatico(Vehiculo vehiculo, ControlAutomatico controlAutomatico, Freno freno) {
        this.vehiculo = vehiculo;
        this.controlAutomatico = controlAutomatico;
        this.freno = freno;
        this.setSize(170, 330);
        this.estado = 3;
        this.velocidadAutomatica = 0.0;
        this.tablaEstado = new String[5];
        this.tablaEstado[0] = "Acelerando";
        this.tablaEstado[1] = "Manteniendo";
        this.tablaEstado[2] = "Reinciando";
        this.tablaEstado[3] = "Apagado";
        this.tablaEstado[4] = "Frenando";
        this.marco = new RoundRectangle2D.Double(3.0, 3.0, this.getWidth() - 6, 225.0, 15.0, 15.0);
        this.marcoEstado = new RoundRectangle2D.Double(10.0, 10.0, this.getWidth() - 20, 30.0, 10.0, 10.0);
        this.botonArrancar = new RoundRectangle2D.Double(25.0, 240.0, this.getWidth() - 50, 35.0, 10.0, 10.0);
        this.botonFrenar = new RoundRectangle2D.Double(25.0, 290.0, this.getWidth() - 50, 35.0, 10.0, 10.0);
        this.cuadro = new Rectangle2D.Double(60.0, 80.0, 45.0, 20.0);
        this.setBackground(new Color(0, 0, 102));
        this.addMouseListener(new ControlMouseAdapter(this, vehiculo, controlAutomatico, freno));
        this.addMouseMotionListener(new ControlMouseMotionAdapter(this));
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setPaint(Color.blue);
        g2.fill(this.marcoEstado);
        g2.setPaint(Color.yellow);
        g2.fill(this.botonFrenar);
        g2.setPaint(Color.white);
        g2.draw(this.botonFrenar);
        g2.draw(this.marcoEstado);
        g2.draw(this.marco);
        g2.draw(this.cuadro);
        g2.setFont(new Font("TimesRoman", 0, 16));
        g2.drawString("Velocidad Autom\u00e1tica", 15, 70);
        g2.drawString(String.valueOf(Math.round(this.velocidadAutomatica)), 78, 96);
        g2.setFont(new Font("TimesRoman", 0, 22));
        this.vehiculo.getClass();
        if (this.vehiculo.getEstadoMotor() == 1) {
            g2.drawString(this.tablaEstado[this.estado], 24, 35);
            g2.setPaint(Color.green);
            g2.fill(this.botonArrancar);
            g2.setPaint(Color.black);
            g2.drawString("Apagar", 44, 265);
        } else {
            g2.setPaint(Color.red);
            g2.fill(this.botonArrancar);
            g2.setPaint(Color.black);
            g2.drawString("Arrancar", 44, 265);
        }
        if (this.estado != 4) {
            g2.drawString("Pisar Freno", 37, 315);
        } else {
            g2.drawString("Soltar Freno", 34, 315);
        }
        g2.setPaint(Color.white);
        g2.draw(this.botonArrancar);
    }

    public void repintar() {
        this.velocidadAutomatica = this.controlAutomatico.getVelocidadAutomatica();
        this.estado = this.controlAutomatico.getEstado();
        this.repaint();
    }
}

