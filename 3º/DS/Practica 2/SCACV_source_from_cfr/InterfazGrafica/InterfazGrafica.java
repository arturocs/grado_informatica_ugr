/*
 * Decompiled with CFR 0_123.
 */
package InterfazGrafica;

import ControlAutomatico.Acelerador;
import ControlAutomatico.CalculadorVelocidad;
import ControlAutomatico.ControlAutomatico;
import ControlAutomatico.Freno;
import ControlAutomatico.Palanca;
import InterfazGrafica.PanelAcelerador;
import InterfazGrafica.PanelControlAutomatico;
import InterfazGrafica.PanelPalanca;
import InterfazGrafica.PanelVelocimetro;
import SimuladorVehiculo.Vehiculo;
import java.awt.Color;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.LayoutManager;
import javax.swing.JApplet;

public class InterfazGrafica
extends JApplet {
    PanelPalanca panelPalanca;
    PanelVelocimetro panelVelocimetro;
    PanelAcelerador panelAcelerador;
    PanelControlAutomatico panelControlAutomatico;
    Vehiculo vehiculo;
    ControlAutomatico controlAutomatico;
    Acelerador acelerador;
    CalculadorVelocidad calculadorVelocidad;
    Palanca palanca;
    Freno freno;

    @Override
    public void init() {
        this.vehiculo = new Vehiculo(this);
        this.acelerador = new Acelerador(this.vehiculo);
        this.calculadorVelocidad = new CalculadorVelocidad(this.vehiculo);
        this.controlAutomatico = new ControlAutomatico(this.acelerador, this.calculadorVelocidad);
        this.palanca = new Palanca(this.controlAutomatico);
        this.freno = new Freno(this.vehiculo, this.controlAutomatico);
        this.panelPalanca = new PanelPalanca(this.vehiculo, this.palanca);
        this.panelVelocimetro = new PanelVelocimetro(this.vehiculo);
        this.panelAcelerador = new PanelAcelerador(this.vehiculo);
        this.panelControlAutomatico = new PanelControlAutomatico(this.vehiculo, this.controlAutomatico, this.freno);
        GridBagLayout gridbag = new GridBagLayout();
        GridBagConstraints pos = new GridBagConstraints();
        pos.fill = 1;
        this.resize(500, 500);
        this.setBackground(Color.BLACK);
        this.setLayout(gridbag);
        pos.gridx = 0;
        pos.gridy = 0;
        pos.gridwidth = 1;
        pos.gridheight = 1;
        pos.weightx = 2.0;
        pos.weighty = 2.0;
        gridbag.setConstraints(this.panelVelocimetro, pos);
        this.add(this.panelVelocimetro);
        pos.gridx = 1;
        pos.gridy = 0;
        pos.gridwidth = 1;
        pos.gridheight = 1;
        pos.weightx = 1.0;
        pos.weighty = 2.0;
        gridbag.setConstraints(this.panelControlAutomatico, pos);
        this.add(this.panelControlAutomatico);
        pos.gridx = 0;
        pos.gridy = 1;
        pos.gridwidth = 1;
        pos.gridheight = 1;
        pos.weightx = 2.0;
        pos.weighty = 1.0;
        gridbag.setConstraints(this.panelAcelerador, pos);
        this.add(this.panelAcelerador);
        pos.gridx = 1;
        pos.gridy = 1;
        pos.gridwidth = 1;
        pos.gridheight = 1;
        pos.weightx = 1.0;
        pos.weighty = 1.0;
        gridbag.setConstraints(this.panelPalanca, pos);
        this.add(this.panelPalanca);
        this.validate();
    }

    public void repintar() {
        this.panelVelocimetro.repintar();
        this.panelAcelerador.repintar();
        this.panelControlAutomatico.repintar();
        this.panelPalanca.repintar();
    }
}

