/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author Javi
 */
public class SpecificBadConsequence extends BadConsequence{
    private ArrayList<TreasureKind> specificHiddenTreasures=new ArrayList();
    private ArrayList<TreasureKind> specificVisibleTreasures=new ArrayList();
    SpecificBadConsequence(String text, int levels, ArrayList<TreasureKind>svt, ArrayList<TreasureKind>sht){
        super(text,levels);
        specificHiddenTreasures=sht;
        specificVisibleTreasures=svt;
    }
    public ArrayList<TreasureKind> getSpecificHiddenTreasures(){
        return specificHiddenTreasures;
    }
    public ArrayList<TreasureKind> getSpecificVisibleTreasures(){
        return specificVisibleTreasures;
    }
    public void substractVisibleTreasure(Treasure t){
        if(!specificVisibleTreasures.isEmpty()){
            int i=0;
            boolean encontrado=false;
            for(TreasureKind t2: specificVisibleTreasures){
                if(t2==t.getType() && encontrado==false){
                    encontrado=true;
                }
            }
            if(encontrado){
                specificVisibleTreasures.remove(t.getType());
            }
        }
    }
    public void substratHiddenTreasure(Treasure t){
        if(!specificHiddenTreasures.isEmpty()){
            boolean encontrado=false;
            for(TreasureKind t2: specificHiddenTreasures){
                if(t2==t.getType() && encontrado==false){
                    encontrado=true;
                }
            }
            if(encontrado){
                specificHiddenTreasures.remove(t.getType());
            }
        }
    }
    public boolean isEmpty(){
        if(specificHiddenTreasures.isEmpty() && specificVisibleTreasures.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }
    private ArrayList<TreasureKind> adjustTreasures(ArrayList<TreasureKind>a, ArrayList<Treasure>b){
        ArrayList<TreasureKind>a2=new ArrayList(a);
        ArrayList<TreasureKind>treasures=new ArrayList();
        for(TreasureKind tk:a2){
            boolean encontrado=false;
            int i=0;
            for(Treasure t:b){
                if(t.getType()==tk && !encontrado){
                    encontrado=true;
                    treasures.add(tk);
                    a.remove(i);
                }
            }
            i++;
        }
        return treasures;     
    }
    public BadConsequence adjustToFitTreasureLists(ArrayList <Treasure> v, ArrayList <Treasure> h){
        BadConsequence pbc=null;
        ArrayList<TreasureKind>svt=new ArrayList();
        ArrayList<TreasureKind>sht=new ArrayList();
        if(!specificVisibleTreasures.isEmpty() || !specificHiddenTreasures.isEmpty()){
            svt=adjustTreasures(specificVisibleTreasures,v);
            sht=adjustTreasures(specificHiddenTreasures,h);
            pbc=new SpecificBadConsequence("", 0, svt, sht);
        }
        System.out.println(svt);
        System.out.println(sht);
        return pbc;
    }
    public String toString(){
        
        return super.toString()+"   "+specificVisibleTreasures +" " +specificHiddenTreasures;
    }
}
