/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ModeloTapuntas;
import ModeloTapuntas.TipoTransaccion;
import ModeloTapuntas.Vehiculo;
import ModeloTapuntas.PlanAlquiler;
import java.util.*;

/**
 *
 * @author 
 */
class Usuario {
    private String nombreUsuario;
    private String contraseña;
    private String direccionCorreo;
    private String telefono;
    private String breveDescriptionPersonal;
    private boolean visibilidad = false;
    private ArrayList <TipoTransaccion> preferenciaCobro=new ArrayList();
    private boolean pendienteBaja = false;
    private ArrayList<PlanAlquiler> listaPlanAlquiler=new ArrayList();
    private ArrayList<Vehiculo> listaVehiculos=new ArrayList();
    // incluir los demás atributos
            
    //GET
    public String getNombreUsuario(){
        return nombreUsuario;
    }
    public String getTelefono(){
        return telefono;
    }
    public String getDescripcionPersonal(){
        return breveDescriptionPersonal;
    }
    public ArrayList<PlanAlquiler> getListaPlanAlquiler(){
        return this.listaPlanAlquiler;
    }
    public String getVisibilidad(){
        String salida;
        if(visibilidad=true) salida="Esta visible";
        else salida="No esta visible";
        return salida;
    }
        public ArrayList<Vehiculo> getListaVehiculos(){
        return listaVehiculos;
    }
    public void setTelefono(String telefono){
        this.telefono=telefono;
    }
    public void setBreveDescripcionPersonal(String bdp){
        this.breveDescriptionPersonal=bdp;
    }
    //FIN GET

    Usuario(String nombreUsuario, String contraseña, String direccionCorreo) {
      this.nombreUsuario= nombreUsuario;
      this.contraseña = contraseña;
      this.direccionCorreo = direccionCorreo;
      this.telefono=null;
      this.breveDescriptionPersonal=null;
    }
    
    public boolean tienePerfilDefinido(){
        if(telefono==null || breveDescriptionPersonal==null)return false;
        else return true;
    }
    
    public void modificarVisibilidad(boolean visibilidad){
        this.visibilidad=visibilidad;
    }
    
    public void nuevoVehiculo(String matricula,String marca, String modelo, String color, int numeroPlazas, String categoria, String confor){
        Vehiculo miVehiculo=new Vehiculo(this, matricula, marca, modelo, color, numeroPlazas, categoria, confor);
        listaVehiculos.add(miVehiculo);
    }

    public ArrayList<String> obtenerPlanesQueCumplanRequisitos(String ciudadRecogida, GregorianCalendar fechaInicio, GregorianCalendar fechaFin){
        ArrayList<String> Planes=new ArrayList();
        
        boolean añadido=false;
        for(PlanAlquiler pa: listaPlanAlquiler){
            if(ciudadRecogida.equals(pa.getCiudadRecogida())){
                int diai=fechaInicio.get(Calendar.DAY_OF_MONTH);
                int mesi=fechaInicio.get(Calendar.MONTH);
                int añoi=fechaInicio.get(Calendar.YEAR);
                int diaf=fechaFin.get(Calendar.DAY_OF_MONTH);
                int mesf=fechaFin.get(Calendar.MONTH);
                int añof=fechaFin.get(Calendar.YEAR);
                int diai2=pa.getPrimerDiaAlquiler().get(Calendar.DAY_OF_MONTH);
                int mesi2=pa.getPrimerDiaAlquiler().get(Calendar.MONTH);
                int añoi2=pa.getPrimerDiaAlquiler().get(Calendar.YEAR);
                int diaf2=pa.getUltimoDiaAlquiler().get(Calendar.DAY_OF_MONTH);
                int mesf2=pa.getUltimoDiaAlquiler().get(Calendar.MONTH);
                int añof2=pa.getUltimoDiaAlquiler().get(Calendar.YEAR);
                ArrayList<String>datosPA=new ArrayList();
                if(añoi>añoi2){
                    if(añof<añof2){
                        datosPA=pa.obtenerdatosPA();
                        Planes.addAll(datosPA);añadido=true;
                    }
                    else if(añof==añof2){
                       if(mesf<mesf2){
                           datosPA=pa.obtenerdatosPA();
                            Planes.addAll(datosPA);añadido=true;
                       }
                       else if(mesf==mesf2){
                           if(diaf<=diaf2){
                               datosPA=pa.obtenerdatosPA();
                                Planes.addAll(datosPA);añadido=true;
                           }
                        }
                    }
                }
                else if(añoi==añoi2){
                    if(mesi>mesi2){
                        if(añof<añof2){
                           datosPA=pa.obtenerdatosPA();
                            Planes.addAll(datosPA);añadido=true;
                        }
                        else if(añof==añof2){
                            if(mesf<mesf2){
                                datosPA=pa.obtenerdatosPA();
                                Planes.addAll(datosPA);añadido=true;
                            }
                            else if(mesf==mesf2){
                                if(diaf<=diaf2){
                                    datosPA=pa.obtenerdatosPA();
                                    Planes.addAll(datosPA);añadido=true;
                                }
                            }
                        }
                    }
                    else if(mesi==mesi2){
                        if(diai>=diai2){
                            if(añof<añof2){
                                datosPA=pa.obtenerdatosPA();
                                Planes.addAll(datosPA);añadido=true;;
                            }
                            else if(añof==añof2){
                                if(mesf<mesf2){
                                    datosPA=pa.obtenerdatosPA();
                                    Planes.addAll(datosPA);añadido=true;;
                                }
                                else if(mesf==mesf2){
                                    if(diaf<=diaf2){
                                        datosPA=pa.obtenerdatosPA();
                                        Planes.addAll(datosPA);añadido=true;;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(añadido){
            Planes.add(0, "Nombre de Usuario: "+this.nombreUsuario);
            Planes.add(1, "Preferencias de cobro: ");
            int i=2;
            for(TipoTransaccion tt: preferenciaCobro){
                if(tt==TipoTransaccion.EFECTIVO)Planes.add(i,"\tEFECTIVO");
                if(tt==TipoTransaccion.PAYPAL)Planes.add(i,"\tPAYPAL");
                if(tt==TipoTransaccion.TARJETA)Planes.add(i,"\tTARJETA");
                if(tt==TipoTransaccion.TRANSFERENCIA)Planes.add(i,"\tTRANSFERENCIA");
                i++;
            }
        }
        return Planes;
    }

    public void definirPlanAlquiler(String matricula, GregorianCalendar fechaInicio, GregorianCalendar fechaFin, String ciudadRecogida, double precio)throws Exception{
        Vehiculo vehiculo=buscarVehiculo(matricula);
        boolean disponible=vehiculo.estasDisponible(fechaInicio, fechaFin);
        if(!disponible){
            throw new Exception("El vehiculo ya pertenece al plan alquiler en esas fechas");
        }
        PlanAlquiler miPlanAlquiler=new PlanAlquiler(vehiculo, fechaInicio, fechaFin, ciudadRecogida, precio);
        vehiculo.incluirPlanAlquiler(miPlanAlquiler);
        listaPlanAlquiler.add(miPlanAlquiler);
        
    }

    public void eliminarVehiculo(String matricula)throws Exception{
        Vehiculo vehiculo=buscarVehiculo(matricula);
        boolean alquilado=vehiculo.comprobarEstadoAlquileres();
        if(!alquilado){
            vehiculo.eliminarVehiculoAlquileres();
        }
        else{
            throw new Exception("El vehiculo no se puede eliminar, tiene vigentes viajes o alquileres");
        }
        listaVehiculos.remove(vehiculo);
    }
    
    public void introducirPerfil(String nombre, String telefono, String breveDescripcion, ArrayList <TipoTransaccion> preferenciaCobro){
        this.nombreUsuario=nombre;
        this.telefono=telefono;
        this.breveDescriptionPersonal=breveDescripcion;
        this.preferenciaCobro=preferenciaCobro;
    }
    
    public ArrayList<ArrayList<String>> obtenerPlanesAlquiler(){
        ArrayList<ArrayList<String>>misPlanesAlquiler=new ArrayList();
        Calendar d=Calendar.getInstance();
        int day=d.get(Calendar.DAY_OF_MONTH);
        int month=d.get(Calendar.MONTH);
        int year=d.get(Calendar.YEAR);
        for(PlanAlquiler pa:listaPlanAlquiler){
           ArrayList<String> datosPlanAlquiler=new ArrayList();
            if(!pa.getVisibilidad()){
                int diai=pa.getPrimerDiaAlquiler().get(Calendar.DAY_OF_MONTH);
                int mesi=pa.getPrimerDiaAlquiler().get(Calendar.MONTH);
                int añoi=pa.getPrimerDiaAlquiler().get(Calendar.YEAR);
                int diaf=pa.getUltimoDiaAlquiler().get(Calendar.DAY_OF_MONTH);
                int mesf=pa.getUltimoDiaAlquiler().get(Calendar.MONTH);
                int añof=pa.getUltimoDiaAlquiler().get(Calendar.YEAR);
                if(year>añoi){
                    if(year<añof){
                        datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                        datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                        datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                        datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                        datosPlanAlquiler.add(pa.getCiudadRecogida());
                    }
                    else if(year==añof){
                        if(month<mesf){
                            datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                            datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                            datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                            datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                            datosPlanAlquiler.add(pa.getCiudadRecogida());
                        }
                        else if(month==mesf){
                            if(day<diaf){
                                datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                datosPlanAlquiler.add(pa.getCiudadRecogida());
                            }
                            else if(day==diaf){
                                datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                datosPlanAlquiler.add(pa.getCiudadRecogida());
                            }
                        }
                    }
                }
                else if(year==añoi){
                    if(month>mesi){
                        if(year<añof){
                            datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                            datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                            datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                            datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                            datosPlanAlquiler.add(pa.getCiudadRecogida());
                        }
                        else if(year==añof){
                            if(month<mesf){
                                datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                datosPlanAlquiler.add(pa.getCiudadRecogida());
                            }
                            else if(month==mesf){
                                if(day<diaf){
                                    datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                    datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                    datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                    datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                    datosPlanAlquiler.add(pa.getCiudadRecogida());
                                }
                                else if(day==diaf){
                                    datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                    datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                    datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                    datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                    datosPlanAlquiler.add(pa.getCiudadRecogida());
                                }
                            }
                        }  
                    }
                    else if(month==mesi){
                        if(day>diai){
                            if(year<añof){
                                datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                datosPlanAlquiler.add(pa.getCiudadRecogida());
                            }
                            else if(year==añof){
                                if(month<mesf){
                                    datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                    datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                    datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                    datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                    datosPlanAlquiler.add(pa.getCiudadRecogida());
                                }
                                else if(month==mesf){
                                    if(day<diaf){
                                        datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                        datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                        datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                        datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                        datosPlanAlquiler.add(pa.getCiudadRecogida());
                                    }
                                    else if(day==diaf){
                                        datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                        datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                        datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                        datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                        datosPlanAlquiler.add(pa.getCiudadRecogida());
                                    }
                                }
                            }
                        }
                        else if(day==diai){
                            if(year<añof){
                                datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                datosPlanAlquiler.add(pa.getCiudadRecogida());
                            }
                            else if(year==añof){
                                if(month<mesf){
                                    datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                    datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                    datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                    datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                    datosPlanAlquiler.add(pa.getCiudadRecogida());
                                }
                                else if(month==mesf){
                                    if(day<diaf){
                                        datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                        datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                        datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                        datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                        datosPlanAlquiler.add(pa.getCiudadRecogida());
                                    }
                                    else if(day==diaf){
                                        datosPlanAlquiler.add(pa.getVehiculo().obtenerMatricula());
                                        datosPlanAlquiler.add(String.valueOf(diai)+"/"+String.valueOf(mesi)+"/"+String.valueOf(añoi));
                                        datosPlanAlquiler.add(String.valueOf(diaf)+"/"+String.valueOf(mesf)+"/"+String.valueOf(añof));
                                        datosPlanAlquiler.add(String.valueOf(pa.getCosteAlquilerAlDia()));
                                        datosPlanAlquiler.add(pa.getCiudadRecogida());
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }
        return misPlanesAlquiler;
    }
    
    public ArrayList<String> consultarPerfil(){
        ArrayList<String> info=new ArrayList();
        info.add(this.nombreUsuario);
        info.add(this.telefono);
        info.add(this.breveDescriptionPersonal);
        info.add(this.getVisibilidad());
        return info;
    }
    
    public void ofertarPlanAlquiler(GregorianCalendar fechaInicio, String matricula)throws Exception{
        PlanAlquiler pa=buscarPlanAlquiler(fechaInicio, matricula);
        if(pa!=null){
            pa.modificarVisibilidad(true);
        }
        else{
            throw new Exception("Ese plan de alquiler no esta definido");
        }
    }
    
    public Vehiculo buscarVehiculo(String matricula)throws Exception{
        Vehiculo vehiculo=null;
        boolean encontrado=false;
        for(Vehiculo v: listaVehiculos){
            if(v.obtenerMatricula().equals(matricula)){
                vehiculo=v;
                encontrado=true;
            }
        }
        if(!encontrado){
            throw new Exception("El vehiculo no existe");
        }
        
        return vehiculo;
    }
    
    public PlanAlquiler buscarPlanAlquiler(GregorianCalendar fechaInicio, String matricula){
        PlanAlquiler planAlquiler=null;
        for(PlanAlquiler pa:listaPlanAlquiler){
            if(pa.getVehiculo().obtenerMatricula().equals(matricula)){
                if(pa.getPrimerDiaAlquiler().get(Calendar.YEAR)==fechaInicio.get(Calendar.YEAR)){
                    if(pa.getPrimerDiaAlquiler().get(Calendar.DAY_OF_YEAR)==fechaInicio.get(Calendar.DAY_OF_YEAR)){
                        planAlquiler=pa;
                    }
                }
            }
        }
        return planAlquiler;
    }
}
