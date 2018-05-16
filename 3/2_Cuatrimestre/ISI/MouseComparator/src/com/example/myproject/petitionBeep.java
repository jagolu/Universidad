package com.example.myproject;

public class petitionBeep extends MouseComparatorServlet{
    public void checkBeep(String modelo, MouseComparator cb){
        String url=callURLBeep(modelo);
        if(url!=null){
            String urlProducto=getURLProductoBeep(modelo, url);
            cb.setUrlBeep(urlProducto);
            cb.setPrecioBeep(getPriceBeep(urlProducto));
            cb.setUrlImagenBeep(getUrlImagenBeep(urlProducto));
        }
        else{
            cb.setPrecioBeep("");
            cb.setUrlImagenBeep("");
            cb.setUrlBeep("");
        }
    }
    
    private String callURLBeep(String modelo){
        String url="https://www.beep.es/buscar/";
        String [] palabras=initializeStringArrayToVoid(50);
        int numPalabras=countWords(modelo, palabras);
        url=addWordsToURL(url, numPalabras, palabras, "%20");
        url=conectarURL(url);
        if(!url.contains("No se ha encontrado")) return url;
        else return null;
    }
    
    private String getPriceBeep(String url){
        String partOfPrice=getElementsByTag(url, "script");
        int pos=partOfPrice.indexOf("ecomm_totalvalue: [");
        String precio=addTillCharacter(partOfPrice, "", pos, 19, ']');
        return precio;
    }
    
    private String getUrlImagenBeep(String url){
        String partOfImagen=getElementsByTag(url, "img");
        int pos=partOfImagen.indexOf("<img id=\"product-zoom\" src=\"");
        String imagen=addTillCharacter(partOfImagen, "", pos, 28, '"');
        return imagen;
    }
    
    private String getURLProductoBeep(String modelo, String url){
        int pos=url.indexOf("/productos");
        String finalURL=addTillCharacter(url, "https://www.beep.es", pos, 0, '"');
        pos=url.indexOf('"', pos);
        pos=url.indexOf("title=\"", pos);
        String posible=addTillCharacter(url, "", pos, 7, '"');
        if(compararPeticiones(posible, modelo)) return finalURL;
        else return null;
    }
}
