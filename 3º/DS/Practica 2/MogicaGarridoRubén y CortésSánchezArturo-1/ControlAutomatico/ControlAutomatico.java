
package ControlAutomatico;

import ControlAutomatico.Motor;
import Coche.Coche;
import Coche.MonitorizarCoche;

public class ControlAutomatico extends Thread { //Rubén
	private Motor motor;
	private MonitorizarCoche monitor;
	//private Coche coche;
	private int estado;
	private int estadoAnterior;
	private double velocidadAutomatica;
	private boolean salir;

	public ControlAutomatico(Motor motor, Coche coche) {
		this.motor = motor;
		//this.coche = coche;
		this.estado = 3;
		this.estadoAnterior = 3;
		this.velocidadAutomatica = 0;
		this.monitor=new MonitorizarCoche(coche);
	}

	public double getVelocidadAutomatica() {
		return this.velocidadAutomatica;
	}

	public int getEstado() {
		return this.estado;
	}

	public void setVelocidadAutomatica() {
		this.velocidadAutomatica = this.monitor.getVelocidad();
	}

	public void inicarControl() {
		this.salir = false;
		if (!this.isAlive()) {
			this.start();
		}
	}

	public void salirHebra() {
		this.salir = true;
	}

	public void apagarMotor() {
		this.velocidadAutomatica = 0;
	}

	public void EstadoAnterior() {
		if (this.estadoAnterior == 0) {
			this.estado = this.estadoAnterior;
		} else {
			this.estado = 0;
		}
	}

	public void cambiarEstado(int cambio) {
		if (monitor.getEstadoMotor() == 1) {
			this.estadoAnterior = this.estado;
			this.estado = cambio;
		}
	}

	public void mantener() {
		if ((this.monitor.getVelocidad() - this.velocidadAutomatica) > 0) {
			this.motor.decelerar((this.monitor.getVelocidad() - this.velocidadAutomatica) * 5);
		} else if ((this.monitor.getVelocidad() - this.velocidadAutomatica) < 0) {
			this.motor.acelerar((this.monitor.getVelocidad() - this.velocidadAutomatica) * -5);
		}
	}

	@Override
	public void run() {
		while (!salir) {
			if (estado == 0) {
				while (estado == 0) {
					motor.acelerar(5);
					try {
						sleep(100);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			} else if (estado == 1) {
				while (estado == 1) {
					mantener();
					try {
						sleep(100);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			} else if (estado == 2) {
				while (estado == 2) {
					do {
						motor.acelerar(5);
						try {
							sleep(100);
						} catch (InterruptedException e) {
							e.printStackTrace();
						}
					} while ((velocidadAutomatica >= monitor.getVelocidad()) && (estado == 2));
					if (estado == 2) {
						cambiarEstado(1);
					}
				}
			} else if (estado == 3) {
				motor.apagar();
				while (estado == 3) {
					try {
						sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			} else if (estado == 4) {
				motor.apagar();
				while (estado == 4) {
					try {
						sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}

			} else {
				System.out.println("error");
			}
		}
	}
}