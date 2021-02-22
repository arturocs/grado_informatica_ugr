
package ControlAutomatico;

import Coche.Coche;
import ControlAutomatico.ControlAutomatico;

public class Motor { //Ruben

	private Coche coche;
	private ControlAutomatico controlAutomatico;
	private int estado;

	public Motor(Coche coche, ControlAutomatico controlAutomatico) {
		this.coche = coche;
		this.controlAutomatico = controlAutomatico;
		this.estado = 5;
	}
	
	@Override
	public String toString() {
		return "Motor [coche=" + coche + ", controlAutomatico=" + controlAutomatico + ", estado=" + estado + "]";
	}


	public int getEstado() {
		return this.estado;
	}

	void setEstado() {
		if(this.estado  == 5) {
			this.estado =4;
		}else {
			this.estado = 5;
		}
		
		this.controlAutomatico.cambiarEstado(this.estado);
	}

	void acelerar(double a) {
		this.coche.aumentarAcelerador(a);
	}

	void decelerar(double a) {
		this.coche.disminuirAcelerador(a);
	}

	void apagar() {
		this.coche.pararAcelerador();
	}

	public void frenar() {
		this.estado = 4;
		this.controlAutomatico.cambiarEstado(4);
		this.coche.frenar(5);
	}

	public void soltarFrenos() {
		this.estado = 5;
		this.controlAutomatico.EstadoAnterior();
		this.coche.soltarFrenos();
	}
}
