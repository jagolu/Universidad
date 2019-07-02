/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import GUI.Dice;
//import GUI.Dice;
/**
 *
 * @author Javi
 */
public class Player {
    static int MAXLEVEL=10;
    private String name;
    private int level;
    private boolean dead=true;
    private boolean canISteal=true;
    protected Player enemy;
    private BadConsequence pendingBadConsequence;
    private ArrayList <Treasure> hiddenTreasures=new ArrayList();
    private ArrayList <Treasure> visibleTreasures=new ArrayList();
    
    public Player(String name){
        this.name=name;
        this.level=1;
    }
    public Player(Player p){
        this.name=p.name;
        this.level=p.level;
        this.dead=p.dead;
        this.canISteal=p.canISteal;
        this.enemy=p.enemy;
        this.pendingBadConsequence=p.pendingBadConsequence;
        this.hiddenTreasures=p.hiddenTreasures;
        this.visibleTreasures=p.visibleTreasures;
    }
    
    public String getName(){
        return name;
    }
    public Player getEnemy(){
        return enemy;
    }
    private void bringToLife(){
        dead=false;
    }
    public int getCombatLevel(){
        int nivel_combate=this.level;
        for(Treasure t : visibleTreasures){
            nivel_combate=nivel_combate+t.getBonus();
        }
        return nivel_combate;
    }
    private void incrementLevels(int l){
        level=level+l;
    }
    private void decrementLevels(int l){
        level=level-l;
        if(level<1){
            level=1;
        }
    }
    private void setPendingBadConsequence(BadConsequence b){
        pendingBadConsequence=b;
    }
    private void applyPrize(Monster m){
        int nLevels=m.getLevelsGained();
        this.incrementLevels(nLevels);
        int nTreasures=m.getTreasuresGained();
        if(nTreasures>0){
            CardDealer dealer=CardDealer.getInstance();
            for(int i=0; i<nTreasures;i++){
                hiddenTreasures.add(dealer.nextTreasure());
            }
        }
    }
    private void applyBadConsequence(Monster m){
        int nLevels=m.getBadConsequence().getLevels();
        this.decrementLevels(nLevels);
        this.pendingBadConsequence=m.getBadConsequence().adjustToFitTreasureLists(visibleTreasures, hiddenTreasures);
        this.setPendingBadConsequence(this.pendingBadConsequence);
    }
    private boolean canMakeTreasureVisible(Treasure t){
        boolean podemos=true;
        int NumeroOneHand=0;
        boolean BothHandEquipada=false;
        for(Treasure t2: visibleTreasures){
            if(t2.getType()==TreasureKind.ONEHAND){
                NumeroOneHand++;
            }
            if(t2.getType()==TreasureKind.BOTHHANDS){
                BothHandEquipada=true;
            }
            if(t2.getType()==t.getType() && t2.getType()!=TreasureKind.ONEHAND && t2.getType()!=TreasureKind.BOTHHANDS){
                podemos=false;
            }
        }
        if( (t.getType()==TreasureKind.ONEHAND && NumeroOneHand>=2) || (t.getType()==TreasureKind.BOTHHANDS && BothHandEquipada) || (t.getType()==TreasureKind.ONEHAND && BothHandEquipada) || (t.getType()==TreasureKind.BOTHHANDS && NumeroOneHand!=0) ){
            podemos=false;
        }
        return podemos;
    }
    private int howManyVisibleTreasures(TreasureKind tKind){
        int cont=0;
        for(Treasure t : visibleTreasures){
            if(t.getType()==tKind){
                cont++;
            }
        }
        return cont;
    }
    private void diefNoTreasures(){
        if(hiddenTreasures.isEmpty() && visibleTreasures.isEmpty()){
            dead=true;
        }
    }
    public boolean isDead(){
        return dead;
    }
    public ArrayList<Treasure> getHiddenTreasures(){
        return hiddenTreasures;
    }
    public ArrayList <Treasure> getVisibleTreasures(){
        return visibleTreasures;
    }
    public CombatResult combat(Monster m){
        int myLevel= this.getCombatLevel();
        int monsterLevel=this.getOponentLevel(m);
        if(myLevel>monsterLevel){
            this.applyPrize(m);
            if(level>=MAXLEVEL){
                return CombatResult.WINGAME;
            }
            else{
                return CombatResult.WIN;
            }
        }
        else{
            this.applyBadConsequence(m);
            if(this.shouldConvert()){
                return CombatResult.LOSEANDCONVERT;
            }
            else{
                return CombatResult.LOSE;
            }
        }
        
    }
    public void makeTreasureVisible(Treasure t){
        boolean canI= this.canMakeTreasureVisible(t);
        if(canI){
            visibleTreasures.add(t);
            hiddenTreasures.remove(t);
        }
    }
    public void discardVisibleTreasure(Treasure t){
        visibleTreasures.remove(t);
        if( (pendingBadConsequence!=null) && (!pendingBadConsequence.isEmpty())){
            pendingBadConsequence.substractVisibleTreasure(t);
        }
        this.diefNoTreasures();
    }
    public void discardHiddenTreasure(Treasure t){
        hiddenTreasures.remove(t);
        if( (pendingBadConsequence!=null) && (!pendingBadConsequence.isEmpty()) ){
            pendingBadConsequence.substratHiddenTreasure(t);
        }
        this.diefNoTreasures();
    }
    public boolean validState(){
        if(pendingBadConsequence==null){
            return true;
        }
        else if(pendingBadConsequence.isEmpty() && hiddenTreasures.size()<=4){
            return true;
        }
        else{
            return false;
        }
    }
    public void initTreasures(){
        CardDealer dealer=CardDealer.getInstance();
        Dice dice=Dice.getInstance();
        this.bringToLife();;
        Treasure treasure=dealer.nextTreasure();
        hiddenTreasures.add(treasure);
        int number=dice.nextNumber();
        if(number>1){
            treasure=dealer.nextTreasure();
            hiddenTreasures.add(treasure);
        }
        if(number==6){
            treasure=dealer.nextTreasure();
            hiddenTreasures.add(treasure);
        }
    }
    public int getLevels(){
        return level;
    }
    public Treasure stealTreasure(){
        Treasure t=null;
        if(this.canISteal && enemy.canYouGiveMeATreasure()){
            t=enemy.giveMeATreasure();
            hiddenTreasures.add(t);
            this.haveStolen();
        }
        return t;
    }
    public void setEenemy(Player enemy){
        this.enemy=enemy;
    }
    private Treasure giveMeATreasure(){
        if(canYouGiveMeATreasure()){
            Random r=new Random();
            int i=r.nextInt(hiddenTreasures.size());
            Treasure t;
            t=hiddenTreasures.get(i);
            hiddenTreasures.remove(i);
            return t;
        }
        else return null;
    }
    public boolean canISteal(){
        return canISteal;
    }
    private boolean canYouGiveMeATreasure(){
        if(hiddenTreasures.isEmpty()){
            return false;
        }
        else{
            return true;
        }
    }
    private void haveStolen(){
        canISteal=false;
    }
    public void discardAllTreasures(){
        ArrayList<Treasure>vt=new ArrayList(visibleTreasures);
        ArrayList<Treasure>hd=new ArrayList(hiddenTreasures);
        for(Treasure t: vt){
            this.discardVisibleTreasure(t);
            pendingBadConsequence.substractVisibleTreasure(t);
        }
        for(Treasure t: hd){
            this.discardHiddenTreasure(t);
            pendingBadConsequence.substratHiddenTreasure(t);
        }
    }
    public String toString(){
        System.out.println( name+"  level->"+level+" levelCombat-->"+this.getCombatLevel()+"  dead->"+dead+" enemigo-->"+enemy.getName());
        if(this.pendingBadConsequence!=null){
            return "PendingBad----->" +this.pendingBadConsequence.toString();
        }
        else return " vacio";
    }
    
    protected int getOponentLevel(Monster m){
        return m.getCombatLevel();
    }
    protected boolean shouldConvert(){
       Dice dice=Dice.getInstance();
       if(dice.nextNumber()==1){
           return true;
       }
       else{
           return false;
       }
    }
    public BadConsequence getPendingBadConsequence(){
        if(pendingBadConsequence!=null){
        return pendingBadConsequence;}
        else return null;
    }
}
