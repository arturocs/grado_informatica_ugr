# encoding: utf-8

class BadConsequence
  @@MAXTREASURES=10
  def initialize(txt,lvl,nvisibtreas,nhiddentreas,dth,spechidtrea,specvisbtrea)
    @text=txt
    @levels=lvl
    @nVisibleTreasures=nvisibtreas
    @nHiddenTreasures=nhiddentreas
    @death=dth
    @specificHiddenTreasures=Array.new(spechidtrea)
    @specificVisibleTreasures=Array.new(specvisbtrea)
  end

  attr_reader :levels
  attr_reader :death
  attr_reader :nVisibleTreasures
  attr_reader :nHiddenTreasures
  attr_reader :text
  attr_reader :specificHiddenTreasures
  attr_reader :specificVisibleTreasures
  
  def self.newLevelNumberOfTreasures(aText, someLevels, someVisibleTreasures, someHiddenTreasures)
    new(aText,someLevels,someVisibleTreasures,someHiddenTreasures,false,[],[])
  end

  def self.newLevelSpecificTreasures(aText, someLevels, someSpecificVisibleTreasures, someSpecificHiddenTreasures)
    new(aText,someLevels,0,0,false,someSpecificHiddenTreasures,someSpecificVisibleTreasures)
  end

  def self.newDeath(aText)
    new(aText,0,0,0,true,[],[])
  end
  
  def self.MAXTREASURES
    @@MAXTREASURES
  end
  
  def isEmpty
    return @nVisibleTreasures==0 && @nHiddenTreasures==0 && @specificVisibleTreasures.empty? && @specificHiddenTreasures.empty?
  end

  def substractVisibleTreasure(t)
    @specificVisibleTreasures.delete(t) #preguntar este y el otro
    @nVisibleTreasures-=1 if(@nVisibleTreasures>0)
  end

  def substractHiddenTreasure(t)
    @specificHiddenTreasures.delete(t)
    @nHiddenTreasures-=1 if(@nHiddenTreasures>0)
  end

  def adjustToFitTreasureList(v,h)
    
    bc=BadConsequence.new(@text,@levels,@nVisibleTreasures,@nHiddenTreasures,@death,@specificVisibleTreasures,@specificHiddenTreasures)
    
    if(bc.nVisibleTreasures > v.length)
      nv=v.length
    else
      nv=bc.nVisibleTreasures
    end
    
    if(bc.nHiddenTreasures > h.length)
      nh=h.length
    else
      nh=bc.nHiddenTreasures
    end
      
    visible=Array.new
    hidden=Array.new

    bc.specificVisibleTreasures.each do |x|
        if(v.index(x) != nil)
          visible << x.type
          bc.specificVisibleTreasures.delete(x)
        end
      end if (!v.empty?)

    bc.specificHiddenTreasures.each do |y|
      if(h.index(y) !=nil )
        hidden << y.type
        bc.specificHiddenTreasures.delete(y)
      end
    end if(!h.empty?)
    
    

    bc=BadConsequence.new(bc.text,bc.levels,nv,nh,bc.death,visible,hidden)
    

    return bc
  end

    def to_s
    "text: #{@text} levels: #{@levels} nVisibleTreasures: #{@nVisibleTreasures} nHiddenTreasures: #{@nHiddenTreasures} death: #{@death} specificHiddenTreasures: #{@specificHiddenTreasures} specificVisibleTreasures: #{@specificVisibleTreasures}"
  end 
  
end
  
