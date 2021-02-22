import java.awt.*;

import javax.swing.JFrame;


public class p23 extends JFrame {

	/**
	 * @param args
	 */
	public p23(){
     super();
	 setSize( 200, 200);
	 setLayout( new BorderLayout() );
	 add( new Button("Norte"), BorderLayout.NORTH);
	 add( new Button("Sur"), BorderLayout.SOUTH);
	 add( new Button("Este"), BorderLayout.EAST);
	 add( new Button("Oeste"), BorderLayout.WEST);
	 add( new Button("Centro"), BorderLayout.CENTER);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		p23 marco= new p23();
	      marco.setVisible(true);
	}

}
