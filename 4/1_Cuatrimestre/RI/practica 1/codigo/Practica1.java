/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica1;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.Charset;
import org.apache.tika.Tika;
import org.apache.tika.parser.Parser;
import org.apache.tika.parser.ParseContext;
import org.apache.tika.parser.AutoDetectParser;
import org.apache.tika.metadata.Metadata;


import org.apache.tika.language.detect.LanguageDetector;
import org.apache.tika.sax.BodyContentHandler;
import org.apache.tika.sax.LinkContentHandler;
import org.apache.tika.sax.XHTMLContentHandler;
import org.apache.tika.sax.Link;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.List;

import org.apache.tika.detect.AutoDetectReader;
import org.apache.tika.exception.TikaException;
import org.apache.tika.langdetect.OptimaizeLangDetector;
import org.apache.tika.language.detect.LanguageResult;

import java.io.BufferedWriter;
import java.io.FileWriter;

import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Iterator;
import java.util.Map;

public class Practica1 {

    public static  String identifyLanguage(String text) throws IOException {
        LanguageDetector identifier  = new  OptimaizeLangDetector().loadModels();
        LanguageResult idioma = identifier.detect(text);
        return idioma.getLanguage();
    }
    
    public static void process(File file) throws Exception {
        Parser parser = new AutoDetectParser();
        Metadata metadata = new Metadata();
        LinkContentHandler handler = new LinkContentHandler();

        InputStream stream = new FileInputStream(file);
        System.out.println("seleccionando links ");
        try {
            parser.parse(stream, handler, metadata,new ParseContext());
        }
        finally {
            stream.close();
        }
        List<Link> lista  = new LinkedList<Link>();

        lista = handler.getLinks();
        for (Link enlace : lista) {
            System.out.println("link: "+enlace.toString()); 
        }
    }
    
    public static String nextWord(HashMap<String, Integer>cont){
        String palabra=null;
        int n=0;
        Iterator it = cont.entrySet().iterator();
        while(it.hasNext()){
            Map.Entry pair=(Map.Entry)it.next();
            int v=(int) pair.getValue();
            if(v>n){
                palabra=(String)pair.getKey();
                n=(int)pair.getValue();
            }
        }
        return palabra;
    }
    
    public static void processOcurrencias(File f) throws IOException, TikaException{
        Tika tika = new Tika();
        HashMap<String, Integer > contenido=new HashMap<String, Integer>();
        String text = tika.parseToString(f);
        String palabra="";
        for(int i=0;i<text.length();i++){
            if(text.charAt(i)==' ' || text.charAt(i)==',' || text.charAt(i)=='*' || text.charAt(i)==' ' || text.charAt(i)==' ' || text.charAt(i)=='?' || text.charAt(i)=='¿' || text.charAt(i)=='!' || text.charAt(i)=='–' || text.charAt(i)=='¡' || text.charAt(i)=='.' || text.charAt(i)=='\n' || text.charAt(i)=='-' || text.charAt(i)==':' || text.charAt(i)==';' || text.charAt(i)=='_' || text.charAt(i)=='(' || text.charAt(i)==')' || text.charAt(i)==60 || text.charAt(i)==62 || text.charAt(i)=='\t'){
                if(contenido.containsKey(palabra)){
                    int value=contenido.get(palabra);
                    value++;
                    contenido.replace(palabra, value);
                    palabra="";
                }
                else{
                    if(!palabra.equals("")) contenido.put(palabra, 1);
                }
            }
            else{
                String a="";
                a=a+text.charAt(i);
                palabra=palabra+a.toLowerCase();
            }
        }
        
        String rutaArchivo=f.getAbsolutePath()+"__ocurrencias.txt";
        String rutaArchivo2=f.getAbsolutePath()+"__ocurrencias2.txt";
        File archivo=new File(rutaArchivo);
        File archivo2=new File(rutaArchivo2);
        BufferedWriter buffer, buffer2;
        if(archivo.exists()){
            buffer=new BufferedWriter(new FileWriter(archivo));
        }
        else{
            buffer=new BufferedWriter(new FileWriter(archivo));
        }
        if(archivo2.exists()){
            buffer2=new BufferedWriter(new FileWriter(archivo2));
        }
        else{
            buffer2=new BufferedWriter(new FileWriter(archivo2));
        }
        String p;
        int cont=1;
        while((p=nextWord(contenido))!=null){
            buffer.write(p+": "+contenido.get(p)+"\r\n");
            buffer2.write(cont+"\t"+contenido.get(p)+"\r\n");
            cont++;
            contenido.remove(p);
        }
        buffer.close();
    }
    
    
    
    public static void main(String[] args) throws IOException, TikaException, Exception {
        File f=new File(args[0]);
        Tika tika = new Tika();
        if(f.exists()){
            File [] ficheros=f.listFiles();
            for(int i=0;i<ficheros.length;i++){
                //********************************PRIMERA PARTE**************************
                System.out.println(ficheros[i].getAbsolutePath());
                File f2 = new File(ficheros[i].getAbsolutePath());
                String type=tika.detect(f2);
                System.out.println("Tipo: "+type);
                InputStream is = new FileInputStream(f2);   
                AutoDetectReader detector = new AutoDetectReader(is);
                Charset charSet = detector.getCharset();
                System.out.println("Codificacion: "+ charSet.toString());
                Metadata met = new Metadata();
                String aux = tika.parseToString(is, met);
                String text = tika.parseToString(f2);
                System.out.println("lenguaje: "+identifyLanguage(text)+"\n");
                //*********************************SEGUNDA PARTE***************************
                process(f2);
                System.out.println("\n\n\n");
                //**********************************TERCERA PARTE**************************
                processOcurrencias(f2);
            }
        }
        else{
            System.out.println("El directorio no existe");
        }
        
        
    }
    
}
