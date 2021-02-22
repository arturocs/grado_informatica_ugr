
public abstract class Bicicleta {
	TC tipo;
	public Bicicleta(TC tipo) {
		this.tipo=tipo;
	}
	public TC getTipo() {
		return tipo;
	}
	public void setTipo(TC tipo) {
		this.tipo = tipo;
	}
	@Override
	public String toString() {
		return "Bicicleta " + tipo ;
	}
	
	
}
