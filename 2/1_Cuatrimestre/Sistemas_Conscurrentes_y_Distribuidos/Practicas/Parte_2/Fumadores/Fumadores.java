import monitor.*;
import java.util.Random;

//***********************************************************************

class Estanco extends AbstractMonitor{
	private int ingrediente;
	private Condition poner;
	private Condition[] coger= new Condition[3];
	
	public Estanco( ){
		poner= makeCondition();
		for(int i=0;i<3;i++){
			coger[i]= makeCondition();
		}
		ingrediente=-1;

	}

	public void obtenerIngrediente(int miIngrediente){
		enter();
		if(ingrediente==-1 || miIngrediente!=ingrediente){
			coger[miIngrediente].await();
		}
		System.out.println("Fumador " +miIngrediente +" recoge el ingrediente " +ingrediente);
		poner.signal();
		ingrediente=-1;
		leave();
	}
	public void ponerIngrediente(int ingrediente){
		enter();
		this.ingrediente=ingrediente;
		System.out.println("Puesto ingrediente " +ingrediente);
		coger[ingrediente].signal();
		leave();
	}
	public void esperarRecogidaIngrediente(){
		enter();
		if(ingrediente!=-1){	
			poner.await();
		}
		
		leave();
	}
}

//***********************************************************************

class Fumador implements Runnable{
	int miIngrediente;
	public Thread thr;
	private Estanco estanco;
	/*...................*/
	public Fumador(int p_miIngrediente, Estanco e){
		miIngrediente=p_miIngrediente;
		thr=new Thread(this, "Fumador "+p_miIngrediente);
		estanco=e;
	}
	public void run(){
		try{
			while(true){
				estanco.obtenerIngrediente(miIngrediente);
				aux.dormir_max(2000);
			}
		}
		catch(Exception e){
			System.err.println("Exception en Fumador "+miIngrediente +" : " +e);
		}
	}
}

//*******************************************************************

class Estanquero implements Runnable{
	public Thread thr;
	private Estanco estanco;
	public Estanquero(Estanco e){
		thr=new Thread(this, "Estanquero");
		estanco=e;
	}
	/*.......................*/
	public void run(){
		try{
			int ingrediente;
			while(true){
				Random r=new Random();
				ingrediente= r.nextInt(3);
				estanco.ponerIngrediente(ingrediente);
				estanco.esperarRecogidaIngrediente();
			}
		}
		catch(Exception e){
			System.err.println("Exception en Estanquero: " +e);	
		}
	}
}

//********************************************************************

class Fumadores{ 
	public static void main(String [] args){
		Fumador[] fums = new Fumador[3];
		Estanco estanco= new Estanco();
		Estanquero estanquero=new Estanquero(estanco);
		for(int i=0;i<3;i++){
			fums[i]=new Fumador(i,estanco);
		}
		for(int i=0;i<3;i++){
			fums[i].thr.start();
		}
		estanquero.thr.start();
	}
}


























