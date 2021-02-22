public class Cliente {
	public static void main (String [ ] args) {
		
	Equipo A = new Equipo();
	VisitanteNombre vn=new VisitanteNombre();
	VisitantePrecio vp=new VisitantePrecio();
	
	for(ElementoEquipo a: A.elementos) {
		a.aceptar(vp);
		a.aceptar(vn);
	}
	
	
	
	System.out.println("Precio: " + vp.getPreciofinal());
	System.out.println("Nombres: "+ vn.getNombreequipo());
	
	}
}