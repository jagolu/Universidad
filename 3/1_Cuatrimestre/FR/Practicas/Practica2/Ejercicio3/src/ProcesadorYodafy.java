import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;

public class ProcesadorYodafy extends Thread {
    private Socket socketServicio;
    private Random random;
    public ProcesadorYodafy(Socket socketServicio) {
        this.socketServicio=socketServicio;
        random=new Random();
    }
    public void run(){
        procesa();
    }
    void procesa(){		               
        String s_enviado, s_recibido;
        try {                 
            PrintWriter outPrinter = new PrintWriter(socketServicio.getOutputStream(), true);
            BufferedReader inReader = new BufferedReader(new InputStreamReader(socketServicio.getInputStream()));
            s_recibido = inReader.readLine();
            s_enviado =yodaDo(s_recibido);
            outPrinter.println(s_enviado);
        } catch (IOException e) {
            System.err.println("Error al obtener los flujos de entrada/salida.");
        }
    }
    private String yodaDo(String peticion) {
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
        return resultado;
    }
}
