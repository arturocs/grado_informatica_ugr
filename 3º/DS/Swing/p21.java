import java.awt.*;

import javax.swing.JFrame;


public class p21 extends JFrame {

	/**
	 * @param args
	 */
	public p21(){
		setTitle("Programa test simple");
	    setSize(100,100);
	    Panel panelSuperior= new Panel();
	    panelSuperior.setLayout(new BorderLayout());
	    getContentPane().add(panelSuperior);//para acceder a JRootPane
	    Label etiquetaHola= new Label("Hola a todo el mundo!");
	    panelSuperior.add(etiquetaHola, BorderLayout.NORTH);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
      p21 marco= new p21();
      marco.setVisible(true);
	}

}
