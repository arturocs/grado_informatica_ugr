
public class main{
	
	public static void main (String [ ] args) {

	System.out.println("Enter something:");
	//String input = System.console().readLine();
	//int N=Integer.parseInt(input);
	int N = 20;	
	
	FactoriaCarreraCarretera fcc = new FactoriaCarreraCarretera(N);
	FactoriaCarreraMontaña fcm = new FactoriaCarreraMontaña(N);

	fcm.start();
	fcc.start();
	
	//input n
	//llamar a factoria montaña y carretera
	//llamar a eliminar bicis
	
	}
}