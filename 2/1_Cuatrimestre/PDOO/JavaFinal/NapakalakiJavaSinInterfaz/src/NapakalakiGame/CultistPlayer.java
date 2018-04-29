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
public class CultistPlayer extends Player {
    private static int totalCultistPlayers=0;
    private Cultist myCultistCard;
    public CultistPlayer(Player p, Cultist c){
        super(p);
        myCultistCard=c;
    }
    public int getCombatLevel(){
        return super.getCombatLevel();
    }
    protected int getOponentLevel(Monster m){
        return m.getCombatLevelAgainstCultisPlayer();
    }
    protected boolean shouldConvert(){
        return false;
    }
    private Treasure giveMeATreasure(){
        return super.stealTreasure();
    }
    private boolean canYouGiveMeATreasure(){
        if(super.getHiddenTreasures().size()!=0){
            return true;
        }
        else{
            return false;
        }
    }
    public static int getTotalCultistPlayers(){
        return totalCultistPlayers;
    }
    public String toString(){
        return "soy un cultist   "+myCultistCard+"-->"+super.toString();
    }
}
