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
public class NumericBadConsequence extends BadConsequence{
    private int nVisibleTreasures;
    private int nHiddenTreasures;
    NumericBadConsequence(String text, int level, int nVisibleTreasures, int nHiddenTreasures){
        super(text,level);
        this.nHiddenTreasures=nHiddenTreasures;
        this.nVisibleTreasures=nVisibleTreasures;
    }
    public int getNVisibleTreasures(){
        return nVisibleTreasures;
    }
    public int getNHiddenTreasures(){
        return nHiddenTreasures;
    }
    public void substratHiddenTreasure(Treasure t){
        if(nHiddenTreasures!=0){
            nHiddenTreasures--;
        }
    }
    public void substractVisibleTreasure(Treasure t){
        if(nVisibleTreasures!=0){
            nVisibleTreasures--;
        }
    }
    public BadConsequence adjustToFitTreasureLists(ArrayList <Treasure> v, ArrayList <Treasure> h){
        BadConsequence pbc=null;
        int nvt=0;
        int nht=0;
        if(nVisibleTreasures!=0 || nHiddenTreasures!=0){
            if(nVisibleTreasures>v.size())nvt=v.size();
            else nvt=nVisibleTreasures;
            if(nHiddenTreasures>h.size())nht=h.size();
            else nht=nHiddenTreasures;
            pbc=new NumericBadConsequence("", 0, nvt, nht);
        }
        System.out.println(nvt +"  " +nht);
        return pbc;
    }
    public String toString(){
        return super.toString()+"   "+nVisibleTreasures +"  " +nHiddenTreasures;
    }
    public boolean isEmpty(){
        if(nVisibleTreasures==0 && nHiddenTreasures==0){
            return true;
        }
        else{
            return false;
        }
    }
}
