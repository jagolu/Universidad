import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import static java.lang.Math.random;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class YodafyServidorIterativo {
    public static void main(String[] args) throws IOException {
        DatagramSocket socketServidor = null;
        int port=8989;
        byte []bufer=new byte[256];
        byte []buferyoda=new byte[256];
        Random random;
        random = new Random();
        try {
            socketServidor = new DatagramSocket(port);

        } catch (IOException e) {
                System.err.println("Error al escuchar en el puerto "+port);
        }
        while(true){
            InetAddress direccion;
            DatagramPacket paquete;
            paquete = new DatagramPacket(bufer, bufer.length);
            socketServidor.receive(paquete);
            String peticion = new String(bufer,0,bufer.length);
            String[] s = peticion.split(" ");
            String resultado="";
            for(int i=0;i<s.length;i++){
                    int j=random.nextInt(s.length);
                    int k=random.nextInt(s.length);
                    String tmp=s[j];

                    s[j]=s[k];
                    s[k]=tmp;
            }
            resultado=s[0];
            for(int i=1;i<s.length;i++){
              resultado+=" "+s[i];
            }
            buferyoda = resultado.getBytes();
            direccion = paquete.getAddress();
            port = paquete.getPort();
            paquete = new DatagramPacket (buferyoda,buferyoda.length, direccion, port);
            socketServidor.send(paquete);
        }           
    }
}
        
