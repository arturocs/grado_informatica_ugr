//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Cliente {

	public static void main(String[] args) {
		
		String buferRecepcion;	
		String user;
		String password;
		String codigo;
		// Nombre del host donde se ejecuta el servidor:
		String host="localhost";
		// Puerto en el que espera el servidor:
		int port=8989;
		
		// Socket para la conexión TCP
		Socket socketServicio=null;
		
		try {
			System.out.println("\nIntroduce el usuario\n");
			user = System.console().readLine();
			System.out.println("\nIntroduce la contraaseña\n");
			password = System.console().readLine();

			socketServicio=new Socket (host,port);
			InputStream inputStream = socketServicio.getInputStream();
			OutputStream outputStream = socketServicio.getOutputStream();

			//buferEnvio="Al monte del volcán debes ir sin demora";

			PrintWriter outPrinter = new PrintWriter(outputStream, true);
			String s=new String(user+password);
			outPrinter.println(s);
			outPrinter.flush();

			

			BufferedReader inReader = new BufferedReader(new InputStreamReader(inputStream));
            buferRecepcion = inReader.readLine();

            System.out.println("\nRecibido: " + buferRecepcion + "\n");
			if(buferRecepcion.equals("1")){
				System.out.println("\nIntroduce codigo\n");
				codigo = System.console().readLine();

				outPrinter = new PrintWriter(outputStream, true);
				outPrinter.println(codigo);

				inReader = new BufferedReader(new InputStreamReader(inputStream));
				buferRecepcion = inReader.readLine();// recibir confirmacion de codigo
				if(buferRecepcion.equals("2")){
					System.out.print("Autenticacion finalizada con exito "+ buferRecepcion+"\n");
				}
				else{
					System.out.print("Codigo erroneo "+ buferRecepcion+"\n");
				}

			}
			else{
				System.out.println("\nUsuario o contraseña incorrectos\n");
			}
			
            socketServicio.close();

			// Excepciones:
		} catch (UnknownHostException e) {
			System.err.println("Error: Nombre de host no encontrado.");
		} catch (IOException e) {
			System.err.println("Error de entrada/salida al abrir el socket.");
		}
	}
}
