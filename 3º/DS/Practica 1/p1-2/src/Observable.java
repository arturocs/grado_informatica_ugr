

public abstract class Observable {

	private Observador observador;
	
	public void incluirObservador(Observador o) {
		observador = o;
	}
	
	public void notificarObservador(int t) {
		observador.manejarEvento(t);
	}
}

