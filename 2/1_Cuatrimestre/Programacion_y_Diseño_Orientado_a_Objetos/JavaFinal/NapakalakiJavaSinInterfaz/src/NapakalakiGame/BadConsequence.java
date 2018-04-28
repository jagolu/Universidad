/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

import java.util.ArrayList;

/**
 *
 * @author javigomez
 */
public abstract class BadConsequence {
    static int MAXTREASURES=10;
    private String text;
    private int levels;
    
    public abstract boolean isEmpty();
    public int getLevels(){
        return levels;
    }
    
    public abstract void substractVisibleTreasure(Treasure t);
    public abstract void substratHiddenTreasure(Treasure t);
    
    public abstract BadConsequence adjustToFitTreasureLists(ArrayList <Treasure> v, ArrayList <Treasure> h);
    public String toString(){
        return text+"   niveles->"+levels;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public String getText(){
            return text;
    }
    public BadConsequence(String texto, int levels){
        this.text=texto;
        this.levels=levels;
    }
}