# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require 'singleton'
require_relative 'treasure'
require_relative 'monster'
require_relative 'prize'
require_relative 'bad_consequence'
class CardDealer
  include Singleton
  
  def initialize
    @usedMonsters = Array.new
    @unusedMonsters = Array.new
    @usedTreasures = Array.new
    @unusedTreasures = Array.new
  end
  
  def initTreasureCardDeck
    @unusedTreasures = Array.new
    @unsuedTreasures << Treasure.new("Si mi amo!", 4, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Botas de investigacion", 3, TreasureKind::SHOES)
    @unusedTreasures << Treasure.new("Capucha de Cthulhu", 3, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("A prueba de babas", 2, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Botas de lluvia acida", 1, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Casco minero", 2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Ametralladora ACME", 4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Camiseta de la ETSIIT", 1, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Clavo de rail ferroviario", 3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Cuchillo de sushi arcano", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Fez alopodo", 3, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Hacha prehistorica", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("El aparato del PR. Tesla", 4, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Gaita", 4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Insecticida", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Escopeta de 3 canones", 4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Garabato mistico", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("La rebeca metalica", 2, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Lanzallamas", 4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necro-comicon", 1, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necronomicon", 5, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Linterna a 2 manos", 3, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necro-gnomicon", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necrotelecom", 2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Mazo de los antiguos", 3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necro-playboycon", 3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Porra preternatural", 2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Shogulador", 1, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Varita de atizamiento", 3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Tentoculo de pega", 2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Zapato deja-amigos", 1, TreasureKind::SHOES)
  end
  
  def initMonsterCardDeck
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
  
  def shuffleTreasures
     @unusedTreasures.shuffle!
  end
  
  def shuffleMonsters
     @unusedMonsters.shuffle!
  end
  
  def nextTreasure
    if !@unusedTreasures.empty?
      ret = @unusedTreasures[0]
      @unusedTreasures.delete(ret)
      return ret
    end
    @unusedTreasures = @usedTreasures
    @usedTreasures.clear
    shuffleTreasures
    ret = @unusedTreasures[0]
    @unusedTreasures.delete(ret)
    return ret  
  end
  
  def nextMonster
     if !@unusedMonsters.empty?
      ret = @unusedMonsters[0]
      @unusedMonsters.delete(ret)
      return ret
    end
    @unusedMonsters = @usedMonsters
    @usedMonsters.clear
    shuffleMonster
    ret = @unusedMonsters[0]
    @unusedMonsters.delete(ret)
    return ret
  end
  
  def giveTreasureBack(t)
    @usedTreasures << t
  end
  
  def giveMonsterBack(m)
    @usedMonsters << m
  end
  
  def initCards
    initTreasureCardDeck
    initMonsterCardDeck
  end
  
end
