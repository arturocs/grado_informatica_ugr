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

public class App {

	public static void main(String[] args) {
		
		//String buferEnvio;
		//int bytesLeidos=0;
		String buferRecepcion;	
		// Nombre del host donde se ejecuta el servidor:
		String host="localhost";
		// Puerto en el que espera el servidor:
		int port=9898;
		
		// Socket para la conexión TCP
		Socket socketServicio=null;
		
		try {
			while(true){
			socketServicio=new Socket (host,port);
			InputStream inputStream = socketServicio.getInputStream();
			//OutputStream outputStream = socketServicio.getOutputStream();

			//buferEnvio="Al monte del volcán debes ir sin demora";

			//PrintWriter outPrinter = new PrintWriter(outputStream, true);
			//outPrinter.println(buferEnvio);

			//outPrinter.flush();

			BufferedReader inReader = new BufferedReader(new InputStreamReader(inputStream));
            buferRecepcion = inReader.readLine();

            System.out.println("\nRecibido: " + buferRecepcion + "\n");

			}
          //  socketServicio.close();

			// Excepciones:
		} catch (UnknownHostException e) {
			System.err.println("Error: Nombre de host no encontrado.");
		} catch (IOException e) {
			System.err.println("Error de entrada/salida al abrir el socket.");
		}
	}
}
