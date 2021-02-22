# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'treasure_kind'
class Treasure
  attr_accessor :name
  attr_accessor :bonus
  attr_accessor :type
  
  def initialize(n, bonus, t)
    @name=n
    @bonus=bonus
    @type=t
    
  end
def to_s
      return " Nombre: #{@name} Tipo: #{@type} Bonus: +#{@bonus}"
end
end
