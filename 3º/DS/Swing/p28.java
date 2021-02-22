import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class p28 extends JFrame {
	/**
	 * @param args
	 */
	public p28(){
	 JPanel panelSuperior= new JPanel();
     panelSuperior.setLayout(new FlowLayout());
	 getContentPane().add( panelSuperior);
	 JButton boton1= new JButton("Boton 1");
	 boton1.setMaximumSize(new Dimension(100, 25));
	 panelSuperior.add(boton1);
	 JPanel subPanel= new JPanel();
	 subPanel.setLayout(new BoxLayout(subPanel,BoxLayout.Y_AXIS));
	 subPanel.setPreferredSize(new Dimension(200,250));
	 subPanel.setBorder(new TitledBorder(
	   new EtchedBorder(), "Casillas verificacion"));
		   panelSuperior.add(subPanel);
	 JCheckBox casilla1= new JCheckBox("Casilla 1");
	 subPanel.add(casilla1);
	 JCheckBox casilla2= new JCheckBox("Casilla 2");
	 subPanel.add(casilla2);
	 JCheckBox casilla3= new JCheckBox("Casilla 3");
	 subPanel.add(casilla3);
	 JCheckBox casilla4= new JCheckBox("Casilla 4");
	 subPanel.add(casilla4);
	 //creaci\'on de un panel de texto
	 JPanel panelTexto= new JPanel( new BorderLayout() );
	 panelTexto.setBorder(new TitledBorder(
		new EtchedBorder(), "Area de Texto"));
	 JTextArea area= new JTextArea(" ", 10, 30);
	 area.setPreferredSize(new Dimension( 170, 130) );
	 panelTexto.add( area );
	 panelSuperior.add(panelTexto);
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
		p28 marco= new p28();
		marco.pack();
		marco.setVisible(true);
	}

}
