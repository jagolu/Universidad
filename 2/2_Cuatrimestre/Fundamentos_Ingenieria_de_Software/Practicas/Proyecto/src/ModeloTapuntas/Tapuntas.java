/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ModeloTapuntas;

import ModeloTapuntas.Usuario;
import ModeloTapuntas.Vehiculo;
import ModeloTapuntas.PlanAlquiler;
import java.util.*;

/**
 *
 * @author aanaya
 */
public class Tapuntas {
    private Map<String /*nombreUsuario*/,Usuario/*objetoUsuario*/> usuarios = new HashMap();

    // Este método mo está bien, está hecho para probar, tenéis que implementar el singleton
    public static Tapuntas getInstance() {
        return new Tapuntas();        
    }

    public void altaRegistro(String nombreUsuario, String contraseña, String direccionCorreo) throws Exception {
       if(usuarios.containsKey(nombreUsuario)) throw new Exception("ya existe un usuario con ese nombre de usuario");
       usuarios.put(nombreUsuario, new Usuario(nombreUsuario,contraseña,direccionCorreo));
       
    }
    
    public Map<String /*nombreUsuario*/,Usuario/*objetoUsuario*/> getUsuarios(){
        return usuarios;
    }
    
    public ArrayList<ArrayList<String>> mostrarVehiculos(String nombreUsuario)throws Exception{ 
        Usuario u=buscarUsuario(nombreUsuario);  
        ArrayList<ArrayList<String>> datos=new ArrayList();
        for(Vehiculo v:u.getListaVehiculos()){
            datos.add(v.obtenerDatosVehiculo());
        }
        return datos;
    }
    
    public ArrayList<ArrayList<String>> mostrarOfertasAlquiler(String nombreUsuario)throws Exception{
        ArrayList<ArrayList<String>> salida=new ArrayList();
        Usuario usuario=buscarUsuario(nombreUsuario);
        if(usuario.getListaPlanAlquiler()!=null){
            for(PlanAlquiler pa: usuario.getListaPlanAlquiler()){
                if(pa!=null){
                    if(pa.obtenerDatosPlanAlquiler()!=null){
                        salida.add(pa.obtenerDatosPlanAlquiler());
                    }
                }
            }
        }
        return salida;
    }
    
    
    
    public void añadirVehiculo(String nombreUsuario, String matricula,String marca, String modelo, String color, int numeroPlazas, String categoria, String confor)throws Exception{
        if(existeVehiculo(matricula)){
            throw new Exception("ya existe otro vehiculo en el sistema con esa matricula");
        }
        Usuario usuario=buscarUsuario(nombreUsuario);
        usuario.nuevoVehiculo(matricula, marca, modelo,color, numeroPlazas, categoria, confor);
    }
    
    public ArrayList<ArrayList<String>> buscarOfertasAlquiler(String ciudadRecogida,GregorianCalendar fechaInicio, GregorianCalendar FechaFin){
        Iterator it=usuarios.entrySet().iterator();
        ArrayList<ArrayList<String>>listaOfertas=new ArrayList();
        while(it.hasNext()){
            Map.Entry e=(Map.Entry)it.next();
            Usuario u=(Usuario)e.getValue();
            ArrayList<String> aux=u.obtenerPlanesQueCumplanRequisitos(ciudadRecogida, fechaInicio, FechaFin);
            if(!aux.isEmpty())listaOfertas.add(aux);
        }
        if(!listaOfertas.isEmpty()){
            ordenarOfertas(listaOfertas);
        }
        else{
            System.out.println("No hay ofertas que mostrar");
        }
        
        return listaOfertas;
    }
    
    public void definirPlanAlquiler(String idUsuario, String idVehiculo, GregorianCalendar fechaInicio, GregorianCalendar fechaFin, String ciudadRecogida, double precio)throws Exception{
        Usuario usuario=buscarUsuario(idUsuario);
        usuario.definirPlanAlquiler(idVehiculo, fechaInicio, fechaFin, ciudadRecogida, precio);
    }
    public void eliminarVehiculoPropietario(String nombreUsuario, String matricula)throws Exception{
        Usuario usuario=buscarUsuario(nombreUsuario);
        usuario.eliminarVehiculo(matricula);
    }
    
    public void introducirPerfil(String nombreUsuario, String nombre, String telefono, String breveDescripcion, ArrayList<TipoTransaccion> preferenciaCobro)throws Exception{
        Usuario usuario=buscarUsuario(nombreUsuario);
        if(usuario.tienePerfilDefinido()){
            throw new Exception("El usuario ya tiene un perfil definido");
        }
        usuario.introducirPerfil(nombre, telefono, breveDescripcion, preferenciaCobro);
        usuario.modificarVisibilidad(true);
    }
  
    public ArrayList<ArrayList<String>> obtenerPlanesAlquiler(String nombreUsuario)throws Exception{
        Usuario usuario=buscarUsuario(nombreUsuario);
        ArrayList<ArrayList<String>> misPlanesAlquiler=new ArrayList();
        misPlanesAlquiler=usuario.obtenerPlanesAlquiler();
        return misPlanesAlquiler;
    }
    
    public ArrayList<String> consultarPerfil(String nombreUsuario)throws Exception{
        ArrayList<String> infoPerfil=new ArrayList();
        Usuario u=buscarUsuario(nombreUsuario);
        infoPerfil=u.consultarPerfil();
        return infoPerfil;
    }
    
    
        
    public void ofertarPlanAlquiler(String nombreUsuario, GregorianCalendar fechaInicio, String matricula)throws Exception{
        Usuario usuario=buscarUsuario(nombreUsuario);
        usuario.ofertarPlanAlquiler(fechaInicio, matricula);
    }
    
    private boolean existeUsuario(String nombreUsuario){
        boolean existe=false;
        Iterator it=usuarios.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry e=(Map.Entry)it.next();
            if(e.getKey().equals(nombreUsuario)){
                existe=true;
            }
        }
        return existe;
    }
    
    private Usuario buscarUsuario(String nombreUsuario)throws Exception{
        if(!existeUsuario(nombreUsuario)){
            throw new Exception("El usuario no existe");
        }
        Usuario usuario=null;
        Iterator it=usuarios.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry e=(Map.Entry)it.next();
            if(e.getKey().equals(nombreUsuario)){
                usuario=(Usuario) e.getValue();
            }
        }
        return usuario;
    }
    
    private void ordenarOfertas(ArrayList<ArrayList<String>> listaOfertas){
        int tam=listaOfertas.size();
        double aux[]=new double[tam];
        ArrayList<String> auxiliar[]=new ArrayList[tam];
        int i=0;
        for(ArrayList<String> s1: listaOfertas){
            if(s1.size()-1>=0 && s1.size()-1<s1.size()){
                auxiliar[i]=s1;
                aux[i]=Double.parseDouble(s1.get(s1.size()-1));
                i++;
            }
        }
        listaOfertas.clear();
        for(i=0;i<tam;i++){
            for(int j=i+1;j<tam;j++){
                if(aux[i]<aux[j]){
                    double  auxx=aux[i];
                    aux[i]=aux[j];
                    aux[j]=auxx;
                    
                    
                    ArrayList<String> auxx2=auxiliar[i];
                    auxiliar[i]=auxiliar[j];
                    auxiliar[j]=auxx2;
                }
            }
        }
        for(i=0;i<tam;i++){
            listaOfertas.add(auxiliar[i]);
        }
    }
    
    private boolean existeVehiculo(String matricula){
        boolean existe=false;
        Iterator it=usuarios.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry e=(Map.Entry)it.next();
            Usuario u=(Usuario)e.getValue();
            for(Vehiculo v: u.getListaVehiculos()){
                if(v.obtenerMatricula()==matricula){
                    existe=true;
                }
            }
        }
        return existe;
    }
    
    public boolean fechasCorrectas(GregorianCalendar fi, GregorianCalendar ff){
        boolean correcto=false;
        int diai=fi.get(Calendar.DAY_OF_YEAR);
        int añoi=fi.get(Calendar.YEAR);
        int diaf=ff.get(Calendar.DAY_OF_YEAR);
        int añof=ff.get(Calendar.YEAR);
        if(añoi<añof){
            correcto=true;
        }
        else if(añoi==añof){
            if(diai<diaf){
                correcto=true;
            }
        }
        return correcto;
    }
}
