/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;

/**
 *
 * @author javigomez
 */
public class Prize {
    private int treasures;
    private int level;
    
    public Prize(int t, int l){
        treasures=t;
        level=l;
    }
    public int getTreasures(){
        return treasures;
    }
    public int getLevel(){
        return level;
    }
    public String toString(){
        return "level->"+level+" treasures->"+treasures;
    }
}
