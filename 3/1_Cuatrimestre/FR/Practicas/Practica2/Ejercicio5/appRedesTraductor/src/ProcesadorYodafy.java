import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Random;
import language.Language;
import yandtran.translate.Translate;

public class ProcesadorYodafy {

	private Socket socketServicio;
	private InputStream inputStream;
	private OutputStream outputStream;
	private Random random;
	
	public ProcesadorYodafy(Socket socketServicio) {
		this.socketServicio=socketServicio;
		random=new Random();
	}
	
	void procesa() throws Exception{
		

		byte [] datosRecibidos=new byte[1024];
		int bytesRecibidos=0;
		byte [] datosEnviar;
		
		try {
                       
			inputStream=socketServicio.getInputStream();
			outputStream=socketServicio.getOutputStream();
			
                        bytesRecibidos = inputStream.read(datosRecibidos);
                        
			String peticion=new String(datosRecibidos,0,bytesRecibidos);
                        String respuesta=new String();

                        Translate.setKey("trnsl.1.1.20161129T074308Z.ba3481cb641d47ba.62ec1dc73408a02b419fda966e1123b755c1884c");

                        respuesta = Translate.execute(peticion, Language.SPANISH, Language.ENGLISH);
                       
			datosEnviar=respuesta.getBytes();
			
			outputStream.write(datosEnviar);
		
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
