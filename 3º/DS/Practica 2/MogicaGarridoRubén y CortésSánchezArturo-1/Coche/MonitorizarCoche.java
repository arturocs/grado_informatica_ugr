package Coche;

public class MonitorizarCoche { //Arturo
	private Coche coche;
	
	public MonitorizarCoche(Coche coche) {
		super();
		this.coche = coche;
	}

	public double getCombustible() {
		return this.coche.combustible;
	}

	public double getVelocidad() {
		return this.coche.velocidad;
	}

	public int getEstadoMotor() {
		return this.coche.estado;
	}

	
}
