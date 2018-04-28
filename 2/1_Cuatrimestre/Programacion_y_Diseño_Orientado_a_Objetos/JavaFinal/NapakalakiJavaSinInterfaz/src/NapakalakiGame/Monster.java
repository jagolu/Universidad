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
public class Monster {
    private String name;
    private int combatLevel;
    private Prize prize;
    private BadConsequence badConsequence;
    private int levelChangeAgainstCultisPlayer=0;
    Monster(String n, int l, BadConsequence b, Prize p){
        name=n;
        combatLevel=l;
        badConsequence=b;
        prize=p;
    }
    Monster(String n, int l, BadConsequence badConsequence, Prize p, int IC){
        name=n;
        combatLevel=l;
        this.badConsequence=badConsequence;
        prize=p;
        levelChangeAgainstCultisPlayer=IC;
    }
    public String getName(){
        return name;
    }
    public int getCombatLevel(){
        return combatLevel;
    }
    public BadConsequence getBadConsequence(){
        return badConsequence;
    }
    public int getLevelsGained(){
        return prize.getLevel();
    }
    public int getTreasuresGained(){
        return prize.getTreasures();
    }
    public int getCombatLevelAgainstCultisPlayer(){
        return combatLevel+levelChangeAgainstCultisPlayer;
    }
    
    public String toString(){
        return name+ " level->"+combatLevel+" prize->"+prize.toString()+" badConsequence->"+badConsequence.toString();
    }
    public Prize getPrize(){
        return prize;
    }
}
