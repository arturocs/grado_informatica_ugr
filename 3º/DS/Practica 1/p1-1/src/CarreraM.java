
public class CarreraM extends Carrera{

	public CarreraM(int n) {
		for(int i=0; i<n; i++) {
			//bicis[i]= new BiciC(TC.CARRETERA);
			bicis.add(new BiciM(TC.MONTANA));
		}
	}
	public void BorrarBicis() {
		for(int i=0; i<bicis.size()*0.2; i++) {
			bicis.remove(i);
		}
	}

	
}
