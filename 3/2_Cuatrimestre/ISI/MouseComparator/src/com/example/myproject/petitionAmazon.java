package com.example.myproject;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class petitionAmazon extends MouseComparatorServlet{
    private static final String AWS_ACCESS_KEY_ID="*********************";
    private static final String AWS_SECRET_KEY="***************************";
    private static final String ENDPOINT="ecs.amazonaws.com";
    private static final String AMAZON_ASSOCIATE_TAG="****";
    public void checkAmazon(String modelo, MouseComparator bc){
        String [] palabras=initializeStringArrayToVoid(50);
        int numPalabras=countWords(modelo, palabras);
        translateColors(palabras, numPalabras);
        org.w3c.dom.Document doc1=initializeDocument(getKeywords(numPalabras, palabras));
        if(doc1!=null){
            bc.setUrlAmazon(getURLProductoAmazon(doc1));
            bc.setPrecioAmazon(getPriceAmazon(doc1));
            bc.setUrlImagenAmazon(getURLImagenAmazon(doc1));
        }
        else{
            bc.setUrlAmazon("");
            bc.setUrlImagenAmazon("");
            bc.setPrecioAmazon("");
        }
    }
    
    private void translateColors(String [] palabras, int numPalabras){
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
    
    private String getElementValue (org.w3c.dom.Document doc, String tag){
      NodeList nodelist = doc.getElementsByTagName(tag);
      return ( (nodelist.getLength()>0) ? nodelist.item(0).getTextContent() : null );
    }
    
    private String getURLProductoAmazon(org.w3c.dom.Document doc1){
        String url=getElementValue(doc1,"ItemLink");
        String urlFinal=addTillCharacter(url, "https:", url.indexOf("/"), 0, url.charAt(url.length()-1));
        urlFinal+=url.charAt(url.length()-1);
        return urlFinal;
    }
    
    private String getPriceAmazon(org.w3c.dom.Document doc1){
        String precio=getElementValue(doc1,"ListPrice");
        String precioFinal=addTillCharacter(precio, "", precio.indexOf("$"), 0, precio.charAt(precio.length()-1));
        precioFinal+=precio.charAt(precio.length()-1);
        return precioFinal;
    }
    
    private String getURLImagenAmazon(org.w3c.dom.Document doc1){
        NodeList nodelist = doc1.getElementsByTagName("URL");
        String asinCodes[]=new String[nodelist.getLength()];
        for (int i=0; i<asinCodes.length; i++){
            asinCodes[i] = nodelist.item(i).getTextContent();
        }
        int cont=0;
        String urlFinal=null;
        for(int i=0;i<asinCodes.length;i++){
            if(!asinCodes[i].contains("jpg")){
                cont++;
                if(cont==3){
                    urlFinal=asinCodes[i];
                }
            }
        }
        return urlFinal;
    }
    
    private org.w3c.dom.Document initializeDocument(String keywords){
        SignedRequestsHelper helper1;
        try {
            helper1 = SignedRequestsHelper.getInstance(ENDPOINT, AWS_ACCESS_KEY_ID, AWS_SECRET_KEY);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
        String requestUrl1 = helper1.sign(loadParams(keywords));
        DocumentBuilderFactory dbf =DocumentBuilderFactory.newInstance();
        DocumentBuilder db;
        org.w3c.dom.Document doc1=null;
        try{
            db = dbf.newDocumentBuilder();
            try {
                    doc1 = db.parse(requestUrl1);
            } catch (IOException e) {
                    e.printStackTrace();
            }
            catch (SAXException e) {
                return null;
            }
        }catch(ParserConfigurationException e1){
            return null;
        }
        return doc1;
    }
    
    private Map<String, String> loadParams(String keywords){
        Map<String, String> params = new HashMap<String, String>();
        params.put("Service", "AWSECommerceService");
        params.put("Version", "2011-08-01");
        params.put("AssociateTag", AMAZON_ASSOCIATE_TAG);
        params.put("Operation", "ItemSearch");
        params.put("ResponseGroup", "Medium");
        params.put("Keywords", keywords);
        params.put("SearchIndex", "All");
        return params;
    }
    
    private String getKeywords(int numPalabras, String [] palabras){
        String keywords="", modelo="";
        for(int i=0;i<numPalabras;i++){
            if(i==0){
                keywords=keywords+palabras[i];
                if(diferentThat_Mouse_Wireless_Dpi_Numeric(palabras[i])) modelo=modelo+palabras[i];
            }
            else{
                keywords=keywords+"+"+palabras[i];
                if(diferentThat_Mouse_Wireless_Dpi_Numeric(palabras[i])) modelo=modelo+" "+palabras[i];
            }
        }
        org.w3c.dom.Document doc=initializeDocument(keywords);
        if(compararPeticiones(getElementValue(doc, "Title"), modelo)) return keywords;
        else return null;
    }
    
    private boolean diferentThat_Mouse_Wireless_Dpi_Numeric(String palabra){
       if(!palabra.equals("mouse") && !palabra.equals("wireless") && !palabra.equals("dpi") && !isNumeric(palabra)) return true;
       else return false;
    }
}
