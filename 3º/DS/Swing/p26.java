import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class p26 extends JFrame implements ActionListener {
    private int contadorI=0;
    private JButton boton=null;
	
	public p26(){
    	setTitle("Aplicacion para implementar un ActionListener");
        JPanel panelSuperior= new JPanel();
        panelSuperior.setLayout(new FlowLayout());
        panelSuperior.setPreferredSize(new Dimension(300,200));
        getContentPane().add(panelSuperior);
        boton= new JButton("Pulsa me");
        panelSuperior.add(boton);
        //Aadir un "action listener" al boton
        boton.addActionListener( this );
        this.addWindowListener (new WindowAdapter()
        { 
          public void windowClosing(WindowEvent e)
          {
        	  System.exit(0);
          }
        });
    }
	@Override
	public void actionPerformed(ActionEvent event) {
		// TODO Auto-generated method stub
	  if (event.getSource() == boton){
		     contadorI++;
		     boton.setText("Pulsado "+contadorI+" veces");
		     System.out.println("Click");
		     pack();
		  }
	}
	public static void main(String args[]){
		p26 marco= new p26();
		marco.pack();
		marco.setVisible(true);
	}

}
