
package InterfazGrafica;

import javax.swing.JApplet;

import Coche.Coche;
import Coche.MonitorizarCoche;
import ControlAutomatico.*;

import java.text.*;

/**
 *
 * @author arturo
 */
public class Interfaz extends JApplet { //Rubén y Arturo

	Coche coche;
	ControlAutomatico controlAutomatico;
	Motor motor;
	Palanca palanca;
	DecimalFormat df = new DecimalFormat("#.##");
	private MonitorizarCoche monitor;

	private javax.swing.JToggleButton Acelerar;
	private javax.swing.JButton Arrancar;
	private javax.swing.JLabel Estado;
	private javax.swing.JToggleButton Freno;
	private javax.swing.JToggleButton Mantener;
	private javax.swing.JToggleButton Parar;
	private javax.swing.JToggleButton Reiniciar;
	private javax.swing.JButton Repostar;
	private javax.swing.JLabel VAutomatica;
	private javax.swing.JLabel deposito;
	private javax.swing.JLabel velocidad;

	public void ActualizarVista() {
		velocidad.setText("Velocidad: " + df.format(this.monitor.getVelocidad()) + " KM/h   ");
		VAutomatica.setText(
				"Velocidad automatica: " + df.format(this.controlAutomatico.getVelocidadAutomatica()) + " KM/h   ");
		int estado = this.controlAutomatico.getEstado();

		if (estado == 0) {
			Estado.setText("Acelerando");
		} else if (estado == 1) {
			Estado.setText("Manteniendo");
		} else if (estado == 2) {
			Estado.setText("Reiniciando");
		} else if (estado == 3) {
			Estado.setText("Apagado");
		} else if (estado == 4) {
			Estado.setText("Frenando");
		} else {
			System.out.println("error");
		}
		deposito.setText("Deposito: " + df.format(this.monitor.getCombustible()) + "   ");
	}

	@Override
	public void init() {

		try {
			for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
				if ("Nimbus".equals(info.getName())) {
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch (ClassNotFoundException ex) {
			java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (InstantiationException ex) {
			java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (IllegalAccessException ex) {
			java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		} catch (javax.swing.UnsupportedLookAndFeelException ex) {
			java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		}

		try {
			java.awt.EventQueue.invokeAndWait(new Runnable() {
				@Override
				public void run() {
					initComponents();
					setSize(550, 300);
				}
			});
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")

	private void initComponents() {

		this.coche = new Coche(this);
		this.monitor = new MonitorizarCoche(coche);
		this.motor = new Motor(this.coche, this.controlAutomatico);
		this.controlAutomatico = new ControlAutomatico(this.motor, this.coche);
		this.palanca = new Palanca(this.controlAutomatico);

		velocidad = new javax.swing.JLabel();
		Arrancar = new javax.swing.JButton();
		VAutomatica = new javax.swing.JLabel();
		Estado = new javax.swing.JLabel();
		Freno = new javax.swing.JToggleButton();
		deposito = new javax.swing.JLabel();
		Repostar = new javax.swing.JButton();
		Acelerar = new javax.swing.JToggleButton();
		Mantener = new javax.swing.JToggleButton();
		Parar = new javax.swing.JToggleButton();
		Reiniciar = new javax.swing.JToggleButton();

		controlAutomatico.inicarControl();

		velocidad.setText("Velocidad: 0 KM/h");

		Arrancar.setText("Arrancar");
		Arrancar.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				ArrancarActionPerformed(evt);
			}
		});

		VAutomatica.setText("Velocidad automatica: 0 KM/h");

		Estado.setText("Apagado");

		Freno.setText("Pisar freno");
		Freno.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				FrenoActionPerformed(evt);
			}
		});

		deposito.setText("Deposito: 1");

		Repostar.setText("Repostar");
		Repostar.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				RepostarActionPerformed(evt);
			}
		});

		Acelerar.setText("Acelerar");
		Acelerar.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				AcelerarActionPerformed(evt);
			}
		});

		Mantener.setText("Mantener");
		Mantener.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				MantenerActionPerformed(evt);
			}
		});

		Parar.setText("Parar");
		Parar.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				PararActionPerformed(evt);
			}
		});

		Reiniciar.setText("Reiniciar");
		Reiniciar.addActionListener(new java.awt.event.ActionListener() {
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				ReiniciarActionPerformed(evt);
			}
		});

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(layout.createSequentialGroup().addGap(33, 33, 33)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
								.addGroup(layout.createSequentialGroup().addComponent(Freno)
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
												javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
										.addComponent(Parar, javax.swing.GroupLayout.PREFERRED_SIZE, 100,
												javax.swing.GroupLayout.PREFERRED_SIZE)
										.addGap(105, 105, 105)
										.addComponent(Mantener, javax.swing.GroupLayout.PREFERRED_SIZE, 100,
												javax.swing.GroupLayout.PREFERRED_SIZE)
										.addGap(35, 35, 35))
								.addGroup(layout
										.createSequentialGroup().addComponent(velocidad).addGap(60, 60, 60)
										.addComponent(VAutomatica).addGap(91, 91, 91).addComponent(Estado)
										.addGap(53, 53, 53))
								.addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
										.addComponent(Arrancar, javax.swing.GroupLayout.PREFERRED_SIZE, 99,
												javax.swing.GroupLayout.PREFERRED_SIZE)
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
												javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
										.addGroup(layout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
												.addComponent(Acelerar, javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
												.addComponent(Reiniciar, javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
										.addGap(141, 141, 141))))
				.addGroup(layout.createSequentialGroup().addGap(50, 50, 50).addComponent(deposito).addGap(44, 44, 44)
						.addComponent(Repostar)
						.addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)));
		layout.setVerticalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(layout.createSequentialGroup().addGap(28, 28, 28)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(velocidad).addComponent(VAutomatica).addComponent(Estado))
						.addGap(44, 44, 44)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(Arrancar).addComponent(Acelerar))
						.addGap(18, 18, 18)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(Freno).addComponent(Mantener).addComponent(Parar))
						.addGap(18, 18, 18).addComponent(Reiniciar)
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
								javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(deposito).addComponent(Repostar))
						.addGap(54, 54, 54)));
	}

	private void ArrancarActionPerformed(java.awt.event.ActionEvent evt) {
		if (monitor.getEstadoMotor() == 0) {
			coche.arrancar();
			Arrancar.setText("Apagar");

		} else if (monitor.getEstadoMotor() == 1) {
			coche.pararMotor();
			controlAutomatico.apagarMotor();
			Arrancar.setText("Arrancar");

		} else {
			System.out.println("error");
		}
	}

	private void FrenoActionPerformed(java.awt.event.ActionEvent evt) {

		if (Freno.isSelected()) {
			motor.frenar();
		} else {
			motor.soltarFrenos();
		}
	}

	private void AcelerarActionPerformed(java.awt.event.ActionEvent evt) {
		palanca.moverPalanca(0);
		if (palanca.getPosicion() == 0) {
			Acelerar.setSelected(true);
			Parar.setSelected(false);
			Reiniciar.setSelected(false);
			Mantener.setSelected(false);
		} else {
			Acelerar.setSelected(false);
		}
	}

	private void MantenerActionPerformed(java.awt.event.ActionEvent evt) {
		palanca.moverPalanca(1);
		if (palanca.getPosicion() == 1) {
			Acelerar.setSelected(false);
			Parar.setSelected(false);
			Reiniciar.setSelected(false);
			Mantener.setSelected(true);
		} else {
			Mantener.setSelected(false);
		}
	}

	private void ReiniciarActionPerformed(java.awt.event.ActionEvent evt) {
		palanca.moverPalanca(2);
		if (palanca.getPosicion() == 2) {
			Acelerar.setSelected(false);
			Parar.setSelected(false);
			Reiniciar.setSelected(true);
			Mantener.setSelected(false);
		} else {
			Reiniciar.setSelected(false);
		}
	}

	private void PararActionPerformed(java.awt.event.ActionEvent evt) {
		palanca.moverPalanca(3);
		if (palanca.getPosicion() == 3) {
			Acelerar.setSelected(false);
			Parar.setSelected(true);
			Reiniciar.setSelected(false);
			Mantener.setSelected(false);
		} else {
			Parar.setSelected(false);
		}
	}

	private void RepostarActionPerformed(java.awt.event.ActionEvent evt) {
		if (monitor.getEstadoMotor() == 0 && monitor.getVelocidad() == 0) {
			coche.repostar();
		}
	}
}
