/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package practica3b;

import interfaz.pillar_rutas;
import interfaz.VistaPrincipal;
import interfaz.resultados;

import java.io.IOException;
import java.io.StringReader;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.index.Term;
import org.apache.lucene.search.BooleanClause;
import org.apache.lucene.search.BooleanQuery;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.analysis.en.EnglishAnalyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.IntPoint;
import org.apache.lucene.facet.DrillDownQuery;
import org.apache.lucene.facet.FacetResult;
import org.apache.lucene.facet.Facets;
import org.apache.lucene.facet.FacetsCollector;
import org.apache.lucene.facet.FacetsConfig;
import org.apache.lucene.facet.LabelAndValue;
import org.apache.lucene.facet.taxonomy.FastTaxonomyFacetCounts;
import org.apache.lucene.facet.taxonomy.TaxonomyReader;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.Sort;
import org.apache.lucene.search.SortField;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.search.TopFieldCollector;
import org.apache.lucene.search.TopFieldDocs;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import sun.java2d.SurfaceData;


public class Practica3b {
    
    public static boolean isNumeric(String cadena){
        try{
            Integer.parseInt(cadena);
            return true;
        }catch(NumberFormatException nfe){
            return false;
        }
    }
    
    public static TopDocs busquedaAuthor(IndexSearcher is, String tipo, String tipo_year, String authors, Integer num1, Integer num2, FacetsCollector fc) throws IOException{
        Analyzer analizador=new StandardAnalyzer();
        List<String> palabras=new ArrayList<String>();
        try{
            TokenStream stream=analizador.tokenStream(null, new StringReader(authors));
            CharTermAttribute catt=stream.addAttribute(CharTermAttribute.class);
            stream.reset();
            while(stream.incrementToken()){
                palabras.add(catt.toString());
            }
            stream.close();
            stream.end();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
        ArrayList <BooleanClause>bc=new ArrayList<BooleanClause>();
        for(int i=0;i<palabras.size();i++){
            Query query = new TermQuery(new Term("Authors",palabras.get(0)));
            if(tipo.equals("should")) bc.add(new BooleanClause(query, BooleanClause.Occur.SHOULD));
            else if(tipo.equals("must")) bc.add(new BooleanClause(query, BooleanClause.Occur.MUST));
        }
        BooleanQuery.Builder bqbuilder=new BooleanQuery.Builder();
        for(int i=0;i<bc.size();i++){
            bqbuilder.add(bc.get(i));
        }
        if(num1!=null){
            Query q;
            if(num2==null){
                q=IntPoint.newExactQuery("Year", num1);
                bqbuilder.add(q, BooleanClause.Occur.MUST);
            }
            else{
                if(tipo_year.equals("range")){
                    q=IntPoint.newRangeQuery("Year", num1, num2);
                    bqbuilder.add(q, BooleanClause.Occur.MUST);
                }
                else{
                    q=IntPoint.newSetQuery("Year", num1, num2);
                    bqbuilder.add(q, BooleanClause.Occur.MUST);
                }
            }  
        }
        BooleanQuery bq=bqbuilder.build();
        fc=new FacetsCollector();
        TopDocs td=FacetsCollector.search(is, bq, 10, fc);
        for (ScoreDoc scoreDoc: td.scoreDocs) {
            Document doc = is.doc(scoreDoc.doc);
            System.out.println(scoreDoc.score + " - " + doc.get("Authors") + " - " + doc.get("Title")+" - Year: "+doc.get("Year"));
        }
        return td;
    }
    //tipo_busqueda==1 para title
    //tipo_busqueda==2 para author
    //tipo_busqueda==3 para abstract
    public static ArrayList<BooleanClause> createClause(String busqueda, int tipo_busqueda, String tipo){
        Analyzer analizador;
        List<String> palabras=new ArrayList<String>();
        if(tipo_busqueda==1){
            analizador=new EnglishAnalyzer();
        }
        else if(tipo_busqueda==2){
            analizador=new StandardAnalyzer();
        }
        else{
            analizador=new EnglishAnalyzer();
        }
        try{
            TokenStream stream=analizador.tokenStream(null, new StringReader(busqueda));
            CharTermAttribute catt=stream.addAttribute(CharTermAttribute.class);
            stream.reset();
            while(stream.incrementToken()){
                palabras.add(catt.toString());
            }
            stream.close();
            stream.end();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
        
        ArrayList <BooleanClause>bc=new ArrayList<BooleanClause>();
        for(int i=0;i<palabras.size();i++){
            Query q;
            if(tipo_busqueda==1) q=new TermQuery(new Term("Title", palabras.get(i))); 
            else if(tipo_busqueda==2) q=new TermQuery(new Term("Authors", palabras.get(i)));
            else q=new TermQuery(new Term("Abstract", palabras.get(i)));
            if(tipo.equals("should")) bc.add(new BooleanClause(q, BooleanClause.Occur.SHOULD));
            else if(tipo.equals("must")) bc.add(new BooleanClause(q, BooleanClause.Occur.MUST));
        }
        return bc;
    }
    //tipo_year=range && tipo_year=set
    public static TopDocs busqueda(IndexSearcher searcher, String tipo_orden,String tipo, String tipo_year, String title, String the_abstract, Integer num1, Integer num2) throws IOException{
        BooleanQuery.Builder bqbuilder=new BooleanQuery.Builder();
        if(title!=null && !title.equals("")){
            ArrayList<BooleanClause> bc=createClause(title, 1, tipo);
            for(int i=0;i<bc.size();i++){
                bqbuilder.add(bc.get(i));
            }
        }
        else if(the_abstract!=null && !the_abstract.equals("")){
            ArrayList<BooleanClause> bc=createClause(the_abstract, 3, tipo);
            for(int i=0;i<bc.size();i++){
                bqbuilder.add(bc.get(i));
            }
        }
        
        if(num1!=null){
            Query q;
            if(num2==null){
                q=IntPoint.newExactQuery("Year", num1);
                bqbuilder.add(q, BooleanClause.Occur.MUST);
            }
            else{
                if(tipo_year.equals("range")){
                    q=IntPoint.newRangeQuery("Year", num1, num2);
                    bqbuilder.add(q, BooleanClause.Occur.MUST);
                }
                else{
                    q=IntPoint.newSetQuery("Year", num1, num2);
                    bqbuilder.add(q, BooleanClause.Occur.MUST);
                }
            }  
        }
        if(!tipo_orden.equals("score")){
            SortField sf = new SortField("Year", SortField.Type.INT,true);
            sf.setMissingValue(0);
            Sort orden = new Sort(sf);
            TopFieldCollector tfcollector = TopFieldCollector.create(orden, 10, false, true, false);
            BooleanQuery bq=bqbuilder.build();
            searcher.search(bq, tfcollector);
            TopFieldDocs tfd = tfcollector.topDocs();
            return tfd;
        }
        else{
            BooleanQuery bq=bqbuilder.build();
            TopDocs tdocs=searcher.search(bq,10);
            return tdocs;
        }
    }
    
    public static void main(String[] args) throws IOException {
        pillar_rutas pr=new pillar_rutas();
        pr.setVisible(true);
        /*VistaPrincipal vp=new VistaPrincipal();
        vp.setRutas("C:\\index", "C:\\categoryIndex");
        vp.setVisible(true);*/
    }
}
