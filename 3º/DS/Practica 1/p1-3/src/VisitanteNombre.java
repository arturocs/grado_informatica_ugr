

public class VisitanteNombre extends VisitanteEquipo {
	public String nombreequipo="";
	
	public String getNombreequipo() {
		return nombreequipo;
	}
	
	@Override
	public void VisitarDisco(Disco d) {
		nombreequipo+=d.nombre()+" ";
		
	}

	@Override
	public void VisitarTarjeta(Tarjeta t) {
		nombreequipo+=t.nombre()+" ";
		
	}

	@Override
	public void VisitarBus(Bus b) {
		nombreequipo+=b.nombre()+" ";
		
	}

}
