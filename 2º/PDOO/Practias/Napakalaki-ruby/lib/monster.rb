# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative "prize.rb"
require_relative "bad_consequence.rb"
require_relative "treasure_kind.rb"

class Monster
  attr_accessor :name
  attr_accessor :combatLevel
  attr_accessor :prize
  attr_accessor :bc
  
  def initialize(name, combatLevel, prize, bc)
    @name = name
    @combatLevel = combatLevel
    @prize = prize
    @bc = bc
    
  end
  def to_s
    "Nombre: #{@name} Nivel: #{@combatLevel} Premio: #{@prize} Mal rollo: #{@bc}"
  end
  
  def getLevelsGained
    @prize.level
  end

  def getTreasuresGained
    @prize.treasures
  end
  
end
