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
public class Napakalaki {
    private static final Napakalaki instance = new Napakalaki();
    
    private Napakalaki(){}
    private Player currentPlayer;
    private ArrayList <Player> players= new ArrayList();
    private CardDealer dealer;
    private Monster currentMonster;
    
    private void  initPlayers( ArrayList<String> name  ){
        for (String n : name){
            Player p = new Player (n);
            players.add(p);
        }
    }
   
    private Player nextPlayer(){
        Random ran=new Random();
        if(currentPlayer == null){
            return players.get(ran.nextInt(players.size()));
        }
        else{
            return currentPlayer = players.get((players.indexOf(currentPlayer)+1)%players.size());
        } 
    }
    private boolean nextTurnAllowed(){
        if (currentPlayer == null) {
            return true;
	} else {
            return currentPlayer.validState();
        }
    }
    private void setEnemies(){
        Random r=new Random();
        Player aux;
        int i = 0;
        while(i < players.size()){
            aux=players.get(r.nextInt(players.size()));
            if(aux != players.get(i)){
                players.get(i).setEnemy(aux);
                i++;
            }            
}
    }
    public CombatResult developCombat(){
        CombatResult combatResult = currentPlayer.combat(currentMonster);
        dealer.giveMonsterBack(currentMonster);
        return combatResult;       
    }
   public void discardVisibleTreasures(ArrayList<Treasure> tr){
        for(Treasure t :tr){
            currentPlayer.discardVisibleTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    public void discardHiddenTreasures(ArrayList<Treasure> tr){
        for(Treasure t :tr){
            currentPlayer.discardHiddenTreasure(t);
            dealer.giveTreasureBack(t);
        }
    }
    public void makeTreasuresVisible(ArrayList<Treasure> tr){
        for(Treasure t :tr){
            currentPlayer.makeTreasureVisible(t);
        }    
    }
    public void initGame(ArrayList<String> players){
        initPlayers(players);
        setEnemies();
        dealer = CardDealer.getInstance();
        dealer.initCards();      
        nextTurn();
    }
    public Player getCurrentPlayer(){
        return currentPlayer;
    }
    public Monster getCurrentMonster(){
        return currentMonster;
    }
    public boolean nextTurn(){
        Boolean stateOK= nextTurnAllowed();
        if(stateOK){
            currentMonster= dealer.nextMonster();
            currentPlayer= nextPlayer();
            Boolean dead= currentPlayer.isDead();
            if(dead){
                currentPlayer.initTreasures();
            }
        }
        return stateOK;
    }
    public boolean endOfGame(CombatResult result){
        if(result==CombatResult.WINGAME)
            return true;
        else
            return false;
    }
           
    
    
    public static Napakalaki getInstance (){
        return instance;
    }

    
}
