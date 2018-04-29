import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;

public class YodafyClienteUDP {
    public static void main(String[] args) throws SocketException, UnknownHostException, IOException {
        byte []buferRecibido =new byte[256];
        byte []bufer=new byte[256];
        int bytesLeidos=0;
        String host="localhost";
        int port=8989;
        InetAddress direccion;
        DatagramPacket paquete;
        DatagramSocket socket;
        bufer = "Al monte del volcán debes ir sin demora".getBytes();
        socket = new DatagramSocket();
        direccion = InetAddress.getByName(host);
        paquete = new DatagramPacket (bufer,bufer.length, direccion, port);
        socket.send(paquete);
        paquete = new DatagramPacket(buferRecibido, buferRecibido.length);
        socket.receive(paquete);
        paquete.getData();
        paquete.getAddress();
        paquete.getPort();
        System.out.println("Recibido: ");
        for(int i=0;i<buferRecibido.length;i++){
            System.out.print((char)buferRecibido[i]);
        }
        socket.close();            
    }
}
