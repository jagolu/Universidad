/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ModeloTapuntas;
import ModeloTapuntas.Usuario;
import java.util.GregorianCalendar;
import ModeloTapuntas.PlanAlquiler;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author Javier
 */
class Vehiculo {
    private String marca;
    private String modelo;
    private String confor;
    private int numeroPlazas;
    private String color;
    private String categoria;
    private String matricula;
    private ArrayList<PlanAlquiler> listaPlanAlquiler=new ArrayList();
    
    

    Vehiculo(Usuario unUsuario, String matricula, String marca, String modelo, String color, int numeroPlazas, String categoria, String confor){
        this.matricula=matricula;
        this.marca=marca;
        this.modelo=modelo;
        this.color=color;
        this.numeroPlazas=numeroPlazas;
        this.categoria=categoria;
        this.confor=confor;
    }

    public ArrayList<String> obtenerDatosVehiculo(){
        ArrayList<String> salida=new ArrayList();
        salida.add("Matricula: "+matricula);
        salida.add("Marca: "+marca);
        salida.add("Modelo: "+modelo);
        salida.add("Confor: "+confor);
        salida.add("Numero de plazas: "+String.valueOf(numeroPlazas));
        salida.add("Color: "+color);
        salida.add("Categoria: "+categoria);
        return salida;
    }

    public boolean estasDisponible(GregorianCalendar fechaInicio, GregorianCalendar fechaFin){
        boolean disponible=true;
        int diai1=fechaInicio.get(Calendar.DAY_OF_MONTH);
        int mesi1=fechaInicio.get(Calendar.MONTH);
        int añoi1=fechaInicio.get(Calendar.YEAR);
        int diaf1=fechaFin.get(Calendar.DAY_OF_MONTH);
        int mesf1=fechaFin.get(Calendar.MONTH);
        int añof1=fechaFin.get(Calendar.YEAR);
        for(PlanAlquiler pa: listaPlanAlquiler){
            int diai2=pa.getPrimerDiaAlquiler().get(Calendar.DAY_OF_MONTH);
            int mesi2=pa.getPrimerDiaAlquiler().get(Calendar.MONTH);
            int añoi2=pa.getPrimerDiaAlquiler().get(Calendar.YEAR);
            int diaf2=pa.getUltimoDiaAlquiler().get(Calendar.DAY_OF_MONTH);
            int mesf2=pa.getUltimoDiaAlquiler().get(Calendar.MONTH);
            int añof2=pa.getUltimoDiaAlquiler().get(Calendar.YEAR);
            if(añof1<añoi2){
                disponible=true;
            }
            else if(añof1==añoi2){
                if(mesf1<mesi2){
                    disponible=true;
                }
                else if(mesf1==mesi2){
                    if(diaf1<diai2){
                        disponible=true;
                    }
                }
            }
            else if(añoi1>añof2){
                disponible=true;
            }
            else if(añoi1==añof2){
                if(mesi1>mesf2){
                    disponible=true;
                }
                else if(mesi1==mesf2){
                    if(diai1>diaf2){
                        disponible=true;
                    }
                }
            }
        }
        return disponible;
    }

    public void incluirPlanAlquiler(PlanAlquiler miPlanAlquiler){
        listaPlanAlquiler.add(miPlanAlquiler);
    }

    public boolean comprobarEstadoAlquileres(){//cambiar
        boolean pertenece=false;
        Calendar d=Calendar.getInstance();
        int day=d.get(Calendar.DAY_OF_MONTH);
        int month=d.get(Calendar.MONTH);
        int year=d.get(Calendar.YEAR);
        for(PlanAlquiler lpa: listaPlanAlquiler){
            int diai=lpa.getPrimerDiaAlquiler().get(Calendar.DAY_OF_MONTH);
            int mesi=lpa.getPrimerDiaAlquiler().get(Calendar.MONTH);
            int añoi=lpa.getPrimerDiaAlquiler().get(Calendar.YEAR);
            int diaf=lpa.getUltimoDiaAlquiler().get(Calendar.DAY_OF_MONTH);
            int mesf=lpa.getUltimoDiaAlquiler().get(Calendar.MONTH);
            int añof=lpa.getUltimoDiaAlquiler().get(Calendar.YEAR);
            if(year>añoi){
                if(year<añof)pertenece=true;
                else if(year==añof){
                    if(month<mesf)pertenece=true;
                    else if(month==mesf){
                        if(day<diaf)pertenece=true;
                        else if(day==diaf)pertenece=true;
                    }
                }
            }
            else if(year==añoi){
                if(month>mesi){
                    if(year<añof)pertenece=true;
                    else if(year==añof){
                        if(month<mesf)pertenece=true;
                        else if(month==mesf){
                            if(day<diaf)pertenece=true;
                            else if(day==diaf)pertenece=true;
                        }
                    }  
                }
                else if(month==mesi){
                    if(day>diai){
                        if(year<añof)pertenece=true;
                        else if(year==añof){
                            if(month<mesf)pertenece=true;
                            else if(month==mesf){
                                if(day<diaf)pertenece=true;
                                else if(day==diaf)pertenece=true;
                            }
                        }
                    }
                    else if(day==diai){
                        if(year<añof)pertenece=true;
                        else if(year==añof){
                            if(month<mesf)pertenece=true;
                            else if(month==mesf){
                                if(day<diaf)pertenece=true;
                                else if(day==diaf)pertenece=true;
                            }
                        }
                    }
                }
            }
        }
        return pertenece;
    }

    public void eliminarVehiculoAlquileres(){
        ArrayList<PlanAlquiler> listaPlanAlquiler2=listaPlanAlquiler;
        for(PlanAlquiler pa: listaPlanAlquiler2){
            listaPlanAlquiler.remove(pa);
        }
    }

    public String obtenerMatricula(){
        return matricula;
    }

}
