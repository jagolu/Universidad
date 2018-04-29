import monitor.*;

//******************************************************************

class Barberia extends AbstractMonitor{
	private int clientes_esperando;
	private Condition esperar=makeCondition();
	private Condition dormir=makeCondition();
	private Condition terminado=makeCondition();
	private boolean empezarTrabajo;

	public Barberia(){
		empezarTrabajo=false;
		clientes_esperando=0;
	}

	public void cortarPelo(){
		enter();
		clientes_esperando++;
		if(clientes_esperando==1 && !empezarTrabajo){
			System.out.println("Despertando al barbero");
			dormir.signal();
			empezarTrabajo=true;
			System.out.println("Pelando...");
			terminado.await();
			empezarTrabajo=false;
		}
		else{
			esperar.await();	
			System.out.println("Pelando...");
			terminado.await();
		}
		leave();
	}

	public void siguienteCliente(){
		enter();
		if(clientes_esperando==0){
			System.out.println("El barbero esta durmiendo");
			dormir.await();
			empezarTrabajo=true;
		}
		else if(clientes_esperando!=0 && !empezarTrabajo){
			esperar.signal();
		}
		leave();
	}

	public void finCliente(){
		enter();
		clientes_esperando--;
		terminado.signal();
		leave();	
	}
		
}

//******************************************************************

class Cliente implements Runnable{
	public Thread thr;
	private int clienteN;
	private Barberia barberia;
	public Cliente(Barberia b, int num_cliente){
		thr=new Thread(this, "Cliente "+num_cliente);
		barberia=b;
		clienteN=num_cliente;
	}
	/*..............*/
	public void run(){
		try{
			while(true){
				System.out.println("Entrando cliente "+clienteN);
				barberia.cortarPelo();
				System.out.println("Cliente terminado "+clienteN);
				aux.dormir_max(9000);
			}
		}
		catch ( Exception e){
			System.err.println( "Exception en Cliente: " +e);
		}
	}
	
}

//******************************************************************		

class Barbero implements Runnable{
	public Thread thr;
	Barberia barberia;
	public Barbero(Barberia b){
		barberia=b;
		thr=new Thread(this, "Barbero");
	}
	/*.........*/
	public void run(){
		try{
			while(true){
				barberia.siguienteCliente();
				aux.dormir_max(2000);
				barberia.finCliente();
			}
		}
		catch(Exception e){
			System.err.println("Exception en barbero: " +e);
		}
	}
}


//******************************************************************

class BarberoDurmiente{
	public static void main(String [] args){
		if(args.length!=1){
			System.err.println("Uso: <Numero de clientes>");
			return ;
		}
		int n_clientes=Integer.parseInt(args[0]);
		Barberia barberia= new Barberia();
		Cliente [] clientes=new Cliente[n_clientes];
		Barbero barbero= new Barbero(barberia);
		for(int i=0;i<n_clientes;i++){
			clientes[i]=new Cliente(barberia, i);
		}
		for(int i=0;i<n_clientes;i++){
			clientes[i].thr.start();
		}
		barbero.thr.start();
	}
}























