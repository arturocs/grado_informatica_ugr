import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.DatagramSocket;		
import java.net.DatagramPacket;		
import java.net.InetAddress;

//
// YodafyServidorIterativo
// (CC) jjramos, 2012
//
public class YodafyServidorIterativo {

	public static void main(String[] args) {
		DatagramSocket socketServidor;

		InetAddress direccion;
		DatagramPacket paquete;
		byte[] bufer = new byte[256];
		DatagramSocket socket;
		// Puerto de escucha
		String mensaje;
		int port=8989;
		// array de bytes auxiliar para recibir o enviar datos.
		// byte []buffer=new byte[256];
		// Número de bytes leídos
		//int bytesLeidos=0;
		
		try {
			// Abrimos el socket en modo pasivo, escuchando el en puerto indicado por "port"
			//////////////////////////////////////////////////
			// ...serverSocket=... (completar)
			//////////////////////////////////////////////////
			socket = new DatagramSocket(port);
			// Mientras ... siempre!
			do {
				
				// Aceptamos una nueva conexión con accept()
				/////////////////////////////////////////////////
				// socketServicio=... (completar)
				//////////////////////////////////////////////////
				paquete = new DatagramPacket(bufer, bufer.length);

				socket.receive(paquete);
				

				mensaje = new String(paquete.getData());
				direccion = paquete.getAddress();
				port = paquete.getPort();

				ProcesadorYodafy pr=new ProcesadorYodafy();
				String respuesta=pr.yodaDo(mensaje);

				paquete =  new DatagramPacket(respuesta.getBytes(), respuesta.getBytes().length, direccion, port);
				socket.send(paquete);
			} while (true);
			
		} catch (IOException e) {
			System.err.println("Error al escuchar en el puerto "+port);
		}

	}

}
