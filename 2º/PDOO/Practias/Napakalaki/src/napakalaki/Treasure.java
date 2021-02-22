/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

/**
 *
 * @author arturo
 */
public class Treasure {
    private String name;
    private int bonus;
    private TreasureKind type;

    public TreasureKind getType() {
        return type;
    }
            
    public Treasure(String n,int bonus,TreasureKind t){}        

    public String getName() {
        return name;
    }

    public int getBonus() {
        return bonus;
    }
    
}
