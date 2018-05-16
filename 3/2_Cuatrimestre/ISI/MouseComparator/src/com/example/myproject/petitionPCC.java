package com.example.myproject;

public class petitionPCC extends MouseComparatorServlet{
    public void checkPCC(String modelo, MouseComparator cb){
        String url=callURLPCC(modelo);
        if(stringNotNullNotEmpty(url)){
            String urlProducto=getURLProductoPCC(url, modelo);
            cb.setUrlPCC(urlProducto);
            cb.setPrecioPCC(getPricePCC(urlProducto));
            cb.setUrlImagenPCC(getUrlImagenPCC(urlProducto));
        }
        else{
            cb.setPrecioPCC("");
            cb.setUrlPCC("");
            cb.setUrlImagenPCC("");
        }
    }
    
    private String callURLPCC(String modelo){
        String url="https://www.pccomponentes.com/buscar/?query=";
        String [] palabras=initializeStringArrayToVoid(50);
        int numPalabras=countWords(modelo, palabras);
        url=addWordsToURL(url, numPalabras, palabras, "+");
        url=conectarURL(url);
        if(!url.contains("No hay resultados")) return url;
        else return null;
    }
    
    private String getPricePCC(String url){
        String partOfPrice=getElementsByTag(url, "script");
        int pos=partOfPrice.indexOf("'price': ");
        String precio=addTillCharacter(partOfPrice, "", pos, 10, '\'');
        return precio;
    }
    
    private String getUrlImagenPCC(String url){
        String partOfImagen=getSelect(url, "a.fancybox");
        int pos=partOfImagen.indexOf("a class=\"fancybox\" data-fancybox-group=\"gallery\" href=\"https://img.pccomponentes.com");
        String imagen=addTillCharacter(partOfImagen, "http://", pos, 59, '"');
        return imagen;
    }
    
    private String getURLProductoPCC(String url, String modelo){
        int pos=url.indexOf("<a itemprop=\"url\" href=\"");
        String finalURL=addTillCharacter(url, "https://www.pccomponentes.com", pos, 24, '"');
        pos=url.indexOf("data-name");
        String posible=addTillCharacter(url, "", pos, 11, '"');
        if(compararPeticiones(posible, modelo)) return finalURL;
        else return null;
    }
}
