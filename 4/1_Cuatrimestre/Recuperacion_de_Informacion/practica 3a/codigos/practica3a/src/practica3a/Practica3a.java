package practica3a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

import org.apache.tika.exception.TikaException;
import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.core.KeywordAnalyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.en.EnglishAnalyzer;
import org.apache.lucene.analysis.miscellaneous.PerFieldAnalyzerWrapper;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.IntPoint;
import org.apache.lucene.document.StoredField;
import org.apache.lucene.document.StringField;
import org.apache.lucene.document.TextField;
import org.apache.lucene.facet.FacetField;
import org.apache.lucene.facet.FacetsConfig;
import org.apache.lucene.facet.taxonomy.directory.DirectoryTaxonomyWriter;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.store.FSDirectory;


public class Practica3a {
    
    // Función que se encarga de asignar un analizador a cada campo
    private static Analyzer cargaAnalyzer() {
        
        Map<String, Analyzer> analyzer= new HashMap<>();
        
        /*analyzer.put("Authors", new StandardAnalyzer());
        analyzer.put("Link", new KeywordAnalyzer());*/
        
        analyzer.put("EID", new KeywordAnalyzer());
        
        analyzer.put("Title", new EnglishAnalyzer());
        analyzer.put("Source title", new EnglishAnalyzer());
        analyzer.put("Abstract", new EnglishAnalyzer());
        analyzer.put("Author keywords", new EnglishAnalyzer());
        analyzer.put("Index keywords", new EnglishAnalyzer());
        
        PerFieldAnalyzerWrapper pfaWrapper= new PerFieldAnalyzerWrapper(new StandardAnalyzer(), analyzer);
        
        return pfaWrapper;
    }
    
    // Función que extrae los campos de cada línea que se le pasa
    private static String extraeCampo (String linea, int[] pos) {
        
        String str = "";
        boolean fin = false;
        
        if (linea.charAt(pos[0])==44) // si empieza por , el campo está vacío
            pos[0]++;
        else if (linea.charAt(pos[0])=='\"') { // si empieza por "
            pos[0]++;
            while (!fin)
                // si hay 2 comillas dobles se sustituyen por 1
                if (linea.charAt(pos[0])=='\"' && linea.charAt(pos[0]+1)=='\"') {
                    str += '\"';
                    pos[0]+=2;
                // si hay comillas dobles, se ha acabado el campo
                } else if (linea.charAt(pos[0])=='\"') {
                    pos[0]+=2;
                    fin = true;
                } else {
                    str += linea.charAt(pos[0]);
                    pos[0]++;
                }
        } else { // en caso contrario
            while (!fin)
                // si hay una coma, se ha acabado el campo
                if (linea.charAt(pos[0])==44) {
                    pos[0]++;
                    fin = true;
                // si es el final de línea, se ha acabado el campo
                } else if (pos[0]==linea.length()-1) {
                    str += linea.charAt(pos[0]);
                    fin = true;
                } else {
                    str += linea.charAt(pos[0]);
                    pos[0]++;
                }
        }
        
        return str;
    }
    
    private static void incluyeFaceta(Document luceneDoc, String[] cadena, int campo, char delimitador, String faceta) {
        int i=0;
        if (!cadena[campo].isEmpty())
            while (i != cadena[campo].length()-1) {
                String cadenaAux = "";
                while (cadena[campo].charAt(i)!=delimitador && i != cadena[campo].length()-1) {
                    cadenaAux += cadena[campo].charAt(i);
                    i++;
                }
                if (i != cadena[campo].length()-1)
                    i+=2;
                else
                    cadenaAux += cadena[campo].charAt(i);

                luceneDoc.add (new FacetField ( faceta , cadenaAux ));
                //System.out.println(cadenaAux);
            }
    }
    
    // Función que crea un documento
    private static Document creaDocumento(String linea, int[] posicion, String[] cadena, int[] numero) {
        
        Document luceneDoc = new Document();
        
        cadena[0] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Authors", cadena[0], TextField.TYPE_STORED));

        cadena[1] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Title", cadena[1], TextField.TYPE_STORED));

        numero[0] = Integer.valueOf(extraeCampo(linea,posicion));
        luceneDoc.add(new IntPoint("Year", numero[0]));
        luceneDoc.add(new StoredField("Year", numero[0]));

        cadena[2] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Source title", cadena[2], TextField.TYPE_STORED));

        numero[1] = Integer.valueOf(extraeCampo(linea,posicion));
        luceneDoc.add(new IntPoint("Cited by", numero[1]));
        luceneDoc.add(new StoredField("Cited by", numero[1]));

        cadena[3] = extraeCampo(linea,posicion);
        luceneDoc.add(new StringField("Link", cadena[3], Field.Store.YES));

        cadena[4] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Abstract", cadena[4], TextField.TYPE_STORED));

        cadena[5] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Author keywords", cadena[5], TextField.TYPE_STORED));

        cadena[6] = extraeCampo(linea,posicion);
        luceneDoc.add(new Field("Index keywords", cadena[6], TextField.TYPE_STORED));

        cadena[7] = extraeCampo(linea,posicion);
        luceneDoc.add(new StringField("EID", cadena[7], Field.Store.YES));
        
        // Se incluyen las facetas
        
        incluyeFaceta (luceneDoc, cadena, 0, ',', "Authors");
        incluyeFaceta (luceneDoc, cadena, 5, ';', "Author keyboards");
        incluyeFaceta (luceneDoc, cadena, 6, ';', "Index keyboards");
        
        
        return luceneDoc;
    }
    
    // Función que muestra por consola los distintos campos de los documentos
    private static void muestraDocs(String[] cadena, int[] numero) {
        System.out.println("Authors: "+cadena[0]);
        System.out.println("Title: "+cadena[1]);
        System.out.println("Year: "+numero[0]);
        System.out.println("Source title: "+cadena[2]);
        System.out.println("Cited by: "+numero[1]);
        System.out.println("Link: "+cadena[3]);
        System.out.println("Abstract: "+cadena[4]);
        System.out.println("Author keywords: "+cadena[5]);
        System.out.println("Index keywords: "+cadena[6]);
        System.out.println("EID: "+cadena[7]);
    }
    
    private static int localizaUltimaAparicion (String cadena) {
        int i;
        for (i=cadena.length()-1; i>0 ; i--)
            if (cadena.charAt(i) == '/')
                return i;
        return i;
    }
    
    // Función que se ocupa de crear el índice
    private static void indexar(String carpeta) throws IOException, TikaException {
        
        File f = new File(carpeta);
        File [] ficheros;
        
        if(f.exists()){
            
            ficheros = f.listFiles();
            
            // Se crean las estructuras necesarias para crear los índices
            //FSDirectory dir = FSDirectory.open( Paths.get(carpeta+"/index") );            
            FSDirectory dir = FSDirectory.open( Paths.get(carpeta.substring(0, localizaUltimaAparicion(carpeta)) + "/index") );
            //FSDirectory taxoDir = FSDirectory.open(Paths.get(carpeta+"/categoryIndex"));
            FSDirectory taxoDir = FSDirectory.open( Paths.get(carpeta.substring(0, localizaUltimaAparicion(carpeta)) + "/categoryIndex") );
            
            IndexWriterConfig iwc = new IndexWriterConfig( cargaAnalyzer() );
            iwc.setOpenMode(IndexWriterConfig.OpenMode.CREATE);
            FacetsConfig fconfig = new FacetsConfig();
            
            fconfig.setMultiValued ( "Authors", true ) ;
            fconfig.setMultiValued ( "Author keyboards", true ) ;
            fconfig.setMultiValued ( "Index keyboards", true ) ;
            
            IndexWriter iw = new IndexWriter(dir, iwc);
            DirectoryTaxonomyWriter tw = new DirectoryTaxonomyWriter (taxoDir);
            
            Document luceneDoc;
            
            for (File fichero : ficheros) { // para cada fichero
                
                // Se crea un buffer y se lee una línea
                BufferedReader br;
                br = new BufferedReader(new FileReader(fichero.getAbsolutePath()));
                String linea = br.readLine(); // la primera lína no interesa porque contiene el nombre de los campos
                linea = br.readLine();
                
                String[] cadena = new String[8];
                int[] numero = new int[2];
                
                while (linea!=null) { // para cada línea
                    
                    int[] posicion = new int[1];
                    posicion[0] = 0; // posición por la que se va leyendo
                    
                    // Se crea el documento y se incluye en el índice
                    luceneDoc = creaDocumento(linea, posicion, cadena, numero);
                    //iw.addDocument(luceneDoc);
                    iw.addDocument(fconfig.build(tw, luceneDoc));
                    
                    //muestraDocs(cadena, numero);
                    
                    linea=br.readLine();
                }
            }
            
            iw.commit();
            tw.commit();
            
            iw.close();
            tw.close();
        }
    }
    
    public static void main(String[] args) throws IOException, TikaException {
        indexar(args[0]);
    }
}
