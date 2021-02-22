
public class CarreraC extends Carrera{

	public CarreraC(int n) {
		for(int i=0; i<n; i++) {
			//bicis.add(new BiciM(TC.CARRETERA));
			bicis.add(new BiciC(TC.CARRETERA));
		}
	}
	public void BorrarBicis() {
		for(int i=0; i<bicis.size()*0.1; i++) {
			bicis.remove(i);
		}
	}

}