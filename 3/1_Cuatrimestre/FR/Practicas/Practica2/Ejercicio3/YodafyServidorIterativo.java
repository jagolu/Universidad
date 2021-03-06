import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class YodafyServidorIterativo {
    public static void main(String[] args) {
        int port=8989;
        ServerSocket socketServidor;
        Socket socketConexion = null;
        try {
            socketServidor = new ServerSocket(port);
                do {
                    socketConexion = socketServidor.accept();
                    ProcesadorYodafy procesador=new ProcesadorYodafy(socketConexion);
                    procesador.start();
                } while (true);
        } catch (IOException e) {
            System.err.println("Error al escuchar en el puerto "+port);
        }
    }
}
