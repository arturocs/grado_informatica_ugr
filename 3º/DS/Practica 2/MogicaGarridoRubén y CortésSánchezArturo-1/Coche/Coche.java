
package Coche;

import InterfazGrafica.Interfaz;

public class Coche extends Thread { //Arturo
	protected double velocidad;
	protected double combustible;
	protected int estado;
	private double acelerador;
	private double frenado;
	private boolean parar;
	private Interfaz interfaz;

	@Override
	public String toString() {
		return "Coche [velocidad=" + velocidad + ", combustible=" + combustible + ", estado=" + estado + ", acelerador="
				+ acelerador + ", frenado=" + frenado + ", parar=" + parar + ", interfaz=" + interfaz + "]";
	}

	public Coche(Interfaz interfaz) {
		this.interfaz = interfaz;
		this.velocidad = 0;
		this.acelerador = 1;
		this.combustible = 100;
		this.estado = 0;
		this.frenado = 0;
		this.parar = false;
	}
	
	public void repostar() {
		this.combustible = 100;
	}

	public void pararAcelerador() {
		this.acelerador = 0;
	}

	public void frenar(int c) {
		this.frenado = c;
	}

	public void soltarFrenos() {
		this.frenado = 0;
	}

	public void aumentarAcelerador(double aceleracion) {
		if (this.acelerador < 100) {
			this.acelerador += aceleracion;
		} else if (this.acelerador > 100) {
			this.acelerador = 100;
		}
	}

	public void disminuirAcelerador(double aceleracion) {
		if (this.acelerador > 0) {
			this.acelerador -= aceleracion;
		} else if (this.acelerador < 0) {
			this.acelerador = 0;
		}
	}

	public void arrancar() {
		this.estado = 1;
		this.parar = false;
		if (!this.isAlive()) {
			this.start();
		}
	}

	public void pararMotor() {
		this.estado = 0;
	}

	public void pararCoche() {
		this.estado = 0;
		this.parar = true;
		this.interfaz.ActualizarVista();
	}

	@Override
	public void run() {
		while (!this.parar) {

			this.velocidad += (this.acelerador / 100) - 0.3 - this.frenado;
			this.combustible -= this.acelerador / 10000;
			
			if (this.velocidad < 0) {
				this.velocidad = 0;
			}
			if (this.combustible < 0) {
				this.combustible = 0;
			}
			this.interfaz.ActualizarVista();
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

	}
}
