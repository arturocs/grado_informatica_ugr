import java.util.ArrayList;

public class Equipo {
	public ArrayList<ElementoEquipo> elementos = new ArrayList<ElementoEquipo>();

	public Equipo() {
		elementos.add(new Bus("bus",10));
		elementos.add(new Tarjeta("tarjeta",20));
		elementos.add(new Disco("Disco",30));
	}
	
}
