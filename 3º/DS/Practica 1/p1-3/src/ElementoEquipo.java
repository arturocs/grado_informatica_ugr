
public abstract class ElementoEquipo {
	private String nombre;
	private double precio;
	public ElementoEquipo(String nombre){
		this.nombre= nombre;
	}
	public String nombre(){
		return nombre;
	}

	public double getPrecio() {
		return precio;
	}
	public void setPrecio(double precio) {
		this.precio = precio;
	}
	//public abstract double potencia();
	public abstract double precioNeto();
	//public abstract double precioConDescuento();
	public abstract void aceptar(VisitanteEquipo ve);
	@Override
	public String toString() {
		return "ElementoEquipo [nombre=" + nombre + ", precio=" + precio + "]";
	}
	
	
}
