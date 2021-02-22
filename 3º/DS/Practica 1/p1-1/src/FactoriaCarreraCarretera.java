
public class FactoriaCarreraCarretera extends Thread implements FactoriaCarrera {

	int n;
	
	public FactoriaCarreraCarretera(int n) {
		this.n = n;
	}

	public void run () {
		 CarreraC carrerac = crearCarrera(n); 
		 for (int i=0;i<60;i++) {
			 System.out.println("carrerac: " + i+"s");
			 if(i == 30) {
				 carrerac.BorrarBicis();
			 }
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		 }
		 System.out.println("fin carrerac con " + carrerac.bicis.size() + " bicis");
	 }
	
	@Override
	public CarreraC crearCarrera(int n) {
		CarreraC carrerac = new CarreraC(n);
		return carrerac;

		
	}

}
