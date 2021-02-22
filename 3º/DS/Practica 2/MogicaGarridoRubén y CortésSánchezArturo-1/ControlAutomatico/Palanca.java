
package ControlAutomatico;

import ControlAutomatico.ControlAutomatico;

public class Palanca { //Rubén
	
    private ControlAutomatico controlAutomatico;
    private int posicion;
    

	public Palanca(ControlAutomatico controlAutomatico) {
        this.controlAutomatico = controlAutomatico;
        this.posicion = 3;
    }
    
    @Override
	public String toString() {
		return "Palanca [controlAutomatico=" + controlAutomatico + ", posicion=" + posicion + "]";
	}

	
    public void setPalanca(int cambio) {
        this.posicion = cambio;
    }
    
    public int getPosicion() {
        return this.posicion;
    }

    public void moverPalanca(int posicion) {
    	if (posicion == 0) {
            this.controlAutomatico.cambiarEstado(posicion);
            this.posicion = posicion;
        } else if (posicion == 1 && this.controlAutomatico.getEstado() == 0) {
            this.controlAutomatico.setVelocidadAutomatica();
            this.controlAutomatico.cambiarEstado(posicion);
            this.posicion = posicion;
        } else if (posicion == 2 && this.controlAutomatico.getEstado() == 3 && this.controlAutomatico.getVelocidadAutomatica() > 0) {
            this.controlAutomatico.cambiarEstado(posicion);
            this.posicion = posicion;
        } else if (posicion == 3 && this.controlAutomatico.getEstado() != 0) {
            this.controlAutomatico.cambiarEstado(posicion);
            this.posicion = posicion;
        } else if (posicion == 0) {
            this.controlAutomatico.cambiarEstado(posicion);
            this.posicion = posicion;
        } 
    }
}

