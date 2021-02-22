# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'dice'
require_relative 'card_dealer'
require_relative 'combat_result'

class Player
  attr_accessor :name
  attr_accessor :level
  attr_accessor  :pendingBadConsequence
  attr_accessor :visibleTreasures
  attr_accessor :hiddenTreasures
  attr_accessor :dead
  attr_accessor :enemy
  attr_accessor :canISteal
  
   @@MAXLEVEL = 10
  def initialize(name)
    @name=name
    @level = 0
    @dead = true
    @canISteal =true
    @visibleTreasures = Array.new
    @hiddenTreasures = Array.new
    @enemy = nil
    @pendingBadConsequence = nil
  end
  
  def bringToLife
    @dead= false
  end
  def to_s
    "Name: #{@name}\tLevel: #{@level}"
  end
  def getCombatLevel
    lv=@level
    for j in @visibleTreasures
      lv+=j.bonus
    end
    return lv
  end
  
  def incrementLevels(i)
		@level=@level + i
  end
  
  def decrementLevels(i)
    if (@level > i)
      @level=@level - i
    else
      @level = 0
    end
  end
 
  def setPendingBadConsequence(b)
     @pendingBadConsequence = b
  end
 
  def applyPrize(m)
    nlevels=m.getLevelsGained
    incrementLevels(nlevels)
    ntreasures=m.getTreasuresGained

    if(ntreasures>0)
      dealer=CardDealer.instance
      ntreasures.times do
        treasure=dealer.nextTreasure
        @hiddenTreasures << treasure
      end
    end
  end
  
  def applyBadConsequence(m)
    bad_consequence=m.bc
    n_levels=bad_consequence.levels
    decrementLevels(n_levels)
    pending_bad=bad_consequence.adjustToFitTreasureList(@visibleTreasures,@hiddenTreasures) #4
    setPendingBadConsequence(pending_bad)
  end
  
  def canMakeTreasureVisible(t)
    ret = true
    type = t.type
    num_both = howManyVisibleTreasures(TreasureKind::BOTHHANDS)
    num_one = howManyVisibleTreasures(TreasureKind::ONEHAND)
    if (type == TreasureKind::ONEHAND)
        if ((num_both > 0) || (num_one > 1))
          ret = false
        end
    elsif (type == TreasureKind::BOTHHANDS)
      if ((num_both > 0) || (num_one > 0))
        ret = false
      end
    elsif (howManyVisibleTreasures(type) > 0)
      ret = false
    end
    ret
  end
  
  def howManyVisibleTreasures(tKind)
    	k = 0
		for i in 0..@visibleTreasures.size
			if (@visibleTreasures[i] == tKind)
        k = k+ 1
			end
    end
    k
  end
  
  def dieIfNoTreasures
    
    if( @hiddenTreasures.empty? && @visibleTreasures.empty? )
      @dead = true
    end
  end
  
  def isDead
     return @dead
  end
   
  def combat(m)
    mylevel=getCombatLevel 
    monsterlevel=m.combatLevel

    if(!canISteal)
      dice=Dice.instance
      number=dice.nextNumber
      
      if(number<3)
        e_level=@enemy.getCombatLevel
        monsterlevel+=e_level
      end

    end

    if(mylevel > monsterlevel)
      applyPrize(m)
      if(@level>=@@MAXLEVEL)
        combat_result=CombatResult::WINGAME
      else
        combat_result=CombatResult::WIN
      end

    else
      applyBadConsequence(m)
      combat_result=CombatResult::LOSE
    end
    return combat_result
  end
  
  def makeTreasureVisible(t)
    can_i=canMakeTreasureVisible(t) 

    if(can_i)
      @visibleTreasures << t 
      @hiddenTreasures.delete(t)
    end
  end
  
  def discardVisibleTreasure(t)
    @visibleTreasures.delete(t)
    if (@pendingBadConsequence != nil && !@pendingBadConsequence.isEmpty)
      @pendingBadConsequence.substractVisibleTreasure(t)
    end
    dieIfNoTreasure
  end
  
  def discardHiddenTreasure(t)
    @hiddenTreasures.delete(t)
    if(@pendingBadConsequence != nil && !@pendingBadConsequence.isEmpty)
      @pendingBadConsequence.substractHiddenTreasure(t)
    end
    dieIfNoTreasures
  end
  
  def validState
     return ( @pendingBadConsequence.isEmpty && (@hiddenTreasures.size <= 4) )
  end
  
  def initTreasures
    return (@pendingBadConsequence == nil || @pendingBadConsequence.isEmpty) && @hiddenTreasures.length<=4
  end
  
  
  def initTreasures
    dealer=CardDealer.instance
    dice=Dice.instance

    bringToLife

    treasure=dealer.nextTreasure
    @hiddenTreasures << treasure
    number=dice.nextNumber

    if(number > 1)
      treasure=dealer.nextTreasure
      @hiddenTreasures << treasure
    end

    if(number == 6)
      treasure=dealer.nextTreasure
      @hiddenTreasures << treasure
    end
  end
  
  def stealTreasure

    if(@canISteal)
      can_you=@enemy.canYouGiveMeATreasure

      if(can_you)
        treasure=@enemy.giveMeATreasure
        @hiddenTreasures << treasure
        haveStolen
        return treasure

      else
        return nil
      end
    else
      return nil
    end
  end
  
  
  def giveMeATreasure
     @hiddenTreasures.at(rand(@hiddenTreasures.length + 1))
  end
  
  
  def canYouGiveMeATreasure
     !@hiddenTreasures.empty?
  end
  
  def haveStolen
     @canISteal = false
  end
 
  def discardAllTreasures
    v=@visibleTreasures

    v.each do |vi|
      discardVisibleTreasure(vi)
    end

    h= @hiddenTreasures

    h.each do |hi| 
      discardHiddenTreasure(hi) 
    end
  end
def setEnemy(enem)
    @enemy=enem
end
end
