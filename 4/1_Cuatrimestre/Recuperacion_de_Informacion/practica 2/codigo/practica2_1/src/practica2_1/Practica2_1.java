/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica2_1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import org.apache.tika.Tika;
import org.apache.tika.exception.TikaException;
import org.apache.tika.parser.Parser;
//import org.apache.lucene.analysis.Token;
import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.standard.ClassicAnalyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.standard.UAX29URLEmailAnalyzer;
import org.apache.lucene.analysis.es.SpanishAnalyzer;
import org.apache.lucene.analysis.en.EnglishAnalyzer;
import org.apache.lucene.analysis.fr.FrenchAnalyzer;
import org.apache.lucene.analysis.fi.FinnishAnalyzer;
import org.apache.lucene.analysis.core.StopAnalyzer;
import org.apache.lucene.analysis.core.SimpleAnalyzer;
import org.apache.lucene.analysis.core.WhitespaceAnalyzer;


import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.analysis.tokenattributes.OffsetAttribute;


import org.apache.lucene.util.Version;

import java.io.IOException;
import java.io.StringReader;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import org.apache.lucene.analysis.core.LowerCaseFilterFactory;
import org.apache.lucene.analysis.core.StopFilterFactory;
import org.apache.lucene.analysis.core.WhitespaceTokenizerFactory;
import org.apache.lucene.analysis.custom.CustomAnalyzer;
import org.apache.lucene.analysis.standard.StandardFilterFactory;

import org.apache.lucene.analysis.standard.StandardTokenizer;
import org.apache.lucene.analysis.standard.StandardTokenizerFactory;
import org.apache.tika.langdetect.OptimaizeLangDetector;
import org.apache.tika.language.detect.LanguageDetector;
import org.apache.tika.language.detect.LanguageResult;



/**
 *
 * @author Javi
 */
public class Practica2_1 {

    
public static  String identifyLanguage(String text) throws IOException {
    LanguageDetector identifier  = new  OptimaizeLangDetector().loadModels();
    LanguageResult idioma = identifier.detect(text);
    return idioma.getLanguage();
}    
    
public static List<String> tokenizeString(Analyzer analyzer, String string) {
    List<String> result = new ArrayList<String>();

    String cad;
    try {
        
        TokenStream stream  = analyzer.tokenStream(null, new StringReader(string));
        //OffsetAttribute offsetAtt = stream.addAttribute(OffsetAttribute.class);
        CharTermAttribute cAtt= stream.addAttribute(CharTermAttribute.class);
        stream.reset();
        
        while (stream.incrementToken()) {
          //cad = stream.getAttribute(CharTermAttribute.class).toString();
          result.add(cAtt.toString());
        }
        stream.close();
        stream.end();
    } catch (IOException e) {
      // not thrown b/c we're using a string reader...
        throw new RuntimeException(e);
    }
    return result;
}
    
    
public static void process(List<String> l, String name) throws IOException{
    HashMap<String, Integer > contenido=new HashMap<String, Integer>();
    for(int i=0;i<l.size();i++){
        if(contenido.containsKey(l.get(i))){
            int value=contenido.get(l.get(i));
            value++;
            contenido.replace(l.get(i), value);
        }
        else{
            contenido.put(l.get(i), 1);
        }
    }
    TreeMap<Integer, List<String> > contenido2=new TreeMap<Integer, List<String> >(java.util.Collections.reverseOrder());
    Iterator it=contenido.entrySet().iterator();
    while(it.hasNext()){
        Map.Entry e=(Map.Entry)it.next();
        int n=(Integer)e.getValue();
        String s=(String)e.getKey();
        if(contenido2.containsKey(n)){
            List<String> a=contenido2.get(n);
            a.add(s);
            contenido2.put(n, a);
        }
        else{
            List<String> a=new ArrayList<String>();
            a.add(s);
            contenido2.put(n, a);
        }
    }
    File archivo=new File(name+".txt");
    File archivo2=new File(name+"2.txt");
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
    Iterator it2=contenido2.entrySet().iterator();
    while(it2.hasNext()){
        Map.Entry e=(Map.Entry)it2.next();
        int n=(Integer)e.getKey();
        List<String> l2=(List<String>)e.getValue();
        for(int i=0;i<l2.size();i++){
            buffer.write(l2.get(i)+": "+n+"\r\n");
            buffer2.write(cont+"\t"+n+"\r\n");
            cont++;
        }
    }
    buffer.close();
}   
    
public static void main(String[] args) throws IOException, TikaException {
    Analyzer [] analizadores = {
        new WhitespaceAnalyzer(),
        new SimpleAnalyzer(),
        new StandardAnalyzer(),
        new EnglishAnalyzer(),
        new FrenchAnalyzer(),
        new FinnishAnalyzer(),
        CustomAnalyzer.builder(Paths.get(""))
            .withTokenizer(StandardTokenizerFactory.class)
            .addTokenFilter(LowerCaseFilterFactory.class)       
            .addTokenFilter(StopFilterFactory.class, "words", "C:\\Users\\Javi\\Desktop\\RI\\practica2\\stopwords.txt" /*, "ignoreCase", "false", "words", "stopwords.txt", "format", "wordset"*/)
            .build()
        };
    File f=new File(args[0]);
    Tika tika = new Tika();
    if(f.exists()){
        File [] ficheros=f.listFiles();
        for(int i=0;i<ficheros.length;i++){
            System.out.println(ficheros[i].getAbsolutePath());
        }
        for(int i=0;i<ficheros.length;i++){
            File f2 = new File(ficheros[i].getAbsolutePath());
            String text = tika.parseToString(f2);
            String language=identifyLanguage(text);
            List<String> result=new ArrayList<String>();
            String name=ficheros[i].getAbsolutePath();
            if(name.indexOf(".java")!=-1){
                result=tokenizeString(analizadores[6], text);
                process(result, ficheros[i].getAbsolutePath()+"_codeAnalyzer.txt");
            }
            else if(name.indexOf(".java")==-1)
                for(int j=0;j<analizadores.length-1;j++){
                    List<String> result2=new ArrayList<String>();
                    result2=tokenizeString(analizadores[i], text);
                    if(j==0) process(result2, name+"_WhitespaceAnalyzer");
                    else if(j==1) process(result2, name+"_SimpleAnalyzer");
                    else if(j==2) process(result2, name+"_StandardAnalyzer");
                    else if(j==3 && language.equals("en")) process(result2, name+"_englishAnalyzer");
                    else if(j==4 && language.equals("fr")) process(result2, name+"_frenchAnalyzer");
                    else if(j==5 && language.equals("fi")) process(result2, name+"_finnishAnalyzer");
                }
            }
        }
    }
}
    

