# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative "prize.rb"
require_relative "monster.rb"
require_relative "bad_consequence.rb"

class PruebaNapakalaki
  @@monsters = Array.new
  def self.aniadirmonstruos
     
    #3 Byakhees de bonaza
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures('Pierdes tu armadura visible y otra oculta', 0, [TreasureKind::ARMOR], [TreasureKind::ARMOR]) 
    @@monsters << Monster.new('3 Byakhees de bonaza', 8, prize, badConsequence)
      
    #Tenechtitlan
    prize =   Prize.new(1, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("Embobados con el lindo primigenio te descartas de tu casco ", 0, [TreasureKind::HELMET], [])
    @@monsters << Monster.new("Tenechtitlan", 2, prize, badConsequence)
      
    #El sopor de Dunwich
    prize =   Prize.new(1, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("El primordial bostezo contagioso. Pierdes el calzado visible", 0, [TreasureKind::SHOES],[] )                            
    @@monsters <<  Monster.new("El sopor de Dunwich", 2, prize, badConsequence)
      
    #Demonios de Magaluf
    prize =   Prize.new(4, 1)
    badConsequence =  BadConsequence.newLevelNumberOfTreasures("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta", 0, 1, 1)
    @@monsters << Monster.new("Demonios de Magaluf", 2, prize, badConsequence)  
    
    #El gorron en el umbral
    prize =   Prize.new(3, 1)
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Pierdes todos tus tesoros visibles", 0, 0, 0)
    @@monsters << Monster.new("El gorron en el umbral", 13, prize, badConsequence)
    
    #H.P. Munchcraft  
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("Pierdes la armadura visible", 0, [TreasureKind::ARMOR],[] )
    @@monsters << Monster.new("H.P. Munchcraft", 6, prize, badConsequence)                    
    
    #Necrofago
    prize =   Prize.new(1, 1) 
    badConsequence = BadConsequence.newLevelSpecificTreasures("Sientes bichos bajo la ropa. Descarta la armadura visible", 0, [TreasureKind::ARMOR], [])
    @@monsters <<  Monster.new("Necrofago", 13, prize, badConsequence)  
    
    #El rey rosado
    prize = Prize.new(3, 2)
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Pierdes 5 niveles y 3 tesoros visibles", 5, 3, 0)  
    @@monsters << Monster.new("El rey rosado", 11, prize, badConsequence)  
    
    #Flecher
    prize =   Prize.new(1, 1) 
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles", 2, 0, 0)
    @@monsters << Monster.new("Flecher", 2, prize, badConsequence) 

    #Los hondos
    prize =   Prize.new(2, 1) 
    badConsequence = BadConsequence.newDeath("Estos monstruos resultan bastantes superficiales y te aburren mortalmente. Estas muerto")
    @@monsters <<  Monster.new("Los hondos", 8, prize, badConsequence)
    
    #Semillas Cthulhu
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles", 2, 0, 0)    
    @@monsters <<  Monster.new("Semillas Cthulhu", 4, prize, badConsequence) 
    
    #Dameargo
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("Te intentas escaquear. Pierdes una mano visible ", 0, [TreasureKind::ONEHAND],[])
    @@monsters << Monster.new("Dameargo", 1, prize, badConsequence)
    
    #Pollipolipo volante
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Da mucho asquito. Pierdes 3 niveles.", 3, 0, 0)
    @@monsters << Monster.new("Pollipolipo volante", 3, prize, badConsequence)
    
    #Yskhtihyssg-Goth
    prize =   Prize.new(3, 1)
    badConsequence = BadConsequence.newDeath("No le hace gracia que pronuncien mal su nombre.Estas muerto.")
    @@monsters << Monster.new("Yskhtihyssg-Goth", 14,  prize, badConsequence)
    
    #Familia feliz
    prize =   Prize.new(3, 1)
    badConsequence = BadConsequence.newDeath("La familia te atrapa. Estas muerto")
    @@monsters << Monster.new("Familia feliz", 1, prize, badConsequence)
    
    #Roboggoth
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2, [TreasureKind::BOTHHANDS], [])
    @@monsters << Monster.new("Roboggoth", 8, prize, badConsequence)
   
    #El espia sordo
    prize =   Prize.new(1, 1)
    badConsequence = BadConsequence.newLevelSpecificTreasures("Te austa en la noche. Pierdes un casco visible", 0, [TreasureKind::HELMET], [])
    @@monsters << Monster.new("El espia sordo", 5, prize, badConsequence)

    #Tongue
    prize =   Prize.new(2, 1)  
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2, 5, 0)
    @@monsters << Monster.new("Tongue", 19,  prize, badConsequence)
    
    #Bicefalo
    prize =   Prize.new(2, 1)
    badConsequence = BadConsequence.newLevelNumberOfTreasures("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3, 10000, 0)
    @@monsters << Monster.new("Bicefalo", 21, prize, badConsequence)
    
  end
  
  #Funcion que devuelve los monstruos con un nivel superior a 10
  def self.masDeDiez
    @resultado = Array.new
    for m in @@monsters
      if m.combatLevel < 10
        @resultado << m 
      end
    end
    return @resultado
   end 
 
  #Funcion que devuelve los montruos que unicamente causan perdida de nivel como mal rollo 
  def self.perdidaDeNivel
    @resultado = Array.new
    for m in @@monsters
      if m.bc.levels > 0 and m.bc.death == false and m.bc.nHiddenTreasures == 0 and m.bc.nVisibleTreasures == 0 and m.bc.specificHiddenTreasures.empty? and m.bc.specificVisibleTreasures.empty?
        @resultado << m 
      end   
    end
    return @resultado
  end
  
  
  #Funcion que devuelve los monstruos cuyo buen rollo indica una ganancia de nivel superior a 1
  def self.nivelSup1
    @resultado = Array.new
    for m in @@monsters
      if m.prize.level > 1
        @resultado << m 
      end
    end
    @resultado << m 
  end
  
  #Funcion que devuelve los monstruos cuyo mal rollo supone la pérdida de un determinado tipo de tesoro 
  def self.perdidaDeTesoro( treasureKind )
    @resultado = Array.new
      for m in @@monsters
        if m.bc.specificHiddenTreasures.include?(treasureKind) or m.bc.specificVisibleTreasures().include?(treasureKind)
          @resultado << m 
        end
      end
    @resultado << m 
  end   
=begin
  def self.main
    PruebaNapakalaki.aniadirmonstruos
    puts PruebaNapakalaki.masDeDiez
    puts PruebaNapakalaki.perdidaDeNivel
    puts PruebaNapakalaki.nivelSup1
    puts PruebaNapakalaki.perdidaDeTesoro(TreasureKind::ARMOR)
    puts PruebaNapakalaki.perdidaDeTesoro(TreasureKind::ONEHAND)
    puts PruebaNapakalaki.perdidaDeTesoro(TreasureKind::BOTHHANDS)
    puts PruebaNapakalaki.perdidaDeTesoro(TreasureKind::HELMET)
    puts PruebaNapakalaki.perdidaDeTesoro(TreasureKind::SHOES)
    
  end
end

PruebaNapakalaki.main 

=end
end