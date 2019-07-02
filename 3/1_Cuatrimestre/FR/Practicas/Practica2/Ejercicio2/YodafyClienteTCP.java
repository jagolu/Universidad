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
        String s_envio, s_recibido;
        String host="localhost";
        int port=8989;
        Socket socketServicio = null;
        try {
            socketServicio = new Socket(host, port);
            PrintWriter outPrinter = new PrintWriter(socketServicio.getOutputStream(), true);
            BufferedReader inReader = new BufferedReader(new InputStreamReader(socketServicio.getInputStream()));
            s_envio ="Al monte del volcán debes ir sin demora";
            outPrinter.println(s_envio);
            outPrinter.flush();
            s_recibido = inReader.readLine();
            System.out.println("Recibido: ");
            System.out.println(s_recibido);
            socketServicio.close();
        } catch (UnknownHostException e) {
                System.err.println("Error: Nombre de host no encontrado.");
        } catch (IOException e) {
                System.err.println("Error de entrada/salida al abrir el socket.");
        }
    }
}
