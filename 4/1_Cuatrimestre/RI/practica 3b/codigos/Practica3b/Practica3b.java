package practica3b;

import java.io.IOException;
import java.nio.file.Paths;
import org.apache.lucene.document.Document;
import org.apache.lucene.facet.DrillDownQuery;
import org.apache.lucene.facet.FacetResult;
import org.apache.lucene.facet.Facets;
import org.apache.lucene.facet.FacetsCollector;
import org.apache.lucene.facet.FacetsConfig;
import org.apache.lucene.facet.LabelAndValue;
import org.apache.lucene.facet.taxonomy.FastTaxonomyFacetCounts;
import org.apache.lucene.facet.taxonomy.TaxonomyReader;
import org.apache.lucene.facet.taxonomy.directory.DirectoryTaxonomyReader;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.Term;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;

public class Practica3b {
    
    private static Facets devuelveFacetas (TaxonomyReader taxoReader, FacetsCollector fc) throws IOException {

        FacetsConfig fconfig = new FacetsConfig();
        Facets facetas = new FastTaxonomyFacetCounts(taxoReader,fconfig,fc);
        
        return facetas;
    }
    
    private static void muestraDocs(IndexSearcher searcher, TopDocs td) throws IOException {
        System.out.println("\nResultado de la búsqueda:");
        System.out.println("Nº de resultados: " + td.totalHits);
        for (ScoreDoc scoreDoc: td.scoreDocs) {
            Document doc = searcher.doc(scoreDoc.doc);
            System.out.println(scoreDoc.score + " --> " + doc.get("Authors") + " - " + doc.get("Title") + " - " + doc.get("Author keywords"));
        }
    }
    
    private static void muestraFacetas (FacetResult faceta) {
        System.out.println("\n*Faceta: " + faceta.dim + "--> " + faceta.value);
        LabelAndValue[] valores = faceta.labelValues;
        for (LabelAndValue valor: valores)
            System.out.println(valor.label + "(" + valor.value + ")");
    }
    
    private static void busqueda (IndexSearcher searcher, TaxonomyReader taxoReader, TopDocs[] tds, FacetsCollector[] fcs, Facets[] facets, DrillDownQuery ddq, int num) throws IOException {
        tds[num] = FacetsCollector.search(searcher, ddq, 10, fcs[num]);
        muestraDocs(searcher,tds[num]);
        facets[num] = devuelveFacetas (taxoReader, fcs[num]);
    }
    
    private static void restringe (IndexSearcher searcher, TaxonomyReader taxoReader, String[] categorias, FacetResult[] dimensiones, TopDocs[] tds, FacetsCollector[] fcs, Facets[] facets, DrillDownQuery ddq, int num, int seleccionado) throws IOException {
        //ddq.add(dimensiones[0].dim, dimensiones[0].labelValues[0].label);
        
        busqueda (searcher, taxoReader, tds, fcs, facets, ddq, num);
        
        switch (seleccionado) {
            case 0:
                for (int i=0; i<3; i++) {
                    dimensiones[i] = facets[0].getTopChildren(5,categorias[i]);
                    muestraFacetas (dimensiones[i]);
                }   break;
            case 1:
                for (int i=1; i<3; i++) {
                    dimensiones[i] = facets[1].getTopChildren(5,categorias[i]);
                    muestraFacetas (dimensiones[i]);
                }   break;
            case 2:
                dimensiones[0] = facets[2].getTopChildren(5,categorias[0]);
                muestraFacetas (dimensiones[0]);
                dimensiones[2] = facets[2].getTopChildren(5,categorias[2]);
                muestraFacetas (dimensiones[2]);
                break;
            case 3:
                for (int i=0; i<2; i++) {
                    dimensiones[i] = facets[3].getTopChildren(5,categorias[i]);
                    muestraFacetas (dimensiones[i]);
                }   break;
            default:
                break;
        }
        
    }
    
    public static void main(String[] args) throws IOException, ParseException {
        
        Directory dir = FSDirectory.open(Paths.get(args[0]+"/index"));
        IndexReader reader = DirectoryReader.open(dir);
        IndexSearcher searcher = new IndexSearcher(reader);
        
        Directory taxoDir = FSDirectory.open(Paths.get(args[0]+"/categoryIndex"));
        TaxonomyReader taxoReader = new DirectoryTaxonomyReader(taxoDir);
        
        String[] categorias = {"Authors", "Author keywords", "Index keywords"};
        FacetResult[] dimensiones = new FacetResult[3];
        FacetsCollector[] fcs = {new FacetsCollector(), new FacetsCollector(), new FacetsCollector(), new FacetsCollector()};
        TopDocs[] tds = {null, null, null, null};
        Facets[] facets = {null, null, null, null};
        int seleccionado = 0;
        
        Query query = new TermQuery(new Term("Title","opinion"));
        
        FacetsConfig fconfig = new FacetsConfig();
        DrillDownQuery ddq = new DrillDownQuery (fconfig,query);
       
        restringe (searcher, taxoReader, categorias, dimensiones, tds, fcs, facets, ddq, 0, seleccionado);
        /*busqueda (searcher, taxoReader, tds, fcs, facets, ddq, 0);
        for (int i=0; i<3; i++) {
            dimensiones[i] = facets[0].getTopChildren(5,categorias[i]);
            muestraFacetas (dimensiones[i]);
        }*/
        
        System.out.println("\nElijo el primer autor para filtrar los resultados <-------------------------------------------");
        
        seleccionado = 1;
        ddq.add(dimensiones[0].dim, dimensiones[0].labelValues[0].label);
        
        restringe (searcher, taxoReader, categorias, dimensiones, tds, fcs, facets, ddq, 1, seleccionado);
        /*busqueda (searcher, taxoReader, tds, fcs, facets, ddq, 1);
        for (int i=1; i<3; i++) {
            dimensiones[i] = facets[1].getTopChildren(5,categorias[i]);
            muestraFacetas (dimensiones[i]);
        }*/
        
        System.out.println("\nElijo el primer autor keyword para filtrar los resultados <------------------------------------");
        
        ddq.add(dimensiones[1].dim, dimensiones[1].labelValues[0].label);
        
        busqueda (searcher, taxoReader, tds, fcs, facets, ddq, 2);
        dimensiones[2] = facets[2].getTopChildren(5,categorias[2]);
        muestraFacetas (dimensiones[2]);
        
        /*
        ddq.add(dimensiones[2].dim, dimensiones[2].labelValues[0].label);
        busqueda (searcher, taxoReader, tds, fcs, facets, ddq, 3);
        */
        
        
        /*Query q3, q4;

        q3 = new TermQuery(new Term("Title","opinion"));
        q4 = new TermQuery(new Term("Title","sentiment"));
        
        BooleanClause bc1 = new BooleanClause(q3, BooleanClause.Occur.MUST);
        BooleanClause bc2 = new BooleanClause(q4, BooleanClause.Occur.MUST);
        
        BooleanQuery.Builder bqbuilder = new BooleanQuery.Builder();
        bqbuilder.add(bc1);
        bqbuilder.add(bc2);
        
        BooleanQuery bq = bqbuilder.build();
        
        SortField sf = new SortField("Year", SortField.Type.INT,true);
        sf.setMissingValue(0);
        Sort orden = new Sort(sf);
        
        TopFieldCollector tfcollector = TopFieldCollector.create(orden, 10, false, true, false);
        searcher.search(bq, tfcollector);
        
        TopFieldDocs tfd = tfcollector.topDocs();
        
        System.out.println("Número de resultados: " + tfcollector.getTotalHits());
        for (ScoreDoc hit : tfd.scoreDocs) {
            Document d = searcher.doc(hit.doc);
            System.out.println (d.get("Year") + " - Libro: " + d.get("Title") + " - " + hit.score);
        }*/
    }
    
}
