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
import java.net.DatagramSocket;		
import java.net.DatagramPacket;		
import java.net.InetAddress;

public class YodafyClienteUDP {

	public static void main(String[] args) {
		
        byte[] buferEnvio = new byte[256];
        byte[] buferRecepcion = new byte[256];
		DatagramPacket paquete;
		InetAddress direccion;
		// Puerto en el que espera el servidor:
		int port=8989;

		String mensaje;

		try {
			//////////////////////////////////////////////////////
			DatagramSocket socket = new DatagramSocket();
			//////////////////////////////////////////////////////			
			direccion = InetAddress.getByName("localhost");
			buferEnvio="Al monte del volcán debes ir sin demora".getBytes();
			paquete = new DatagramPacket(buferEnvio, buferEnvio.length, direccion, port);
			socket.send(paquete);
			paquete = new DatagramPacket(buferRecepcion, buferRecepcion.length);
			socket.receive(paquete);
			mensaje = new String(paquete.getData());

			
			System.out.println("\nRecibido: " + mensaje + "\n");
			socket.close();

			// Excepciones:
		} catch (UnknownHostException e) {
			System.err.println("Error: Nombre de host no encontrado.");
		} catch (IOException e) {
			System.err.println("Error de entrada/salida al abrir el socket.");
		}
	}
}
