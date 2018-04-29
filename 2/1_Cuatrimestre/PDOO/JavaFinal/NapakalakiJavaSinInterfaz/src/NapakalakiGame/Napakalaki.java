/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
/**
 *
 * @author Javi
 */
public class Napakalaki {
    private static final Napakalaki instance = new Napakalaki();
    private  Monster currentMonster;
    private CardDealer dealer=CardDealer.getInstance();
    private ArrayList <Player> players;
    private Player currentPlayer;
    
    private Napakalaki() {}
    private void initPlayers(ArrayList <String> names){
        players=new ArrayList();
        for(String s: names){
            players.add(new Player(s));
        }
    }
    private Player nextPlayer(){
        Player p;
        int nextI;
        int totalP=this.players.size();
        Random r=new Random();
        if(currentPlayer==null){
            nextI=r.nextInt(totalP);
        }
        else{
            int CPI=this.players.indexOf(this.currentPlayer);
            if(CPI==totalP-1){
                nextI=0;
            }
            else{
                nextI=CPI+1;
            }
        }
        p=players.get(nextI);
        currentPlayer=p;
        return currentPlayer;
    }
    private boolean nextTurnAllowed(){
        if( currentPlayer==null){
            return true;
        }
        else{
            return currentPlayer.validState();
        }
    }
    private void setEnemies(){
        for(Player p: players){
            Random r=new Random();
            boolean otro=true;
            while(otro){
                int i=r.nextInt(players.size());
                if(p!=players.get(i)){
                    p.setEenemy(players.get(i));
                    otro=false;
                }
            }
        }
    }
    public static Napakalaki getInstance() {
        return instance;
    }
    public CombatResult developCombat(){
        CombatResult a=currentPlayer.combat(currentMonster);
        this.dealer.giveMonsterBack(this.currentMonster);
        if(a==CombatResult.LOSEANDCONVERT){
            Cultist c=dealer.nextCultist();
            CultistPlayer cp=new CultistPlayer(currentPlayer, c);
            players.set(players.indexOf(currentPlayer), cp);
            for(Player p: players){
                if(p.getEnemy()==currentPlayer){
                    p.setEenemy(cp);
                }
            }
            currentPlayer=cp;
        }
        return a;
    }
    public void discardVisibleTreasures(ArrayList <Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.discardVisibleTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    public void discardHiddenTreasures(ArrayList <Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.discardHiddenTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    public void makeTreasuresVisible(ArrayList <Treasure> treasures){
        for(Treasure t: treasures){
            currentPlayer.makeTreasureVisible(t);
        }
    }
    public void initGame(ArrayList <String> players){
        this.initPlayers(players);
        this.setEnemies();
        dealer.initCards();
        this.nextTurn();
    }
    public  Player getCurrentPlayer(){
        return currentPlayer;
    }
    public Monster getCurrentMonster(){
        return currentMonster;
    }
    public boolean nextTurn(){
        boolean stateOK=this.nextTurnAllowed();
        if(stateOK){
            currentPlayer=nextPlayer();
            currentMonster=dealer.nextMonster();
            boolean dead=currentPlayer.isDead();
            if(dead){
                currentPlayer.initTreasures();
            }
        }
        return stateOK;
    }
    public boolean endOfGame(CombatResult result){
        if(result==CombatResult.WINGAME){
            return true;
        }
        else {
            return false;
        }
    }
}
