package com.example.myproject;

import java.io.IOException;
import javax.servlet.http.*;
import org.jsoup.*;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;
import java.net.URL;
import java.net.URLConnection;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.BufferedReader;


@SuppressWarnings("serial")
public class MouseComparatorServlet extends HttpServlet {
    petitionPCC pcc=new petitionPCC();
    petitionBeep beep=new petitionBeep();
    petitionAmazon amazon=new petitionAmazon();
    public void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String modelo=req.getParameter("modelo").toLowerCase();
        MouseComparator bc=new MouseComparator();
        bc.setModelo(modelo);
        if(modelo.length()>0 && modelo.contains(" ") && modelo.indexOf(" ")!=0){
            pcc.checkPCC(modelo,bc);
            beep.checkBeep(modelo, bc);
            amazon.checkAmazon(modelo, bc);
            if(!bc.getUrlImagenAmazon().equals(null) || !bc.getUrlImagenPCC().equals(null) || !bc.getUrlImagenBeep().equals(null)){
                try{
                    req.setAttribute("MouseComparator", bc);
                    req.getRequestDispatcher("MouseComparator.jsp").forward(req, resp);
                }
                catch(Exception e){
                    resp.sendRedirect("/error.html");
                }
            }
            else resp.sendRedirect("/error.html");
        }
        else resp.sendRedirect("/badName.html");
    }

    protected String conectarURL(String url1){
        StringBuilder sb = new StringBuilder();
        URLConnection urlConn = null;
        InputStreamReader in = null;
        try {
            URL url = new URL(url1);
            urlConn = url.openConnection();
            urlConn.addRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0");
            if (urlConn != null) urlConn.setReadTimeout(60 * 1000);
            if (urlConn != null && urlConn.getInputStream() != null) {
                in = new InputStreamReader(urlConn.getInputStream(),Charset.defaultCharset());
                BufferedReader bufferedReader = new BufferedReader(in);
                if (bufferedReader != null) {
                    int cp;
                    while ((cp = bufferedReader.read()) != -1) sb.append((char) cp);
                    bufferedReader.close();
                }
            }
            in.close();
        } catch (Exception e) {
            return null;
        } 
        return sb.toString();
    }

    protected boolean compararPeticiones(String posible2, String modelo2){
        if(!stringNotNullNotEmpty(posible2) || !stringNotNullNotEmpty(modelo2)) return false;
        translateWords(posible2, 50);
        translateWords(modelo2, 50);
        String [] m=initializeStringArrayToVoid(50);
        boolean vale=true;
        int nm=1;
        for(int i=0;i<modelo.length();i++){
            if(modelo.charAt(i)==' ' || modelo.charAt(i)==',')  nm++;
            else m[nm-1]=m[nm-1]+modelo.charAt(i);
        }
        nm++;
        for(int i=0;i<nm;i++){
            if(!m[i].equals("mouse") && !m[i].equals("wireless") && !m[i].equals("cable")){
                if(!posible.contains(m[i])) vale=false;
            }
        }
        return vale;
    }
    
    protected String [] initializeStringArrayToVoid(int tam){
        String [] s=new String [tam];
        for(int i=0;i<tam;i++) s[i]="";
        return s;
    }
    
    protected String addWordsToURL(String url, int numPalabras, String [] palabras, String symbol){
        for(int i=0;i<numPalabras;i++){
            url=url+palabras[i];
            if(i!=(numPalabras-1)) url+=symbol;
        }
        return url;
    }
    
    protected int countWords(String modelo, String [] palabras){
        int numPalabras=0;
        for(int i=0;i<modelo.length();i++){
                if(modelo.charAt(i)==' ' || modelo.charAt(i)==',') numPalabras++;
                else palabras[numPalabras]+=modelo.charAt(i);
        }
        numPalabras++;
        return numPalabras;
    }
    
    protected String addTillCharacter(String cadBase, String cadRet, int pos, int addPos, char character){
        pos+=addPos;
        while(cadBase.charAt(pos)!=character){
            cadRet+=cadBase.charAt(pos);
            pos++;
        }
        return cadRet;
    }
    
    protected String getElementsByTag(String url, String tag){
        try{
            Document doc=Jsoup.connect(url).get();
            Elements e=doc.getElementsByTag(tag);
            return e.toString();
        }catch(IOException ioe){
            return null;
        }
    }
    
    protected String getSelect(String url, String whatsSelected){
        try{
            Document doc=Jsoup.connect(url).get();
            Elements e=doc.select(whatsSelected);
            return e.toString();
        }catch(IOException ioe){
            return null;
        }
    }
    
    protected boolean isNumeric(String cadena){
        try {
            Integer.parseInt(cadena);
            return true;
        } catch (NumberFormatException nfe){
            return false;
        }
    }

    protected boolean stringNotNullNotEmpty(String s){
        if(s!=null && !s.isEmpty()) return true;
        else false;
    }

    protected void translateWords(String [] palabras, int numPalabras){
        for(int i=0;i<numPalabras;i++){
            if(palabras[i].equals("azul")) palabras[i]="blue";
            else if(palabras[i].equals("dorado")) palabras[i]="golden";
            else if(palabras[i].equals("amarillo")) palabras[i]="yellow";
            else if(palabras[i].equals("púrpura")) palabras[i]="purple";
            else if(palabras[i].equals("rosa")) palabras[i]="pink";
            else if(palabras[i].equals("verde")) palabras[i]="green";
            else if(palabras[i].equals("rojo")) palabras[i]="red";
            else if(palabras[i].equals("negro")) palabras[i]="black";
            else if(palabras[i].equals("gris")) palabras[i]="gray";
            else if(palabras[i].equals("ratón") || palabras[i].equals("raton")) palabras[i]="mouse";
            else if(palabras[i].equals("inalambrico") || palabras[i].equals("inalámbrico")) palabras[i]="wireless";
        }
    }
}
