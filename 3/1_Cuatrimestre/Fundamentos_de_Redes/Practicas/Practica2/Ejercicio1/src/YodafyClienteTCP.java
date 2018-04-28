import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
public class YodafyClienteTCP {
    public static void main(String[] args) {
        byte []buferEnvio;
        byte []buferRecepcion=new byte[256];
        int bytesLeidos=0;
        String host="localhost";
        int port=8989;
        Socket socketServicio = null;
        try {		
                socketServicio = new Socket(host, port);
                InputStream inputStream = socketServicio.getInputStream();
                OutputStream outputStream = socketServicio.getOutputStream();
                buferEnvio="Al monte del volcán debes ir sin demora".getBytes();
                outputStream.write(buferEnvio, 0, buferEnvio.length);
                outputStream.flush();
                bytesLeidos = inputStream.read(buferRecepcion);
                System.out.println("Recibido: ");
                for(int i=0;i<bytesLeidos;i++){
                        System.out.print((char)buferRecepcion[i]);
                }
                socketServicio.close();
        } catch (UnknownHostException e) {
                System.err.println("Error: Nombre de host no encontrado.");
        } catch (IOException e) {
                System.err.println("Error de entrada/salida al abrir el socket.");
        }
    }
}
