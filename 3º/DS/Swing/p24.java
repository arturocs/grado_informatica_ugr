import java.awt.*;

import javax.swing.*;


public class p24 extends JFrame {

	/**
	 * @param args
	 */
	public p24(){
	    setTitle("Aplicacion utilizando BoxLayout");
	    JPanel panelSuperior= new JPanel();
	    panelSuperior.setLayout(new BorderLayout());
	    getContentPane().add(panelSuperior);
	    JPanel ejeYPanel= createEjeYPanel();
	    panelSuperior.add(ejeYPanel, BorderLayout.CENTER);
	    JPanel ejeXPanel= createEjeXPanel();
	    panelSuperior.add(ejeXPanel, BorderLayout.SOUTH);
	}
	public JPanel createEjeYPanel(){
		  JPanel panel = new JPanel();
		  panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS) );
		  panel.setBackground(Color.lightGray);
		  //A\~nadir algunos componentes a este panel
		  panel.add(new JButton("Boton 1"));
		  panel.add(new TextArea("Esto es una area de texto"));
		  panel.add(new JCheckBox("Checkbox 1"));
		  return panel;
		}
	public JPanel createEjeXPanel(){
		  JPanel panel = new JPanel();
		  panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS) );
		  panel.setBackground(Color.gray);
		  //A\~nadir algunos componentes a este panel
		  panel.add(new JButton("Boton 1"));
		  panel.add(new TextArea("Esto es una area de texto"));
		  panel.add(new JCheckBox("Checkbox 1"));
		  return panel;
		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		p24 marcoPrincipal= new p24();
	    marcoPrincipal.pack();
	    marcoPrincipal.setVisible(true); 

	}

}
