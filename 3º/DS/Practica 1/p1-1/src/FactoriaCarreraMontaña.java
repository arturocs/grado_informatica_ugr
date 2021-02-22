
public class FactoriaCarreraMontaña extends Thread implements FactoriaCarrera {

	int n;
	
	 public FactoriaCarreraMontaña(int n) {
		this.n = n;
	}

	public void run () {
		 CarreraM carreram = crearCarrera(n); 
		 for (int i=0;i<60;i++) {
			 System.out.println("carreram: " + i+"s");
			 if(i == 30) {
				 carreram.BorrarBicis();
			 }
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		 }
		 System.out.println("fin carreram con " + carreram.bicis.size() + " bicis");
	 }
	
	@Override
	public CarreraM crearCarrera(int n) {
		CarreraM carreram = new CarreraM(n);
		return carreram;
		
	}

}
