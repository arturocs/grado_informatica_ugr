# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require 'singleton'
require_relative 'card_dealer'
require_relative 'player'

class Napakalaki
  include Singleton
  
   attr_reader :currentPlayer
   attr_reader :players
   attr_reader :dealer
   attr_reader :currentMonster
  
  def initialize
    @players = Array.new
		@currentPlayer
		@currentMonster
    @dealer
  end
  def initPlayers(names)
    @dealer=CardDealer.instance
    
    names.each do |name|
      @players << Player.new(name)
    end
  end
  def nextPlayer
    if(@currentPlayer == nil)
      i=rand(@players.length)
    else
      j=@players.index(@currentPlayer)
      i=(j+1)%@players.length
      
    end    
    @currentPlayer=@players.at(i)  
    return @currentPlayer
  end
  def nextTurnAllowed
    if(@currentPlayer == nil)
      return true
    else
      return  @currentPlayer.validState
    end
  end
  def setEnemies
        @players.each do |x|
      i=rand(@players.length)

      while(i == @players.index(x)) do
        i=rand(@players.length)
      end

      x.setEnemy(@players[i])
    end
  end
  
  def self.getInstance
    return instance
  end
  
  def developCombat
    m = @currentMonster
    combat = @currentPlayer.combat(m)
    @dealer.giveMonsterBack(m)
    return combat
  end
  def discardVisibleTreasures(treasures)
    treasures.each do |descartar|
    @currentPlayer.discardVisibleTreasure(descartar)
    @dealer.giveTreasuresBack(descartar)
    end
  end
  
  def discardHiddenTreasures(treasures)
    treasures.each do |descartar|
    @currentPlayer.discardHiddenTreasure(descartar)
    @dealer.giveTreasuresBack(descartar)
     end
  end
  def makeTreasuresVisible(treasures)
    treasures.each do |t|
    @currentPlayer.makeTreasureVisible(t)
    end
  end
  def initGame(players)
    initPlayers(players)
    setEnemies
    dealer.initCards
    nextTurn
  end

  def nextTurn
    stateOK = nextTurnAllowed

    if stateOK
      @currentPlayer = nextPlayer
      @currentMonster = @dealer.nextMonster
      
      dead = @currentPlayer.isDead
      if dead
          @currentPlayer.initTreasures
      end
    end
    return stateOK;
  end
  def endOfGame
    if result == result.WINGAME
      return true
    end
 # else
      return false
  end
  def makeTreasuresVisible(treasures);
    
    treasures.each do |t| 
      @currentPlayer.makeTreasureVisible(t) 
    end 
  end
  
end
