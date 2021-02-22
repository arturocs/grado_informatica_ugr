# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class BadConsequence
  attr_accessor :text 
  attr_accessor :levels
  attr_accessor :nVisibleTreasures
  attr_accessor :nHiddenTreasures
  attr_accessor :death
  attr_accessor :specificHiddenTreasures
  attr_accessor :specificVisibleTreasures
  @@MAXTREASURES=10
  def initialize(aText, someLevels, someVisibleTreasures, someHiddenTreasures, someSpecificVisibleTreasures, someSpecificHiddenTreasures, death)
    @text = aText
    @levels = someLevels
    @nVisibleTreasures = someVisibleTreasures
    @nHiddenTreasures = someHiddenTreasures
    @death = death
    @specificHiddenTreasures = someSpecificHiddenTreasures
    @specificVisibleTreasures = someSpecificVisibleTreasures
    
  end
  
  def to_s
    "text: #{@text} levels: #{@levels} nVisibleTreasures: #{@nVisibleTreasures} nHiddenTreasures: #{@nHiddenTreasures} death: #{@death} specificHiddenTreasures: #{@specificHiddenTreasures} specificVisibleTreasures: #{@specificVisibleTreasures}"
  end 
  
  private_class_method :new
  
  def BadConsequence.newLevelNumberOfTreasures (aText, someLevels, someVisibleTreasures, someHiddenTreasures)
    new(aText, someLevels, someVisibleTreasures, someHiddenTreasures, Array.new, Array.new, false)
  end
  
  def BadConsequence.newLevelSpecificTreasures (aText, someLevels, someSpecificVisibleTreasures, someSpecificHiddenTreasures)
    new(aText, someLevels, 0, 0, someSpecificVisibleTreasures, someSpecificHiddenTreasures, false)
  end
  
  def BadConsequence.newDeath (aText)
    new(aText, 0, 0, 0, Array.new, Array.new, true)
  end 
  
  def substractVisibleTreasure(t)
    @specificVisibleTreasures.delete(t)
    unless (@nVisibleTreasures.empty?)
      @nVisibleTreasures = @nVisibleTreasures - 1             
    end
  end
  
  def substractHiddenTreasure(t)
    @specificHiddenTreasures.delete(t)
    unless (@nHiddenTreasures.empty?)
      @nHiddenTreasures = @nHiddenTreasures - 1             
    end
  end
 
  def isEmpty
    return (@nVisibleTreasures == 0 && @nHiddenTreasures == 0) || (@specificVisibleTreasures.empty? && @specificHiddenTreasures.empty?)
  end
  
  def adjustToFitTreasureList(v,h)
      
    bc=BadConsequence.new
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
    vi=Array.new
    hi=Array.new
    bc.specificVisibleTreasures.each do |x|
        if(v.index(x) != nil)
          vi << x.type
          bc.specificVisibleTreasures.delete(x)
        end
      end if (!v.empty?)

    bc.specificHiddenTreasures.each do |y|
      if(h.index(y) !=nil )
        hi << y.type
        bc.specificHiddenTreasures.delete(y)
      end
    end if(!h.empty?)
    bc=BadConsequence.new(bc.text,bc.levels,nv,nh,bc.death,vi,hi)
    return bc
  end
  
end
