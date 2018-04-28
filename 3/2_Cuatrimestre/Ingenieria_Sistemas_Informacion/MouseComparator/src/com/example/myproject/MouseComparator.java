package com.example.myproject;

import java.io.Serializable;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

@XmlRootElement(name="MouseComparator")
@XmlType(propOrder={
		"modelo",
		"precio"
})


public class MouseComparator implements Serializable{
	private String modelo="";
	private String urlImagenPCComponentes="";
	private String urlImagenBeep="";
	private String urlImagenAmazon="";
	private String urlPCComponentes="";
	private String urlBeep="";
	private String urlAmazon="";
	private String precioPCComponentes="";
	private String precioBeep="";
	private String precioAmazon="";
	
	
	//Constructor por defecto
	
	MouseComparator(){
		this.modelo=null;
		this.urlImagenPCComponentes=null;
		this.urlBeep=null;
		this.urlImagenAmazon=null;
		this.urlPCComponentes=null;
		this.urlBeep=null;
		this.urlAmazon=null;
		this.precioPCComponentes=null;
		this.precioBeep=null;
		this.precioAmazon=null;
	}
	
	//Constructor por parametros
	
	MouseComparator(String modelo, String urlImagenPCComponentes, String urlImagenBeep, String urlImagenAmazon, String urlPCComponentes, String urlBeep, String urlAmazon, String precioPCComponentes, String precioBeep, String precioAmazon){
		this.modelo=modelo;
		this.urlImagenPCComponentes=urlImagenPCComponentes;
		this.urlImagenBeep=urlImagenBeep;
		this.urlImagenAmazon=urlImagenAmazon;
		this.urlPCComponentes=urlPCComponentes;
		this.urlBeep=urlBeep;
		this.urlAmazon=urlAmazon;
		this.precioPCComponentes=precioPCComponentes;
		this.precioBeep=precioBeep;
		this.precioAmazon=precioAmazon;
	}
	
	//Getters
	
	@XmlElement(required=true)
	public String getModelo(){
		return modelo;
	}
	
	@XmlElement(required=true)
	public String getPrecioPCC(){
		return precioPCComponentes;
	}
	
	@XmlElement(required=true)
	public String getPrecioBeep(){
		return precioBeep;
	}
	
	@XmlElement(required=true)
	public String getPrecioAmazon(){
		return precioAmazon;
	}
	
	@XmlElement(required=true)
	public String getUrlPCC(){
		return urlPCComponentes;
	}
	
	@XmlElement(required=true)
	public String getUrlBeep(){
		return urlBeep;
	}
	
	@XmlElement(required=true)
	public String getUrlAmazon(){
		return urlAmazon;
	}
	
	@XmlElement(required=true)
	public String getUrlImagenBeep(){
		return urlImagenBeep;
	}
	
	@XmlElement(required=true)
	public String getUrlImagenPCC(){
		return urlImagenPCComponentes;
	}
	
	@XmlElement(required=true)
	public String getUrlImagenAmazon(){
		return urlImagenAmazon;
	}
	
	//Seters
	
	public void setModelo(String modelo){
		this.modelo=modelo;
	}
	
	public void setPrecioPCC(String precioPCComponentes){
		this.precioPCComponentes=precioPCComponentes;
	}
	
	public void setPrecioBeep(String precioBeep){
		this.precioBeep=precioBeep;
	}
	
	public void setPrecioAmazon(String precioAmazon){
		this.precioAmazon=precioAmazon;
	}
	
	public void setUrlPCC(String urlPCComponentes){
		this.urlPCComponentes=urlPCComponentes;
	}
	
	public void setUrlBeep(String urlBeep){
		this.urlBeep=urlBeep;
	}
	
	public void setUrlAmazon(String urlAmazon){
		this.urlAmazon=urlAmazon;
	}
	
	public void setUrlImagenBeep(String urlImagenBeep){
		this.urlImagenBeep=urlImagenBeep;
	}
	
	public void setUrlImagenPCC(String urlImagenPCComponentes){
		this.urlImagenPCComponentes=urlImagenPCComponentes;
	}
	
	public void setUrlImagenAmazon(String urlImagenAmazon){
		this.urlImagenAmazon=urlImagenAmazon;
	}

}
