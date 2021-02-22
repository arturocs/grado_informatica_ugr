# encoding: utf-8

require 'singleton'
require_relative 'treasure'
require_relative 'monster'
require_relative 'prize'
require_relative 'bad_consequence'


class CardDealer
  include Singleton

  private
  
  def initTreasureCardDeck
    @unusedTreasures=Array.new
    @usedTreasures=Array.new

    @unusedTreasures << Treasure.new("¡Sí mi amo!",4, TreasureKind::HELMET);
    @unusedTreasures << Treasure.new("Botas de investigación",3, TreasureKind::SHOES);
    @unusedTreasures << Treasure.new("Capucha de Cthulhu",3, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("A prueba de babas",2, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Botas de lluvia ácida", 1, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Casco minero",2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Ametralladora ACME",4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Camiseta de la ETSIIT", 1, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Clavo de rail ferroviario",3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Cuchillo de sushi arcano",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Fez alópodo", 3, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Hacha prehistórica",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("El aparato del Pr. Tesla",4, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Gaita",4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Insecticida",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Escopeta de 3 cañones", 4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Garabato Mistico",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("La rebeca metálica",2, TreasureKind::ARMOR)
    @unusedTreasures << Treasure.new("Lanzallamas",4, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necro-comicón", 1, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necronomicón",5, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Linterna a 2 manos",3, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Necro-gnomicón",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necrotelecom",2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Mazo de los antiguos",3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Necro-playboycon",3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Porra preternatural",2, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Shogulador",1, TreasureKind::BOTHHANDS)
    @unusedTreasures << Treasure.new("Varita de atizamiento",3, TreasureKind::ONEHAND)
    @unusedTreasures << Treasure.new("Tentácula de pega",2, TreasureKind::HELMET)
    @unusedTreasures << Treasure.new("Zapato deja-amigos",1, TreasureKind::SHOES)
    
    shuffleTreasures
  end

  def initMonsterCardDeck
    @unusedMonsters=Array.new
    @usedMonsters= Array.new

    p1=Prize.new(2,1)
    b1=BadConsequence.newLevelSpecificTreasures("Pierdes tu armadura visible y otra oculta",0,[TreasureKind::ARMOR],[TreasureKind::ARMOR])
    @unusedMonsters << Monster.new("3 Byakhees de bonanza",8,p1,b1)

    p2=Prize.new(1,1)
    b2=BadConsequence.newLevelSpecificTreasures("Embobados con el lindo primigenio te descartas de tu casco visible",0,[TreasureKind::HELMET],0)
    @unusedMonsters << Monster.new("Tenochtitlan",2,p2,b2)

    p3=Prize.new(1,1)
    b3=BadConsequence.newLevelSpecificTreasures("El primordial bostezo contagioso.Pierdes el calzado visible",0,[TreasureKind::SHOES],0)
    @unusedMonsters << Monster.new("El sopor de Dunwich",2,p3,b3)

    p4=Prize.new(4,1)
    b4=BadConsequence.newLevelSpecificTreasures("Te atrapan para llevarte de fiesta y dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta",0,[TreasureKind::ONEHAND],[TreasureKind::ONEHAND])
    @unusedMonsters << Monster.new("Demonios de Magaluf",2,p4,b4)

    p5=Prize.new(3,1)
    b5=BadConsequence.newLevelNumberOfTreasures("Pierdes todos tus tesoros visibles",0,10,0)
    @unusedMonsters << Monster.new("El gorron en el umbral",13,p5,b5)

    p6=Prize.new(2,1)
    b6=BadConsequence.newLevelSpecificTreasures("Pierdes la armadura visible",0,[TreasureKind::ARMOR],0)
    @unusedMonsters << Monster.new("H.P. Munchcraft",6,p6,b6)

    p7=Prize.new(1,1)
    b7=BadConsequence.newLevelSpecificTreasures("Sientes bichos bajo la ropa. Descarta la armadura visible",0,[TreasureKind::ARMOR],0)
    @unusedMonsters << Monster.new("Necrofago",13,p7,b7)

    p8=Prize.new(3,2)
    b8=BadConsequence.newLevelNumberOfTreasures("Pierdes 5 niveles y 3 tesoros visibles.",5,3,0)
    @unusedMonsters << Monster.new("El rey del rosado",11,p8,b8)

    p9=Prize.new(1,1)
    b9=BadConsequence.newLevelNumberOfTreasures("Toses los pulmones y pierdes 2 niveles.",2,0,0)
    @unusedMonsters << Monster.new("Flecher",2,p9,b9)

    p10=Prize.new(2,1)
    b10=BadConsequence.newDeath("Estos monstruos resultan bastante superficiales y te aburren mortalmente")
    @unusedMonsters << Monster.new("Los Hondos",8,p10,b10)

    p11=Prize.new(2,1)
    b11=BadConsequence.newLevelNumberOfTreasures("Pierdes 2 niveles y 2 tesoros ocultos",2,0,2)
    @unusedMonsters << Monster.new("Semillas Cthulhu",4,p11,b11)

    p12=Prize.new(2,1)
    b12=BadConsequence.newLevelSpecificTreasures("Te intentas escaquear. Pierdes una mano visible.",0,[TreasureKind::ONEHAND],0)
    @unusedMonsters << Monster.new("Dameargo",1,p12,b12)

    p13=Prize.new(2,1)
    b13=BadConsequence.newLevelNumberOfTreasures("Da mucho asquito. Pierdes 3 niveles.",3,0,0)
    @unusedMonsters << Monster.new("Pollipolipo volante",3,p13,b13)

    p14=Prize.new(3,1)
    b14=BadConsequence.newDeath("No le hace gracia que pronuncien mal su nombre. Estas muerto")
    @unusedMonsters << Monster.new("YskhtihyssgGoth",14,p14,b14)

    p15=Prize.new(3,1)
    b15=BadConsequence.newDeath("La familia te atrapa. Estas muerto")
    @unusedMonsters << Monster.new("Familia feliz",1,p15,b15)

    p16=Prize.new(2,1)
    b16=BadConsequence.newLevelSpecificTreasures("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible",2,[TreasureKind::BOTHHANDS],0)
    @unusedMonsters << Monster.new("Roboggoth",8,p16,b16)

    p17=Prize.new(1,1)
    b17=BadConsequence.newLevelSpecificTreasures("Te asusta en la noche. Pierdes un casco visible.",0,[TreasureKind::HELMET],0)
    @unusedMonsters << Monster.new("El espia sordo",5,p17,b17)

    p18=Prize.new(2,1)
    b18=BadConsequence.newLevelNumberOfTreasures("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles",2,5,0)
    @unusedMonsters << Monster.new("Tongue",19,p18,b18)

    p19=Prize.new(2,1)
    b19=BadConsequence.newLevelNumberOfTreasures("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos.",3,10,0)
    @unusedMonsters << Monster.new("Bicefalo",21,p19,b19)
    
    shuffleMonsters
  end

  def shuffleTreasures
    @unusedTreasures.shuffle!
    @usedTreasures.shuffle!
  end

  def shuffleMonsters
    @unusedMonsters.shuffle!
    @usedMonsters.shuffle!
  end

  public
  
  def nextTreasure
    if(@unusedTreasures.empty?)

      @usedTreasures.each do |x|
        @unusedTreasures << x
      end

      shuffleTreasures

      @usedTreasures.clear
    end

    treas=@unusedTreasures[0]
    

    giveTreasureBack(treas)

    @unusedTreasures.delete(treas)

    return treas
  end

  def nextMonster
    if(@unusedMonsters.empty?)

      @usedMonsters.each do |x|
        @unusedMonsters << x
      end

      shuffleMonsters

      @usedMonsters.clear
    end

    treas=@unusedMonsters.at(0)

    giveMonsterBack(treas)

    @unusedMonsters.delete(treas)

    return treas
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
  
