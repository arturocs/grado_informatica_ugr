
public class main {

	public static void main(String[] args) {
		Simulador sim;
		Pantalla pan;
		int t_1=-10, t_2=40;
		
		
		sim = new Simulador(t_1, t_2);	
		pan = Pantalla.getInstancia();	
		pan.setVisible(true);
		
		sim.addObservador(pan);	
		sim.start();	
		System.out.println("simulacion");
		Pantalla.t.start();
	}

}
