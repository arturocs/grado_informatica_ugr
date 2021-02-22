# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

class Prize
 
  attr_reader :treasures #Consultor forma 1
  def level #Consultor forma 2
    @level
  end
  
  
  def initialize(treasures,level) 
      @treasures = treasures
      @level = level
  end  
  
  def to_s
    "Tesoros ganados: #{@treasures} Niveles ganados: #{@level}"
  end
  
end
