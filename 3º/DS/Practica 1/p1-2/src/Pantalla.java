
import java.awt.*;
//import java.awt.Font;
//import java.awt.event.WindowAdapter;
//import java.awt.event.WindowEvent;

import javax.swing.*;

public class Pantalla extends JFrame implements Observador, Runnable {
	
	private	static Pantalla INSTANCE = new Pantalla();
	private static double 	fahrenheit, celsius;
	private static JLabel cel, far, temp;
	private static JPanel 	panel;
	public  static Thread 	t;
	
	
	private Pantalla() {
		t = new Thread(this, "pantalla");
		
		setTitle("Simulador");
		setSize(300,100); 
		
		panel = new JPanel();
		temp = new JLabel("Temperaturas: ");
		panel.add(temp, JLabel.CENTER);
		getContentPane().add(panel, BorderLayout.NORTH);
		
		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		cel = new JLabel();
		cel.setAlignmentX(CENTER_ALIGNMENT);
		panel.add(cel);
		
		far = new JLabel();
		far.setAlignmentX(CENTER_ALIGNMENT);
		panel.add(far);
		
		getContentPane().add(panel, BorderLayout.CENTER);
		
	}
	
	
	public static Pantalla getInstancia() {
		return INSTANCE;
	}
	
	public static void refrescarPantalla() {
		cel.setText("celsius: " 	+ String.valueOf(celsius) 	+ "ºC");
		far.setText("fahrenheit: "+ String.valueOf(fahrenheit)+ "ºF");
	}

	@Override
	public void manejarEvento(int temp) {
		celsius = temp;
		fahrenheit = celsius*1.8 + 32;
		fahrenheit = Math.floor(fahrenheit * 100) / 100;

	}

	@Override
	public void run() {
		while(true) {
			refrescarPantalla();			
		}
	}

}
