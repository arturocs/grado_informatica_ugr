/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author arturo
 */
public class Player {
    static final int MAXLEVEL=10;
    
    private String name;
    private int level;
    private boolean dead = true;
    private boolean canISteal =true;
    private Player enemy;
    private ArrayList<Treasure> hiddenTreasures= new ArrayList<Treasure>();;
    private ArrayList<Treasure> visibleTreasures= new ArrayList<Treasure>();;
    private BadConsequence pendingBadConsequence;

    public Player(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
    
    private void bringTolife(){
        dead = false;
    }
    
    private int getCombatLevel(){
    
        int combat_level;
        combat_level=level;
        for(Treasure t:visibleTreasures){
            combat_level=combat_level+t.getBonus();
        }
        return combat_level;
        
    }
    
    private void incrementLevels(int l ){
        if( l > 0 ){
            level += l;
        }
    }
    
    private void decrementLevels(int l){
        if( l > 0 ){
            level -= l;
        }
        
    }
    
    private void setPendingBadConsequence(BadConsequence b){
        pendingBadConsequence = b;
        
    }
    
    private void applyPrize(Monster m){
        int nLevels = m.getLevelsGained();
        int nTreasures = m.getTreasuresGained();
        incrementLevels(level);
        
        if(nTreasures > 0){
            CardDealer dealer = CardDealer.getInstance();
            Treasure treasure;
            for(int i = 0; i < nTreasures; i++){
                treasure = dealer.nextTreasure();
                hiddenTreasures.add(treasure);
            }
        }
    }
    
    private void applyBadConsequence(Monster m){
        BadConsequence badConsequence = m.getBc();
        int nLevels = badConsequence.getLevels();
        decrementLevels(nLevels);
        BadConsequence pendingBad = badConsequence.adjustToFitTreasureLists(visibleTreasures, hiddenTreasures);
        setPendingBadConsequence(pendingBad);
    }
    
    private boolean canMakeTreasureVisible(Treasure T){          
        boolean ret = true;
        TreasureKind type = T.getType();
        
        if (type == TreasureKind.ONEHAND){
            if ((howManyVisibleTreasures(TreasureKind.BOTHHANDS) > 0) || (howManyVisibleTreasures(TreasureKind.ONEHAND) > 1))
                ret = false;
        }        
        else if (type == TreasureKind.BOTHHANDS){
            if ((howManyVisibleTreasures(TreasureKind.BOTHHANDS) > 0) || (howManyVisibleTreasures(TreasureKind.ONEHAND) > 0))
                ret = false;
        }
        else{
            if (howManyVisibleTreasures(type) > 0)
                ret = false;
        }
        return ret;
    }
    
    private int howManyVisibleTreasures(TreasureKind tKind){
        int i = 0;
        
        for (Treasure t : visibleTreasures){
            if( t.getType() == tKind )
                i++;
        }
        return i;
    }
    
    private void dieIfNoTreasures(){
        if( hiddenTreasures.isEmpty() && visibleTreasures.isEmpty() ){
            dead = true;
        }   
    }
    
    public boolean isDead(){
        return dead;
    }
    
    public ArrayList<Treasure> getHiddenTreasures(){
        return hiddenTreasures;
    }
    
    public ArrayList<Treasure> getVisibleTreasures(){
        return visibleTreasures;
    }
    public CombatResult combat(Monster m){
        int myLevel = getCombatLevel();
        int m_Level = m.getCombatLevel();
        CombatResult combatResult;
        
        if(!canISteal){
            Dice dice = Dice.getInstance();
            int n = dice.nextNumber();
            
            if(n<3){
                int e_Level = enemy.getCombatLevel();
                m_Level += e_Level;
            }
        }
        
        if(myLevel > m_Level){
            applyPrize(m);
            if(level >= MAXLEVEL)
                combatResult = CombatResult.WINGAME;
            else
                combatResult = CombatResult.WIN;           
        }
        else{
            applyBadConsequence(m);
            combatResult = CombatResult.LOSE;
        }
        
        return combatResult;
    }
    
    public void makeTreasureVisible(Treasure t){}
            
    public void discardVisibleTreasure(Treasure t){}
            
    public void  discardHiddenTreasure( Treasure t){}
    
    public boolean validState(){
        return pendingBadConsequence.isEmpty() && ( hiddenTreasures.size() <= 4 );
    }
            
    public void initTreasures(){
        CardDealer dealer = CardDealer.getInstance();
        Dice dice = Dice.getInstance();
        
        bringTolife();
        Treasure treasure = dealer.nextTreasure();
        hiddenTreasures.add(treasure);
        int number = dice.nextNumber();
        
        if(number > 1 && number < 6){
            treasure = dealer.nextTreasure();
            hiddenTreasures.add(treasure);           
        }
        if(number == 6){
            treasure = dealer.nextTreasure();
            hiddenTreasures.add(treasure);
        }
    
    }

    public int getLevels() {
        return level;
    }
            
    public Treasure stealTreasure(){
        Treasure t=null;
        if(canISteal()){
            if(enemy.canYouGiveMeATreasure()){
               t = enemy.giveMeATreasure();
               hiddenTreasures.add(t);
               haveStolen();
            }
        }
        return t;
    }     
    
    public void setEnemy(Player enemy){
        this.enemy = enemy;
    }
    
    private Treasure giveMeATreasure(){
            Random ran=new Random();
            return hiddenTreasures.get(ran.nextInt(hiddenTreasures.size()));
    }
    
    public boolean canISteal(){
        return canISteal;
    }
         
    private boolean canYouGiveMeATreasure(){
         return !hiddenTreasures.isEmpty();
    }    

    private void haveStolen(){
         canISteal = false;
    }
    
    public void discardAllTreasures(){
       Treasure treasure;
       for(int i = 0; i < visibleTreasures.size(); i++){
           treasure = visibleTreasures.get(i);
           discardVisibleTreasure(treasure);
       }
       for(int i = 0; i < hiddenTreasures.size(); i++){
           treasure = hiddenTreasures.get(i);
           discardHiddenTreasure(treasure);
        }
    
    }
}
