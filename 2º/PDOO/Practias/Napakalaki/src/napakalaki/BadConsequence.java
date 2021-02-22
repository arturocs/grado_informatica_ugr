package napakalaki;

import java.util.ArrayList;

public class BadConsequence {
    static final int MAXTREASURES=10;
    
    private String text;
    private int levels, nVisibleTreasures, nHiddenTreasures;
    private boolean death;
    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList();
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList();
   
    BadConsequence(String text, int levels, int nVisible, int nHidden){
        this.text=text;
        this.levels=levels;        
        this.nVisibleTreasures=nVisible;
        this.nHiddenTreasures=nHidden;        
    }
    
    BadConsequence(String text, boolean death){
        this.text=text;
        this.death=death;        
    }
    
    BadConsequence(String text, int levels, ArrayList<TreasureKind> tVisible, ArrayList<TreasureKind> tHidden){
        this.text=text;
        this.levels=levels; 
        this.specificHiddenTreasures=tHidden;
        this.specificVisibleTreasures=tVisible;
    }

    public String getText() {
        return text;
    }

    public int getLevels() {
        return levels;
    }

    public int getnVisibleTreasures() {
        return nVisibleTreasures;
    }

    public int getnHiddenTreasures() {
        return nHiddenTreasures;
    }

    public boolean isDeath() {
        return death;
    }

    public ArrayList<TreasureKind> getSpecificHiddenTreasures() {
        return specificHiddenTreasures;
    }

    public ArrayList<TreasureKind> getSpecificVisibleTreasures() {
        return specificVisibleTreasures;
    }
    
    public void substractVisibleTreasure(Treasure t){
        specificVisibleTreasures.remove(t.getType());        
        if(nVisibleTreasures>0)
            nVisibleTreasures--;
    }
    
    public void substractHiddenTreasure(Treasure t){
        specificHiddenTreasures.remove(t.getType());        
        if(nHiddenTreasures>0)
            nHiddenTreasures--;
    }
    
    public boolean isEmpty(){
        return (nHiddenTreasures == 0 && nVisibleTreasures == 0 ) || (specificHiddenTreasures.isEmpty() && specificVisibleTreasures.isEmpty());
        
    }    
    
    public BadConsequence adjustToFitTreasureLists(ArrayList<Treasure> v, ArrayList<Treasure> h){
        int vis=v.size(), hid= h.size();        
        BadConsequence ret=new BadConsequence(text, levels, specificVisibleTreasures, specificHiddenTreasures );        
        if(nHiddenTreasures==0 && nVisibleTreasures==0){
            
            Boolean ins=false;                
            ArrayList<TreasureKind> sv=new ArrayList(), sh=new ArrayList();               
            for(TreasureKind s_vi :specificVisibleTreasures){
                ins= false;
                for(Treasure spvp :v){
                    if(!ins)
                        if(s_vi==spvp.getType()){
                            if(!sv.contains(s_vi)){
                                sv.add(s_vi);
                                ins=true;
                            }
                        }
                }
            }
                
            for(TreasureKind s_hi :specificHiddenTreasures){
                ins= false;
                for(Treasure sphp :h){
                    if(!ins)
                        if(s_hi==sphp.getType()){
                            if(!sh.contains(s_hi)){
                                sh.add(s_hi);
                                ins= true;
                            }
                        }
                }
            }
            ret.specificVisibleTreasures= sv;
            ret.specificHiddenTreasures= sh;
        }
        else{
            if(vis<nVisibleTreasures)
                ret.nVisibleTreasures=vis;
                
            if(hid<nHiddenTreasures)
                ret.nHiddenTreasures=hid;
            }
        return ret;
    }    
    @Override
    public String toString() {
        return "BadConsequence{" + "text=" + text + ", levels=" + levels + ", nVisibleTreasures=" + nVisibleTreasures + ", nHiddenTreasures=" + nHiddenTreasures + ", death=" + death + ", specificHiddenTreasures=" + specificHiddenTreasures + ", specificVisibleTreasures=" + specificVisibleTreasures + '}';
    }

}
