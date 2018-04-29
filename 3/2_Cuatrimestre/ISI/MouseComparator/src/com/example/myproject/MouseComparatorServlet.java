package com.example.myproject;

import java.io.IOException;
import javax.servlet.http.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.jsoup.*;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;

import java.lang.StringBuilder;

import java.util.HashMap;
import java.util.Map;
import java.net.URL;
import java.net.URLConnection;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.BufferedReader;

import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

@SuppressWarnings("serial")
public class MouseComparatorServlet extends HttpServlet {
	private static final String AWS_ACCESS_KEY_ID="*********************";
	private static final String AWS_SECRET_KEY="***************************";
	private static final String ENDPOINT="ecs.amazonaws.com";
	private static final String AMAZON_ASSOCIATE_TAG="****";
	public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
		String modelo=req.getParameter("modelo");
		MouseComparator bc=new MouseComparator();
		bc.setModelo(modelo);
		if(modelo.length()>0 && modelo.indexOf(" ")!=-1 && modelo.indexOf(" ")!=0){
			checkPCC(modelo,bc);
			checkBeep(modelo, bc);
			checkAmazon(modelo, bc);
			if(!bc.getUrlImagenAmazon().equals(null) || !bc.getUrlImagenPCC().equals(null) || !bc.getUrlImagenBeep().equals(null)){
				resp.getWriter().println("olala");
				try{
					req.setAttribute("MouseComparator", bc);
					req.getRequestDispatcher("MouseComparator.jsp").forward(req, resp);
				}
				catch(Exception e){
					resp.sendRedirect("/error.html");
				}
			}
			else{
				resp.sendRedirect("/error.html");
			}
		}
		else{
			resp.sendRedirect("/badName.html");
		}
		
	}
	
	public void checkPCC(String modelo, MouseComparator cb){
		String url=callURLPCC(modelo);
		try{
			String url2=getURLProductoPCC(url, modelo);
			cb.setUrlPCC(url2);
			cb.setPrecioPCC(getPricePCC(url2));
			cb.setUrlImagenPCC(getUrlImagenPCC(url2));
		}
		catch(Exception e){
			cb.setPrecioPCC("");
			cb.setUrlPCC("");
			cb.setUrlImagenPCC("");
		}
	}
	private void checkBeep(String modelo, MouseComparator cb){
		String url=callURLBeep(modelo);
		try{
			String url2=getURLProductoBeep(modelo, url);
			cb.setUrlBeep(url2);
			cb.setPrecioBeep(getPriceBeep(url2));
			cb.setUrlImagenBeep(getUrlImagenBeep(url2));
		}
		catch(Exception e){
			cb.setPrecioBeep("");
			cb.setUrlImagenBeep("");
			cb.setUrlBeep("");
		}
	}
	
	private String callURLPCC(String modelo){
		String url="https://www.pccomponentes.com/buscar/?query=";
		String [] palabras= new String [50];
		int numPalabras=0;
		for(int i=0;i<50;i++){
			palabras[i]="";
		}
		for(int i=0;i<modelo.length();i++){
			if(modelo.charAt(i)==' ' || modelo.charAt(i)==','){
				numPalabras++;
			}
			else{
				palabras[numPalabras]=palabras[numPalabras]+modelo.charAt(i);
			}
		}
		numPalabras++;
		for(int i=0;i<numPalabras;i++){
			url=url+palabras[i];
			if(i!=(numPalabras-1)){
				url=url+"+";
			}
		}
		String url2=conectarURL(url);
		if(url2.indexOf("No hay resultados")==-1){
			return url2;
		}
		else{
			return null;
		}
	}
	
	private String callURLBeep(String modelo){
		String url="http://www.beep.es/Catalogo/Buscar?buscar=";
		String [] palabras= new String [50];
		int numPalabras=0;
		for(int i=0;i<50;i++){
			palabras[i]="";
		}
		for(int i=0;i<modelo.length();i++){
			if(modelo.charAt(i)==' ' || modelo.charAt(i)==','){
				numPalabras++;
			}
			else{
				palabras[numPalabras]=palabras[numPalabras]+modelo.charAt(i);
			}
		}
		numPalabras++;
		for(int i=0;i<numPalabras;i++){
			if(i!=(numPalabras-1)){
				url=url+palabras[i]+"+";
			}
			else{
				url=url+palabras[i];
			}
		}
		url=url+"+raton";
		String url2=conectarURL(url);
		if(url2.indexOf("No se ha encontrado")==-1){
			return url2;
		}
		else{
			return null;
		}
	}
	
	private String conectarURL(String url1){
		StringBuilder sb = new StringBuilder();
		URLConnection urlConn = null;
		InputStreamReader in = null;
		try {
			URL url = new URL(url1);
			urlConn = url.openConnection();
			
			if (urlConn != null)
				urlConn.setReadTimeout(60 * 1000);
			if (urlConn != null && urlConn.getInputStream() != null) {
				in = new InputStreamReader(urlConn.getInputStream(),Charset.defaultCharset());
				BufferedReader bufferedReader = new BufferedReader(in);
				if (bufferedReader != null) {
					int cp;
					while ((cp = bufferedReader.read()) != -1) {
						sb.append((char) cp);
					}
					bufferedReader.close();
				}
			}
		in.close();
		} catch (Exception e) {
			return null;
		} 
		return sb.toString();
	}
	
	private String getPricePCC(String url){
		String precio="";
		try{
			Document doc=Jsoup.connect(url).get();
			Elements e=doc.getElementsByTag("script");
			String a=e.toString();
			boolean encontrado=false;
			int pos=0;
			while(!encontrado){
				pos=a.indexOf("'price': ", pos);
				if(a.charAt(pos+9)=='0' || a.charAt(pos+9)=='1' || a.charAt(pos+9)=='2' || a.charAt(pos+9)=='3' || a.charAt(pos+9)=='4' || a.charAt(pos+9)=='5' || a.charAt(pos+9)=='6' || a.charAt(pos+9)=='7' || a.charAt(pos+9)=='8' || a.charAt(pos+9)=='9'){
					encontrado=true;
				}
				pos=pos+9;
			}
			while(a.charAt(pos)!=','){
				precio=precio+a.charAt(pos);
				pos++;
			}
		}
		catch(IOException error){
			return null;
		}
		return precio;
	}
	
	private String getPriceBeep(String url){
		String precio="";
		try{
			Document doc=Jsoup.connect(url).get();
			Elements e=doc.getElementsByTag("script");
			String a=e.toString();
			int pos=a.indexOf("ecomm_totalvalue: [");
			while(a.charAt(pos+19)!=']'){
				precio=precio+a.charAt(pos+19);
				pos++;
			}
			return precio;
		}
		catch(IOException error){
			return null;
		}
	}
	
	private String getUrlImagenBeep(String url){
		String imagen="";
		try{
			Document doc=Jsoup.connect(url).get();
			Elements e=doc.select("a.group0");
			String a=e.toString();
			int pos=a.indexOf("<a class=\"group0\" href=");
			int i=24;
			while(a.charAt(pos+i)!='\"'){
				imagen=imagen+a.charAt(pos+i);
				i++;
			}
			return imagen;
		}
		catch(IOException error){
			return null;
		}
	}
	
	private String getUrlImagenPCC(String url){
		String imagen="http://";
		try{
			Document doc=Jsoup.connect(url).get();
			Elements e=doc.select("a.fancybox");
			String a=e.toString();
			int pos=a.indexOf("a class=\"fancybox\" data-fancybox-group=\"gallery\" href=\"https://img.pccomponentes.com");
			int i=59;
			while(a.charAt(pos+i)!='\"'){
				imagen=imagen+a.charAt(pos+i);
				i++;
			}
		}
		catch(IOException error){
			return null;
		}
		return imagen;
	}
	
	private String getURLProductoBeep(String modelo, String url){
		int pos=0;
		while(url.indexOf("<div class=\"datosProducto\"", pos)!=-1){
			pos=url.indexOf("<div class=\"datosProducto\"", pos);
			String finalURL="http://www.beep.es";
			pos=url.indexOf("<a href=\"", pos);
			pos=pos+9;
			while(url.charAt(pos)!='?'){
				finalURL=finalURL+url.charAt(pos);
				pos++;
			}
			pos=url.indexOf(">", pos);
			pos++;
			while(url.charAt(pos)!=' ') pos++;
			String posible="";
			while(url.charAt(pos)!='<'){
				posible=posible+url.charAt(pos);
				pos++;
			}
			if(compararPeticiones(posible, modelo)){
				return finalURL;
			}
		}
		return null;
	}
	
	private String getURLProductoPCC(String url, String modelo){
		int pos=0;
		while(url.indexOf("GTM-productClick enlace-superpuesto", pos)!=-1){
			pos=url.indexOf("GTM-productClick enlace-superpuesto", pos);
			int posURL=pos-1000;
			int pos2=pos;
			String finalURL="https://www.pccomponentes.com";
			posURL=url.indexOf("href=", posURL);
			while(url.charAt(posURL+6)!='"'){
				finalURL=finalURL+url.charAt(posURL+6);
				posURL++;
			}
			pos2=url.indexOf("data-name=", pos2);
			String posible="";
			int t=11;
			while(url.charAt(pos2+t)!='"'){
				posible=posible+url.charAt(pos2+t);
				t++;
			}
			if(compararPeticiones(posible, modelo)){
				return finalURL;
			}
		}
		return null;
	}

	private void checkAmazon(String modelo2, MouseComparator bc){
		String modelo=modelo2.toLowerCase();
		String [] palabras= new String [50];
		int numPalabras=0;
		for(int i=0;i<50;i++){
			palabras[i]="";
		}
		for(int i=0;i<modelo.length();i++){
			if(modelo.charAt(i)==' ' || modelo.charAt(i)==','){
				numPalabras++;
			}
			else{
				palabras[numPalabras]=palabras[numPalabras]+modelo.charAt(i);
			}
		}
		numPalabras++;
		for(int i=0;i<numPalabras;i++){
			if(palabras[i].equals("azul")){
				palabras[i]="blue";
			}
			else if(palabras[i].equals("dorado")){
				palabras[i]="golden";
			}
			else if(palabras[i].equals("amarillo")){
				palabras[i]="yellow";
			}
			else if(palabras[i].equals("púrpura")){
				palabras[i]="purple";
			}
			else if(palabras[i].equals("rosa")){
				palabras[i]="pink";
			}
			else if(palabras[i].equals("verde")){
				palabras[i]="green";
			}
			else if(palabras[i].equals("rojo")){
				palabras[i]="red";
			}
			else if(palabras[i].equals("negro")){
				palabras[i]="black";
			}
			else if(palabras[i].equals("gris")){
				palabras[i]="gray";
			}
			else if(palabras[i].equals("ratón") || palabras[i].equals("raton")){
				palabras[i]="mouse";
			}
			else if(palabras[i].equals("inalambrico") || palabras[i].equals("inalámbrico")){
				palabras[i]="wireless";
			}
		}
		String aBuscar="", modelo3="";
		for(int i=0;i<numPalabras;i++){
			if(i==0){
				aBuscar=aBuscar+palabras[i];
				if(!palabras[i].equals("mouse") && !palabras[i].equals("wireless") && !palabras[i].equals("dpi") && !isNumeric(palabras[i])){
					modelo3=modelo3+palabras[i];
				}
			}
			else{
				aBuscar=aBuscar+"+"+palabras[i];
				if(!palabras[i].equals("mouse") && !palabras[i].equals("wireless") && !palabras[i].equals("dpi") && !isNumeric(palabras[i])){
					modelo3=modelo3+" "+palabras[i];
				}
			}
		}
		try {
			SignedRequestsHelper helper1;
	        try {
	            helper1 = SignedRequestsHelper.getInstance(ENDPOINT, AWS_ACCESS_KEY_ID, AWS_SECRET_KEY);
	        } catch (Exception e) {
	            e.printStackTrace();
	            return;
	        }
	        
	        Map<String, String> params = new HashMap<String, String>();
	        params.put("Service", "AWSECommerceService");
	        params.put("Version", "2011-08-01");
	        params.put("AssociateTag", AMAZON_ASSOCIATE_TAG);
	        params.put("Operation", "ItemSearch");
	        params.put("ResponseGroup", "Medium");
	        params.put("Keywords", aBuscar);
	        params.put("SearchIndex", "All");
	        String requestUrl1 = helper1.sign(params);
	       	DocumentBuilderFactory dbf =DocumentBuilderFactory.newInstance();
	        DocumentBuilder db;
			db = dbf.newDocumentBuilder();
			org.w3c.dom.Document doc1=null;
			try {
				doc1 = db.parse(requestUrl1);
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			String name=null;
			name=getElementValue(doc1, "Title");
			try{
				if(compararPeticiones(name, modelo3)){
					String url=getElementValue(doc1,"ItemLink");
					String url2="https:";
					int pos=url.indexOf("/");
					for(int i=pos;i<url.length();i++){
						url2=url2+url.charAt(i);
					}
					bc.setUrlAmazon(url2);
					String precio=getElementValue(doc1,"ListPrice");
					String precio2="";
					int posPrecio=precio.indexOf("$");
					for(int i=posPrecio+1;i<precio.length();i++){
						precio2=precio2+precio.charAt(i);
					}
					bc.setPrecioAmazon(precio2);
					
					
					NodeList nodelist = doc1.getElementsByTagName("URL");
					String asinCodes[]=new String[nodelist.getLength()];
			        for (int i=0; i<asinCodes.length; i++){
			        	asinCodes[i] = nodelist.item(i).getTextContent();
			        }
			        int cont=0;
			        String urlFinal=null;
			        for(int i=0;i<asinCodes.length;i++){
			        	if(asinCodes[i].indexOf("jpg")!=-1){
			        		cont++;
			        		if(cont==3){
			        			urlFinal=asinCodes[i];
			        		}
			        	}
			        }
			        bc.setUrlImagenAmazon(urlFinal);
				}
			}
			catch(Exception e){
				bc.setUrlAmazon("");
				bc.setUrlImagenAmazon("");
				bc.setPrecioAmazon("");
				return ;
			}
		} catch (ParserConfigurationException e1) {
			return;
		}
		catch (SAXException e) {
			return;
		}
	}
	
	private boolean compararPeticiones(String posible2, String modelo2){
		if(posible2.equals(null) || modelo2.equals(null)){
			return false;
		}
		String posible=posible2.toLowerCase();
		String modelo=modelo2.toLowerCase();
		String [] m=new String [50]; int nm=1;
		for(int i=0;i<50;i++){
			m[i]="";
		}
		for(int i=0;i<modelo.length();i++){
			if(modelo.charAt(i)==' ' || modelo.charAt(i)==','){
				nm++;
			}
			else{
				m[nm-1]=m[nm-1]+modelo.charAt(i);
			}
		}
		nm++;
		boolean vale=true;
		for(int i=0;i<nm;i++){
			if(!m[i].equals("Mouse") && !m[i].equals("mouse") && !m[i].equals("MOUSE") && !m[i].equals("Raton") && !m[i].equals("raton") && !m[i].equals("RATON")  && !m[i].equals("Ratón") && !m[i].equals("ratón") && !m[i].equals("RATÓN") && !m[i].equals("Wireless") && !m[i].equals("wireless") && !m[i].equals("WIRELESS") && !m[i].equals("Inalambrico") && !m[i].equals("inalambrico") && !m[i].equals("INALAMBRICO")  && !m[i].equals("Inalámbrico") && !m[i].equals("inalámbrico") && !m[i].equals("INALÁMBRICO") && !m[i].equals("Con cable") && !m[i].equals("con cable") && !m[i].equals("CON CABLE")  && !m[i].equals("con Cable") && !m[i].equals("Con Cable")){
				if(posible.indexOf(m[i])==-1){
					vale=false;
				}
			}
		}
		return vale;
	}
	
	private boolean isNumeric(String cadena){
		try {
			Integer.parseInt(cadena);
			return true;
		} catch (NumberFormatException nfe){
			return false;
		}
	}
	
	private String getElementValue (org.w3c.dom.Document doc, String tag){
      NodeList nodelist = doc.getElementsByTagName(tag);
      return ( (nodelist.getLength()>0) ? nodelist.item(0).getTextContent() : null );
    }
}
