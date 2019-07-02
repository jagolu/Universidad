/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package NapakalakiGame;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
/**
 *
 * @author Javi
 */
public class CardDealer {
    private static final CardDealer instance = new CardDealer();
    private ArrayList <Treasure> unusedTreasures=new ArrayList<Treasure>();
    private ArrayList <Treasure> usedTreasures=new ArrayList<Treasure>();
    private ArrayList <Monster> unusedMonsters=new ArrayList<Monster>();
    private ArrayList <Monster> usedMonsters=new ArrayList<Monster>();
    private ArrayList <Cultist> unusedCultist=new ArrayList<Cultist>();
    
    private CardDealer() {}
    
    private void initTreasureCardDeck(){
        Treasure t=new Treasure("!Si mi amo!", 4, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("Botas de investigacion", 3, TreasureKind.SHOES);
        unusedTreasures.add(t);
        t=new Treasure("Capucha de Cthulhu", 3, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("A prueba de babas", 2, TreasureKind.ARMOR);
        unusedTreasures.add(t);
        t=new Treasure("Botas de lluvia acida", 1, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Casco minero", 2, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("Ametralladora Thompson", 4, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Camiseta de la UGR", 1, TreasureKind.ARMOR);
        unusedTreasures.add(t);
        t=new Treasure("Clavo de rail ferroviario", 3, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Cuchillo de sushi arcano", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Fez alopodo", 3, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("Hacha prehistorica", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("El aparato del Pr. Tesla", 4, TreasureKind.ARMOR);
        unusedTreasures.add(t);
        t=new Treasure("Gaita", 4, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Insecticida", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Escopeta de 3 cañones", 4, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Garabato mistico", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("La rebeca metalica", 2, TreasureKind.ARMOR);
        unusedTreasures.add(t);
        t=new Treasure("Lanzallamas", 4, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Necro-comicon", 1, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Necronomicon", 5, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Linterna a 2 manos", 3, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Necro-gnomicon", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Necrotelecom", 2, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("Mazo de los antiguos", 3, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Necro-playboycon", 3, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Porra preternatural", 2, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Shogulador", 1, TreasureKind.BOTHHANDS);
        unusedTreasures.add(t);
        t=new Treasure("Varita de atizamiento", 3, TreasureKind.ONEHAND);
        unusedTreasures.add(t);
        t=new Treasure("Tentaculo de pega", 2, TreasureKind.HELMET);
        unusedTreasures.add(t);
        t=new Treasure("Zapato deja-amigos", 1, TreasureKind.SHOES);
        unusedTreasures.add(t);
        this.shuffleTreasures();
    }
    private void initMonsterCardDeck(){
        BadConsequence badConsequence=new SpecificBadConsequence("Pierdes tu armadura visible y otra oculta",0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList(Arrays.asList(TreasureKind.ARMOR)));
        Prize prize=new Prize(2,1);
        unusedMonsters.add(new Monster("3 Byakhees de bonanza",8,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Embobados con el lindo primigenio te descartas de tu casco visible",0,new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("Chibithulhu",2,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("El primordial bostezo contagioso. \nPierdes el calzado visible",0,new ArrayList(Arrays.asList(TreasureKind.SHOES)),new ArrayList());
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("El sopor de Dunwich",2,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta",0,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
        prize=new Prize(4,1);
        unusedMonsters.add(new Monster("Angeles de la noche ibicenca",14,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Pierdes todos tus tesoros visibles",0,BadConsequence.MAXTREASURES,0);
        prize=new Prize(3,1);
        unusedMonsters.add(new Monster("El gorron en el umbral",10,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Pierdes la armadura visible",0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("H.P. Munchcraft",6,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Sientes bichos bajo la ropa. Descarta la armadura visible",0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("Bichgooth",2,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Pierdes 5 niveles y 3 tesoros visibles",5,3,0);
        prize=new Prize(4,2);
        unusedMonsters.add(new Monster("El rey de rosa",13,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Toses los pulmones y pierdes 2 niveles.",2,0,0);
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("La que redacta en las tinieblas",2,badConsequence,prize));
        badConsequence=new DeathBadConsequence("Estos monstruos resultn bastante superficiales y te aburren mortalmente. \nEstas muerto");
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("Los hondos",8,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Pierdes 2 niveles y 2 tesoros oscuros",2,0,2);
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("Semillas Cthulhu",4,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Te intentas escaquear. Pierdes una mano visible.",0,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList());
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("Dameargo",1,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Da mucho asquito. Pierdes 3 niveles",3,0,0);
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("Pollipolipo volante",3,badConsequence,prize));
        badConsequence=new DeathBadConsequence("No le hace gracia que pronuncien mal su nombre. Estas muerto");
        prize=new Prize(3,1);
        unusedMonsters.add(new Monster("Yskhtihyssg-Goth",12,badConsequence,prize));
        badConsequence=new DeathBadConsequence("La familia te atrapa. Estas muerto");
        prize=new Prize(4,1);
        unusedMonsters.add(new Monster("Familia feliz",1,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("La quinta directiva primaria te obliga a \nperder 2 niveles y un tesoro 2 manos visible",2,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)),new ArrayList());
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("Roboggoth",8,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Te asusta en la noche. Pierdes un casco visible.",0,new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("El espia",5,badConsequence,prize));
        badConsequence=new NumericBadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles.",2,5,0);
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("El lenguas",20,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Te faltan manos para tanta cabeza. \nPierdes 3 niveles y tus tesoros visibles de las manos.",3,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS, TreasureKind.ONEHAND, TreasureKind.ONEHAND)),new ArrayList());
        prize=new Prize(1,1);
        unusedMonsters.add(new Monster("Bicefalo",20,badConsequence,prize));
        badConsequence=new SpecificBadConsequence("Pierdes 1 mano visible", 0, new ArrayList(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList());
        prize=new Prize(3,1);
        unusedMonsters.add(new Monster("El mal indecible impronunciable", 10, badConsequence, prize, -2));
        badConsequence=new NumericBadConsequence("Pierdes tus tesoros visibles. Jajaja", 0, BadConsequence.MAXTREASURES, 0);
        prize=new Prize(2,1);
        unusedMonsters.add(new Monster("Testigos oculares", 6, badConsequence, prize, 2));
        badConsequence=new DeathBadConsequence("Hoy no es tu dia de suerte. Mueres");
        prize=new Prize(2,5);
        unusedMonsters.add(new Monster("El gran cthulhu", 20, badConsequence, prize, 4));
        badConsequence=new NumericBadConsequence("Tu gobierno te recorta 2 niveles", 2, 0, 0);
        prize=new Prize(2, 1);
        unusedMonsters.add(new Monster("Serpiente politico", 8, badConsequence, prize, -2));
        badConsequence=new SpecificBadConsequence("Pierdes tu casco y tu armadur visible. \nPierdes tus manos ocultas", 0, new ArrayList(Arrays.asList(TreasureKind.ARMOR, TreasureKind.HELMET)),  new ArrayList(Arrays.asList(TreasureKind.ONEHAND, TreasureKind.ONEHAND, TreasureKind.BOTHHANDS))  );
        prize=new Prize(1, 1);
        unusedMonsters.add(new Monster("Felpuggoth", 2, badConsequence, prize, 5));
        badConsequence=new NumericBadConsequence("Shoggoth", 2, 0, 0);
        prize=new Prize(4, 2);
        unusedMonsters.add(new Monster("Shoggoth", 16, badConsequence, prize, -4));
        badConsequence=new NumericBadConsequence("Pintalabios negro. \nPierdes 2 niveles", 2, 0, 0);
        prize=new Prize(1, 1);
        unusedMonsters.add(new Monster("Lolitagooth", 2, badConsequence, prize, 3));
        this.shuffleMonsters();
    }
    private void initCultistCardDeck(){
        unusedCultist.add(new Cultist("Sectario 1", 1));
        unusedCultist.add(new Cultist("Sectario 2", 2));
        unusedCultist.add(new Cultist("Sectario 3", 1));
        unusedCultist.add(new Cultist("Sectario 4", 2));
        unusedCultist.add(new Cultist("Sectario 5", 1));
        unusedCultist.add(new Cultist("Sectario 6", 1));
        this.shuffleCultists();
    }
    private void shuffleTreasures(){
        Collections.shuffle(unusedTreasures);
    }
    private void shuffleMonsters(){
        Collections.shuffle(unusedMonsters);
    }
    private void shuffleCultists(){
        Collections.shuffle(unusedCultist);
    }
    
    public static CardDealer getInstance() {
        return instance;
    }
    
    public Treasure nextTreasure(){
        if(unusedTreasures.isEmpty()){
            unusedTreasures.addAll(usedTreasures);
            usedTreasures.clear();
        }
        Treasure t;
        t=unusedTreasures.get(unusedTreasures.size()-1);
        unusedTreasures.remove(unusedTreasures.size()-1);
        return t;
        
    }
    public Monster nextMonster(){
        if(unusedMonsters.isEmpty()){
            unusedMonsters.addAll(usedMonsters);
            usedMonsters.clear();
            this.shuffleMonsters();
        }
        Monster m;
        m=unusedMonsters.get(unusedMonsters.size()-1);
        usedMonsters.add(m);
        unusedMonsters.remove(unusedMonsters.size()-1);
        return m;
        
    }
    public Cultist nextCultist(){
        if(unusedCultist.isEmpty()){
            this.initCultistCardDeck();
        }
        Cultist c= unusedCultist.get(unusedCultist.size()-1);
        unusedCultist.remove(c);
        return c;
    }
    public void giveTreasureBack(Treasure t){
        usedTreasures.add(t);
    }
    public void giveMonsterBack(Monster m){
        usedMonsters.add(m);
    }
    public void initCards(){
        this.initTreasureCardDeck();
        this.initMonsterCardDeck();
        this.initCultistCardDeck();
    }
}
