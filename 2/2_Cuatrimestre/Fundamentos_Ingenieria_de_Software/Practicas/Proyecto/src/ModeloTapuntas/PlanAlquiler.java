/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ModeloTapuntas;
import java.util.GregorianCalendar;
import ModeloTapuntas.Vehiculo;
import java.util.ArrayList;
import java.util.Calendar;


/**
 *
 * @author Javier
 */
class PlanAlquiler {
    private boolean visible;
    private GregorianCalendar primerDiaAlquiler;
    private GregorianCalendar ultimoDiaAlquiler;
    private double costeAlquilerAlDia;
    private String ciudadRecogida;
    private Vehiculo miVehiculo;
    
    //get
    public GregorianCalendar getPrimerDiaAlquiler(){
        return primerDiaAlquiler;
    }
    public GregorianCalendar getUltimoDiaAlquiler(){
        return ultimoDiaAlquiler;
    }
    public Vehiculo getVehiculo(){
        return miVehiculo;
    }
    public String getCiudadRecogida(){
        return ciudadRecogida;
    }
    public double getCosteAlquilerAlDia(){
        return costeAlquilerAlDia;
    }
    public boolean getVisibilidad(){
        return visible;
    }
    //get
    
    public ArrayList<String> obtenerdatosPA(){
        ArrayList<String> datosPA=new ArrayList();
        datosPA.add("Datos vehiculo: ");
        for(String s: miVehiculo.obtenerDatosVehiculo()){
            datosPA.add(s);
        }
        datosPA.add(String.valueOf(costeAlquilerAlDia));
        return datosPA;
    }
    
    PlanAlquiler(Vehiculo unVehiculo, GregorianCalendar fechaInicio, GregorianCalendar fechaFin, String ciudadRecogida, double precio){
        this.miVehiculo=unVehiculo;
        this.primerDiaAlquiler=fechaInicio;
        this.ultimoDiaAlquiler=fechaFin;
        this.ciudadRecogida=ciudadRecogida;
        this.modificarVisibilidad(false);
        this.costeAlquilerAlDia=precio;
    }
    
    public void eliminarVehiculo(){
        miVehiculo=null;
    }
    
    public ArrayList<String> obtenerDatosPlanAlquiler(){
        ArrayList<String> salida=new ArrayList();
        salida.add("Precio: "+this.costeAlquilerAlDia);
        salida.add("Vehiculo: ");
        ArrayList<String> v=miVehiculo.obtenerDatosVehiculo();
        for(String vv: v){
            salida.add("\t"+vv);
        }
        salida.add("Primer dia alquiler: "+String.valueOf(this.primerDiaAlquiler.get(Calendar.DAY_OF_MONTH))+"/"+String.valueOf(this.primerDiaAlquiler.get(Calendar.MONTH))+"/"+String.valueOf(this.primerDiaAlquiler.get(Calendar.YEAR)));
        salida.add("Ultimo dia alquiler: "+String.valueOf(this.ultimoDiaAlquiler.get(Calendar.DAY_OF_MONTH))+"/"+String.valueOf(this.ultimoDiaAlquiler.get(Calendar.MONTH))+"/"+String.valueOf(this.ultimoDiaAlquiler.get(Calendar.YEAR)));
        if(this.visible){
            salida.add("Esta visible");
        }
        else{
            salida.add("No esta visible");
        }
        return salida;
    }
    
    public void modificarVisibilidad(boolean visibilidad){
        this.visible=visibilidad;
    }
}
