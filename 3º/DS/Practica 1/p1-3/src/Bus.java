
public class Bus extends ElementoEquipo{
	public Bus(String nombre, double precio) {
		super(nombre);
		setPrecio(precio);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public double precioNeto() {
		return getPrecio();
	}
	
	@Override
	public void aceptar(VisitanteEquipo ve) {
		
		ve.VisitarBus(this);
		
	}

}
