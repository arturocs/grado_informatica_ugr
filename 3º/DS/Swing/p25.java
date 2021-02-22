import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
public class p25 extends JFrame {
    public p25(){
    	setTitle("Aplicacion con JLabel");
        setSize(300, 200);
        JPanel panelSuperior= new JPanel();
        panelSuperior.setLayout(new GridLayout(2, 2));
        getContentPane().add( panelSuperior);
        JLabel etiqueta1= new JLabel();
        etiqueta1.setText("Etiqueta1");
        panelSuperior.add( etiqueta1 );
        JLabel etiqueta2= new JLabel("Etiqueta2");
        etiqueta2.setFont(new Font("Helvetica",Font.BOLD,18));
        panelSuperior.add( etiqueta2 );
         Icon imagen = new ImageIcon( "image002.gif");
        JLabel etiqueta3= new JLabel ("Etiqueta3",imagen,SwingConstants.CENTER);
        etiqueta3.setVerticalTextPosition( SwingConstants.TOP);
        panelSuperior.add( etiqueta3 );
        JLabel etiqueta4= new JLabel ("Etiqueta4",SwingConstants.RIGHT);
        panelSuperior.add(etiqueta4);
        //Anadir una clase an\'onima para terminar el programa
        this.addWindowListener (new WindowAdapter()
        { 
            public void windowClosing(WindowEvent e)
            {
              System.exit(0);
            }
         }); //Acaba el escuchador de Windows
      }
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 p25 marcoPrincipal= new p25();
		 marcoPrincipal.setVisible(true); 
	}

}
