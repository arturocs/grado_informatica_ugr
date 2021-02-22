/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import static napakalaki.PruebaNapakalaki.monstruos;

/**
 *
 * @author arturo
 */
public class CardDealer {
    private static final CardDealer instance = new CardDealer();
    
    private ArrayList<Monster> unusedMonsters=new ArrayList<Monster>();
    private ArrayList<Monster> usedMonsters=new ArrayList<Monster>();
    private ArrayList<Treasure> unusedTreasures=new ArrayList<Treasure>();
    private ArrayList<Treasure> usedTreasures=new ArrayList<Treasure>();
    
    
    private CardDealer(){}
    
    public static CardDealer getInstance (){
        return instance;
    }
    private void initTreasureCardDeck() {
    
        unusedTreasures.add(new Treasure("¡Si mi amo!",4,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("Botas de investigacion",3,TreasureKind.SHOES));
        unusedTreasures.add(new Treasure("Capucha de Cthulhu",3,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("A prueba de babas",2,TreasureKind.ARMOR));
        unusedTreasures.add(new Treasure("Botas de lluvia acida",1,TreasureKind.SHOES));
        unusedTreasures.add(new Treasure("Casco minero",2,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("Ametralladora ACME",4,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Camiseta de la ETSIIT",1,TreasureKind.ARMOR));
        unusedTreasures.add(new Treasure("Clavo de rail ferroviario",3,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Cuchillo de sushi arcano",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Fez alopodo",3,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("Hacha prehistorico",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("El aparato de Pr. Tesla",4,TreasureKind.ARMOR));
        unusedTreasures.add(new Treasure("Gaita",4,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Insecticida",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Escopeta de 3 cañones",4,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Garabato mistico",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("La rebeca metalica",2,TreasureKind.ARMOR));
        unusedTreasures.add(new Treasure("Lanzallamas",4,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Necrocomicon",1,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Necronomicon",5,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Linterna a 2 manos",3,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Necrognomicon",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Necrotelecom",2,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("Mazo de los antiguos",3,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Necroplayboycon",3,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Porra preternatural",2,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Shogulador",1,TreasureKind.BOTHHANDS));
        unusedTreasures.add(new Treasure("Varita de atizamiento",3,TreasureKind.ONEHAND));
        unusedTreasures.add(new Treasure("Tentaculo de pega",2,TreasureKind.HELMET));
        unusedTreasures.add(new Treasure("Zapato deja-amigos",1,TreasureKind.SHOES));
        
    }
    
    private void initMonsterCardDeck() {
    
     //3 Byakhees de balanza
    BadConsequence badConsequence = new BadConsequence("Pierdes tu armadura visible y otra oculta", 0,
    new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
    Prize prize = new Prize(2,1);
    monstruos.add(new Monster("3 Byakhees de balanza", 8, badConsequence, prize));

    //Tecnochtitlan
    badConsequence = new BadConsequence("Embobados con el lindo primigenio te descartas de tu casco visible",0,
    new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Tecnochtitlan", 2, badConsequence, prize));

    //El sopor de Dunwich
    badConsequence = new BadConsequence ("El primordial bostezo contagioso. Pierdes el calzado visible",
    0,new ArrayList(Arrays.asList(TreasureKind.SHOES)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("El sopor de Dunwich",2,badConsequence,prize));

    //Demonios de Magaluf
    badConsequence = new BadConsequence ("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo."
        + "Descarta 1 mano visible y 1 mano oculta",0,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
    prize = new Prize(4,1);
    monstruos.add(new Monster("Demonios de Magaluf",2,badConsequence,prize));

    //El gorron en el umbral
    badConsequence = new BadConsequence ("Pierdes todos tus tesoros visibles",0,Integer.MAX_VALUE,0);
    prize = new Prize(3,1);
    monstruos.add(new Monster("El gorron en el umbral",13,badConsequence,prize));

    //H.P Munchcraft
    badConsequence = new BadConsequence ("Pierdes la armadura visible",0,
    new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("H.P Munchcraft",6,badConsequence,prize));

    //Necrofalo
    badConsequence = new BadConsequence ("Sientes bichos bajo la ropa. Descarga la armadura visible",0,
    new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Necrofalo",13,badConsequence,prize));

    //El rey de rosado
    badConsequence = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles",5,3,0);
    prize = new Prize(3,2);
    monstruos.add(new Monster("El rey de rosado",11,badConsequence,prize));

    //Flecher
    badConsequence = new BadConsequence("Toses los pulmones y pierdes 2 niveles",2,0,0);
    prize = new Prize(1,1);
    monstruos.add(new Monster("Flecher",2,badConsequence,prize));

    //Los hondos
    badConsequence = new BadConsequence("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto", true);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Los hondos", 8, badConsequence, prize));
    
    //Semillas Cthulhu
    badConsequence = new BadConsequence("Pierdes 2 niveles y 2 tesoros ocultos", 2, 0, 2);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Semillas Cthulhu",4 , badConsequence, prize));
    
    //Dameargo
    badConsequence = new BadConsequence("Te intentas escaquear. Pierdes una mano visible.", 0, new ArrayList(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("Dameargo",1 , badConsequence, prize));
    
    //Pollipólipo volante
    badConsequence = new BadConsequence("Da mucho asquito. Pierdes 3 niveles.", 3, 0, 0);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Pollipólipo volante",3 , badConsequence, prize));
    
    //Yskhtihyssg-Goth
    badConsequence = new BadConsequence("No le hace gracia que pronuncien mal su nombre. Estas muerto", true);
    prize = new Prize(3,1);
    monstruos.add(new Monster("Yskhtihyssg-Goth", 14, badConsequence, prize));
    
    //Familia feliz
    badConsequence = new BadConsequence("La familia te atrapa. Estás muerto.", true);
    prize = new Prize(3,1);
    monstruos.add(new Monster("Familia feliz", 1, badConsequence, prize));
    
    //Roboggoth
    badConsequence = new BadConsequence("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2, new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)),new ArrayList() );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Roboggoth", 8, badConsequence, prize));
    
    //El espia sordo
    badConsequence = new BadConsequence("Te asusta en la noche. Pierdes un casco visible", 0, new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList() );
    prize = new Prize(1,1);
    monstruos.add(new Monster("El espia sordo", 5, badConsequence, prize));
    
    //Tongue
    badConsequence = new BadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2,5,0 );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Tongue", 19, badConsequence, prize));
    
    //Bicéfalo
    badConsequence = new BadConsequence("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS,TreasureKind.ONEHAND,TreasureKind.ONEHAND)),new ArrayList() );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Bicéfalo", 21, badConsequence, prize));
    
    }
    
    private void shuffleTreasures(){
        Collections.shuffle(unusedTreasures);
    }
    
    private void shuffleMonsters(){
        Collections.shuffle(unusedMonsters);
    }
    
    public Treasure nextTreasure(){
        if(unusedTreasures.isEmpty()){
            unusedTreasures.addAll(usedTreasures);
            usedTreasures.clear();
            shuffleTreasures();
        }
        
        Treasure aux = unusedTreasures.get(0);
        unusedTreasures.remove(0);
        return aux;
    }    
    public Monster nextMonster(){
        if(unusedMonsters.isEmpty()){
            unusedMonsters.addAll(monstruos);
            usedMonsters.clear();
            shuffleMonsters();
            shuffleTreasures();
        }
        Monster aux = unusedMonsters.get(0);
        unusedMonsters.remove(0);
        return aux;
        }

    
    public void giveTreasureBack(Treasure t){
        usedTreasures.add(t);
    }
    
    public void giveMonsterBack(Monster m){
        usedMonsters.add(m);
    }
    
    public void initCards() {
            this.initMonsterCardDeck();
            this.initTreasureCardDeck(); 
    
    }
    
    
}
