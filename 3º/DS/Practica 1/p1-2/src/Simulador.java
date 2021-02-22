
import java.util.Random;


public class Simulador extends Thread{

	private int t_1;
	private int t_2;
	private int temperatura;
	public ObservableTemperatura Ob = new ObservableTemperatura();
	
	public Simulador(int min, int max) {
		t_1	= min;
		t_2 = max;
	}
	
	public void addObservador(Observador o) {
		Ob.incluirObservador(o);
		
	}
	
	public int getTemp() {
		return temperatura;
	}
	
	public void run() {
		while(true) {
			Random r = new Random(System.currentTimeMillis());
			temperatura = r.nextInt(t_2)+t_1;
			System.out.println("Temperatura actual: " + temperatura);
			Ob.notificarObservador(temperatura);
			try {
				Thread.currentThread();
				Thread.sleep(15000);
			}catch(java.lang.InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}