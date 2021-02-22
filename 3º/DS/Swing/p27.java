import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class p27 extends JFrame {

	/**
	 * @param args
	 */
	public p27(){
		setTitle("Aplicacion utilizando ToggleButton");
	    JPanel panelSuperior= new JPanel();
	    panelSuperior.setLayout( new FlowLayout() );
	    getContentPane().add( panelSuperior );
	    JToggleButton boton1= new JToggleButton("Boton 1",true);
	    panelSuperior.add(boton1);
	    JToggleButton boton2= new JToggleButton("Boton 2",false);
	    panelSuperior.add(boton2);
	    JToggleButton boton3= new JToggleButton("Boton 3",false);
	    panelSuperior.add(boton3);
	    //Agrupar los botones, de tal forma que interacciones entre si
	    ButtonGroup grupoBotones= new ButtonGroup();
	    grupoBotones.add(boton1);
	    grupoBotones.add(boton2);
	    grupoBotones.add(boton3);
	  //Aadir una clase an\'onima para terminar el programa
	    this.addWindowListener (new WindowAdapter()
        { 
          public void windowClosing(WindowEvent e)
          {
        	  System.exit(0);
          }
        });
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		p27 marco= new p27();
		marco.pack();
		marco.setVisible(true);
	}

}
