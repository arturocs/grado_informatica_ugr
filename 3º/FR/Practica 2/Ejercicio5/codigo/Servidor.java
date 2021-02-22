import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;

public class Servidor {

	public static void main(String[] args) {
		
		String user="arturo";
		String password="1234";
		int port_client=8989;
		int port_app=9898;
		InputStream inputStream;
		OutputStream outputStream_app;
		OutputStream outputStream_client;
		String datosRecibidos;
		Random aleatorio = new Random(System.currentTimeMillis());
		int intAletorio = aleatorio.nextInt(10000);
		
		try {

			ServerSocket socket_cliente = new ServerSocket(port_client);
			ServerSocket socket_app = new ServerSocket(port_app);
			// Mientras ... siempre!
			do {

				Socket socketServicio_cli = socket_cliente.accept();
				Socket socketServicio_app = socket_app.accept();

				inputStream=socketServicio_cli.getInputStream();
				outputStream_app=socketServicio_app.getOutputStream();
				outputStream_client=socketServicio_cli.getOutputStream();
				BufferedReader inReader = new BufferedReader(new InputStreamReader(inputStream));
				datosRecibidos = inReader.readLine();

				if(datosRecibidos.equals(user+password)){
					System.out.println("\nRecibido: " + datosRecibidos + " correcto\n");

					PrintWriter outPrinter_client = new PrintWriter(outputStream_client, true);
					outPrinter_client.println("1"); //usuario y contraseña ok

					PrintWriter outPrinter_app = new PrintWriter(outputStream_app, true);
					String cod = ""+intAletorio;
					outPrinter_app.println(cod); //enviar codigo a app

					//outPrinter_client.println("2"); //introduce el codigo

					inReader = new BufferedReader(new InputStreamReader(inputStream));
					datosRecibidos = inReader.readLine(); //recibe codigo de cliente

					//codigo introducido
					
					if(cod.equals(datosRecibidos)){
						outPrinter_client.println("2"); // codigo correcto
						System.out.print("Autenticacion finalizada con exito "+ datosRecibidos+"\n");
					}
					else{
						outPrinter_client.println("-1"); //codigo incorrecto
						System.out.print("Codigo erroneo "+ datosRecibidos+"\n");
					}

				}
				else{
					System.out.println("\nRecibido: " + datosRecibidos + " incorrecto\n");
					PrintWriter outPrinter = new PrintWriter(outputStream_client, true);
					outPrinter.println("0"); //usuario y contraaseña incorrectos
				}

				
			} while (true);
			
		} catch (IOException e) {
			System.err.println("Error al escuchar en el puerto "+port_app+ " o "+ port_client);
		}

	}

}
