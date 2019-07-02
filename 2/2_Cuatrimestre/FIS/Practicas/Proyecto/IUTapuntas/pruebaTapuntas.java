/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package IUTapuntas;

import ModeloTapuntas.Tapuntas;
import java.util.Scanner;
import ModeloTapuntas.TipoTransaccion;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.GregorianCalendar;
import java.util.Calendar;


/**
 *
 * @author aanaya
 */
public class pruebaTapuntas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
     
        // Obtener la única instancia de la clase BuenProvecho (patrón sigleton)
        Tapuntas aViajar = Tapuntas.getInstance(); 
        
        // Definir la variable que nos permite leer String desde teclado
        final Scanner in = new Scanner(System.in);
        int opcion = 0; 
        do{
            try{ // tratamiento de las excepciones. Bloque try en el que se puede producir una excepción y la capturamos
		 
                 //Terminar de diseñar el menú (usando System.out.println(...)) con las opciones que faltan
		 // Podéis hacer vuestros propios diseños de interfaz, esta es la interfaz mínima que tenéis que entregar
                System.out.println("\n\n*********************************** MENU ***********************************\n" +
                                       "GESTIÓN DE USUARIOS   \n" +
                                     "\t10. Nuevo Usuario \n" +
                                     "\t11. Consultar usuarios del sistema \n" +
                                     "\t12. Incluir Perfil de Usuario \n" +
                                     "\t13. Consultar Perfil de un Usuario \n");	
                                 
                System.out.println("GESTIÓN DE VEHICULOS  \n" +                             
                                    "\t20. Nuevo vehículo \n" +
                                    "\t21. Consultar vehículos de un usuario \n" +
                                    "\t22. Eliminar vehículo\n");
                
                System.out.println("GESTIÓN DE PLANES DE ALQUILER  \n" +
                                    "\t30. Definir nuevo plan de alquiler \n" +
                                    "\t31. Consultar mis planes de alquiler\n" +
                                    "\t32. Ofertar un plan de alquiler \n" +
                                    "\t33. Buscar ofertas de planes de alquiler \n");
                
                System.out.println("\n**********************************************************************");
                		         
                System.out.println("\t0. TERMINAR");
		System.out.println("\n**********************************************************************");
                 
                // Lectura de un int, para darle valor a opcion.
                opcion =Integer.parseInt(in.nextLine()); 
                
                // Estructura switch con todas las opciones de menú. Algunos de ellos ya lo tenéis hecho
                // Tenéis que terminar las opciones que están incompletas y las que no están hechas
                switch(opcion){
                    case 10: //incluir un nuevo usuario en el sistema 
                                            
                        System.out.print("Nombre de Usuario:");
                        String nombreUsuario =in.nextLine();
                                       
                        System.out.print("Clave:");
                        String claveUsuario= in.nextLine();
                        
                        System.out.print("Dirección de correo:");
                        String correoUsuario= in.nextLine();
                        
                        aViajar.altaRegistro(nombreUsuario, claveUsuario, correoUsuario);                                             
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                    break;  
                    
                    case 11:/*Ver usuarios del sistema */
                        aViajar.getUsuarios();
                        Iterator it = aViajar.getUsuarios().entrySet().iterator();
                        while (it.hasNext()) {
                            Map.Entry e = (Map.Entry)it.next();
                            System.out.println(e.getKey());
                        }
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                    break;
                    
                    case 12:/*Incluir Perfil */
                        System.out.println("Nombre del usuario: ");
                        String nombreU=in.nextLine();

                        System.out.println("Nombre: ");
                        String nombre=in.nextLine();

                        System.out.println("Telefono: ");
                        String telef=in.nextLine();

                        System.out.println("Breve descripcion: ");
                        String bdesc=in.nextLine();

                        System.out.println("Escoja las preferencia cobro: ");
                        ArrayList<TipoTransaccion> tt=new ArrayList();
                        int opcion2=10;
                        do{
                            boolean tarjeta=false, paypal=false, efectivo=false, trans=false;
                            System.out.println("\t1 Tarjeta");
                            System.out.println("\t2 Paypal");
                            System.out.println("\t3 Efectivo");
                            System.out.println("\t4 Transferencia");
                            System.out.println("\t0 Terminar");
                            opcion2 =Integer.parseInt(in.nextLine());
                            switch(opcion2){
                                case 1:
                                    if(!tarjeta)tt.add(TipoTransaccion.TARJETA);
                                    tarjeta=true;
                                break;
                                case 2:
                                    if(!paypal)tt.add(TipoTransaccion.PAYPAL);
                                    paypal=true;
                                break;
                                case 3:
                                    if(!efectivo)tt.add(TipoTransaccion.EFECTIVO);
                                    efectivo=true;
                                break;
                                case 4:
                                    if(!trans)tt.add(TipoTransaccion.TRANSFERENCIA);
                                    trans=true;
                                break;
                                case 0:
                                break;
                                default:
                                    System.out.println("Ese valor no esta\n");
                                break;
                            }
                        }while(opcion2!=0);
                        aViajar.introducirPerfil(nombreU, nombre, telef, bdesc, tt); 
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                    break;
                    case 13:/*Consultar perfil */
                        System.out.print("Nombre de Usaurio:");
                        nombreUsuario =in.nextLine();
                        ArrayList<String> info=aViajar.consultarPerfil(nombreUsuario);
                        int contadorbucles=0;
                        for(String i: info){
                            if(contadorbucles==0){
                                if(i!=null) System.out.println("Nombre usuario: "+i);
                                else System.out.println("Nombre usuario: No definido");
                            }
                            else if(contadorbucles==1){
                                if(i!=null)System.out.println("Telefono: "+i);
                                else System.out.println("Telefono: No definido");
                            }
                            else if(contadorbucles==2){
                                if(i!=null) System.out.println("Breve descripcion personal: "+i);
                                else System.out.println("Breve descripcion personal: No definido");
                            }
                            else{
                                System.out.println(i);
                            }
                            contadorbucles++;
                        }
                    break;
                
                    case 20: /*Nuevo vehículo */ 
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine(); 
                        
                        System.out.println("Matricula del vehiculo: ");
                        String matricula=in.nextLine();
                        
                        System.out.println("Marca del vehiculo: ");
                        String marca=in.nextLine();
                        
                        System.out.println("Modelo del vehiculo: ");
                        String modelo=in.nextLine();
                        
                        System.out.println("Color del vehiculo: ");
                        String color=in.nextLine();
                        
                        System.out.println("Numero de plazas del vehiculo: ");
                        int num_plazas=Integer.parseInt(in.nextLine());
                        
                        System.out.println("Categoria del vehiculo: ");
                        String categoria=in.nextLine();
                        
                        System.out.println("Confor del vehiculo: ");
                        String confor=in.nextLine();
                        
                        
                        System.out.println();
                        aViajar.añadirVehiculo(nombreUsuario, matricula, marca, modelo, color, num_plazas, categoria, confor);
                        
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                    break;
                  
                    case 21: /* Consultar vehículos de un usuario  */
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine(); 
                        
                        for(ArrayList<String> s1: aViajar.mostrarVehiculos(nombreUsuario)){
                            for(String s2: s1){
                                System.out.println(s2);
                            }
                            System.out.println();
                        }                     
                    break;             
                  
                    case 22: /* Eliminar vehículo  */
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine(); 
                        
                        System.out.println("Matricula del vehiculo: ");
                        matricula=in.nextLine();
                        
                        aViajar.eliminarVehiculoPropietario(nombreUsuario, matricula);
                        
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                                                    
                    break;
  
    
                    case 30: /* Nuevo plan de alquiler */
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine(); 
                        
                        System.out.println("Matricula del vehiculo: ");
                        matricula=in.nextLine();
                        
                        GregorianCalendar dateInicio=new GregorianCalendar();
                        
                        System.out.println("Dia de inicio del nuevo plan de alquiler: ");
                        String diai=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(diai)<1 && Integer.parseInt(diai)>31){
                            throw new Exception("Forma del dia incorrecto");
                        }
                        
                        System.out.println("Mes de inicio del nuevo plan de alquiler: ");
                        String mesi=String.valueOf(Integer.parseInt(in.nextLine()));
                        
                        System.out.println("Año de inicio del nuevo plan de alquiler: \n\t(El año debe introducirse en formato de 4 digitos)");
                        String añoi=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(añoi)<1000 && Integer.parseInt(añoi)>9999){
                            throw new Exception("Forma del año incorrecto");
                        }
                        dateInicio.set(Integer.parseInt(añoi), Integer.parseInt(mesi), Integer.parseInt(diai));
                        
                        GregorianCalendar dateFin=new GregorianCalendar();
                        
                        System.out.println("Dia de fin del nuevo plan de alquiler: ");
                        String diaf=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(diaf)<1 && Integer.parseInt(diaf)>31){
                            throw new Exception("Forma del dia incorrecto");
                        }
                        
                        System.out.println("Mes de fin del nuevo plan de alquiler: ");
                        String mesf=String.valueOf(Integer.parseInt(in.nextLine()));
                        
                        System.out.println("Año de fin del nuevo plan de alquiler: \n\t(El año debe introducirse en formato de 4 digitos)");
                        String añof=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(añof)<1000 && Integer.parseInt(añof)>9999){
                            throw new Exception("Forma del año incorrecto");
                        }
                        dateFin.set(Integer.parseInt(añof), Integer.parseInt(mesf), Integer.parseInt(diaf));
                        
                        if(!aViajar.fechasCorrectas(dateInicio, dateFin)){
                            throw new Exception("La fecha de inicio debe ser menor que la fecha de fin");
                        }
                        
                        System.out.println("Ciudad de recogida: ");
                        String ciudadRecogida=in.nextLine();
                        
                        System.out.println("Precio de alquiler al dia: ");
                        double precio=Double.parseDouble(in.nextLine());
                        
                        aViajar.definirPlanAlquiler(nombreUsuario, matricula, dateInicio, dateFin, ciudadRecogida, precio);
                        
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                    break;

                    case 31: /* Consultar planes de alquiler de un usuario */
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine();   
                        
                        for(ArrayList<String> s1: aViajar.mostrarOfertasAlquiler(nombreUsuario)){
                            for(String s2: s1){
                                System.out.println(s2);
                            }
                            System.out.println();
                        }
                    break;

                    case 32: /* Ofertar un plan de alquiler */
                        System.out.println("Nombre del usuario: ");
                        nombreUsuario=in.nextLine(); 
                        
                        System.out.println("Matricula del vehiculo: ");
                        matricula=in.nextLine();
                        
                        GregorianCalendar dateI=new GregorianCalendar();
                        
                        System.out.println("Dia de inicio del plan de alquiler: ");
                        diai=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(diai)<1 && Integer.parseInt(diai)>31){
                            throw new Exception("Forma del dia incorrecto");
                        }
                        
                        System.out.println("Mes de inicio del plan de alquiler: ");
                        mesi=String.valueOf(Integer.parseInt(in.nextLine()));
                        
                        System.out.println("Año de inicio del plan de alquiler: \n\t(El año debe introducirse en formato de 4 digitos)");
                        añoi=String.valueOf(Integer.parseInt(in.nextLine()));
                        dateI.set(Integer.parseInt(añoi), Integer.parseInt(mesi), Integer.parseInt(diai));
                        if(Integer.parseInt(añoi)<1000 && Integer.parseInt(añoi)>9999){
                            throw new Exception("Forma del año incorrecto");
                        }
                        
                        
                        aViajar.ofertarPlanAlquiler(nombreUsuario, dateI, matricula);
                        
                        System.out.print("++++++  Operación realizada con éxito ++++++");
                                  
                    break;

                    case 33: /* Buscar ofertas de planes de alquiler  */
                        System.out.println("Ciudad de recogida: ");
                        ciudadRecogida=in.nextLine();
                        
                        System.out.println("Matricula del vehiculo: ");
                        matricula=in.nextLine();
                        
                        GregorianCalendar fechaInicio=new GregorianCalendar();
                        
                        System.out.println("Dia de inicio del plan de alquiler: ");
                        diai=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(diai)<1 && Integer.parseInt(diai)>31){
                            throw new Exception("Forma del dia incorrecto");
                        }
                        
                        System.out.println("Mes de inicio del plan de alquiler: ");
                        mesi=String.valueOf(Integer.parseInt(in.nextLine()));
                        
                        System.out.println("Año de inicio del plan de alquiler: \n\t(El año debe introducirse en formato de 4 digitos)");
                        añoi=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(añoi)<1000 || Integer.parseInt(añoi)>9999){
                            throw new Exception("Forma del año incorrecto");
                        }
                        fechaInicio.set(Integer.parseInt(añoi), Integer.parseInt(mesi), Integer.parseInt(diai));
                        
                        GregorianCalendar fechaFin=new GregorianCalendar();
                        
                        System.out.println("Dia de fin del plan de alquiler: ");
                        diaf=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(diaf)<1 || Integer.parseInt(diaf)>31){
                            throw new Exception("Forma del dia incorrecto");
                        }
                        
                        System.out.println("Mes de fin del plan de alquiler: ");
                        mesf=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(mesf)<1 )
                        
                        System.out.println("Año de fin del plan de alquiler: \n\t(El año debe introducirse en formato de 4 digitos)");
                        añof=String.valueOf(Integer.parseInt(in.nextLine()));
                        if(Integer.parseInt(añof)<1000 && Integer.parseInt(añof)>9999){
                            throw new Exception("Forma del año incorrecto");
                        }
                        fechaFin.set(Integer.parseInt(añof), Integer.parseInt(mesf), Integer.parseInt(diaf));
                        if(!aViajar.fechasCorrectas(fechaInicio, fechaFin)){
                            throw new Exception("La fecha de inicio debe ser menor que la fecha de fin");
                        }
                        for(ArrayList<String> s1: aViajar.buscarOfertasAlquiler(ciudadRecogida, fechaInicio, fechaFin)){
                            for(String s2: s1){
                                System.out.println(s2);
                            }
                            System.out.println();
                        }
                        

                    break;                 

                    case 0: /* terminar */
                    break;                        
                                    
                    default:
                        System.out.println("opcion no válida");
                    break;
                }
//               
            }catch(Exception ex){ // captura de la excepción
                System.err.println("se ha producido la siguiente excepcion: "+ ex);
            } 
        }while(opcion !=0); 
        System.exit(0);
    }  

}

    
    

