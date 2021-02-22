
public class VisitantePrecio extends VisitanteEquipo {
	public double preciofinal=0;
	
	public double getPreciofinal() {
		return preciofinal;
	}
	
	@Override
	public void VisitarDisco(Disco d) {
		preciofinal+=d.precioNeto();
		
	}

	@Override
	public void VisitarTarjeta(Tarjeta t) {
		preciofinal+=t.precioNeto();
		
	}

	@Override
	public void VisitarBus(Bus b) {
		preciofinal+=b.precioNeto();
		
	}




}
