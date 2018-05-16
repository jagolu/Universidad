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
        if(posible2.equals(null) || modelo2.equals(null)) return false;
        String posible=posible2.toLowerCase();
        String modelo=modelo2.toLowerCase();
        String [] m=initializeStringArrayToVoid(50); 
        int nm=1;
        for(int i=0;i<modelo.length();i++){
            if(modelo.charAt(i)==' ' || modelo.charAt(i)==',')  nm++;
            else m[nm-1]=m[nm-1]+modelo.charAt(i);
        }
        nm++;
        boolean vale=true;
        for(int i=0;i<nm;i++){
            if(!m[i].equals("Mouse") && !m[i].equals("mouse") && !m[i].equals("MOUSE") && !m[i].equals("Raton") && !m[i].equals("raton") && !m[i].equals("RATON")  && !m[i].equals("Ratón") && !m[i].equals("ratón") && !m[i].equals("RATÓN") && !m[i].equals("Wireless") && !m[i].equals("wireless") && !m[i].equals("WIRELESS") && !m[i].equals("Inalambrico") && !m[i].equals("inalambrico") && !m[i].equals("INALAMBRICO")  && !m[i].equals("Inalámbrico") && !m[i].equals("inalámbrico") && !m[i].equals("INALÁMBRICO") && !m[i].equals("Con cable") && !m[i].equals("con cable") && !m[i].equals("CON CABLE")  && !m[i].equals("con Cable") && !m[i].equals("Con Cable")){
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
        }catch(IOException error){
            return null;
        }
    }
    
    protected String getSelect(String url, String whatsSelected){
        try{
            Document doc=Jsoup.connect(url).get();
            Elements e=doc.select(whatsSelected);
            return e.toString();
        }catch(IOException error){
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
}
