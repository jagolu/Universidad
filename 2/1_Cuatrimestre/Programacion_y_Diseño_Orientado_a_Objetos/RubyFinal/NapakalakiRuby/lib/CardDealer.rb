# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'Treasure.rb'
require_relative 'Monster.rb'
require_relative 'BadConsequence.rb'
require_relative 'SpecificBadConsequence.rb'
require_relative 'NumericBadConsequence.rb'
require_relative 'DeathBadConsequence.rb'
require_relative 'Prize.rb'
require_relative 'TreasureKind.rb'
require_relative 'Cultist.rb'

  
module NapakalakiGame
require "singleton"
  
  
  class CardDealer
    include Singleton
    attr_accessor :usedMonsters, :unusedMonsters, :usedTreasures, :unusedTreasures, :unusedCultists
    def initialize
      @unusedTreasures=Array.new
      @usedTreasures=Array.new
      @unusedMonsters=Array.new
      @usedMonsters=Array.new
      @unusedCultists=Array.new
    end
    def nextTreasure
      if(@unusedTreasures.empty?)then
        self.initTreasureCardDeck()
        self.shuffleTreasures()
        @usedTreasures.clear
      end
      t=@unusedTreasures.at(@unusedTreasures.size-1)
      @unusedTreasures.delete_at(@unusedTreasures.size-1)
      return t
    end
    def nextMonster()
      if(@unusedMonsters.empty?)then
        self.initMonsterCardDeck()
        self.shuffleMonsters()
        @usedMonsters.clear
      end
      m=@unusedMonsters.at(@unusedMonsters.size-1)
      @unusedMonsters.delete_at(@unusedMonsters.size-1)
      @usedMonsters<<m
      return m
    end
    def nextCultist()
      if(@unusedCultists.empty?)then
        initCultistCardDeck
      end
      c=@unusedCultists.at(@unusedCultists.size-1)
      @unusedCultists.delete(c)
      return c
    end
    def giveTreasureBack(t)
      usedTreasures<<t
    end
    def giveMonsterBack(m)
      usedMonsters<<m
    end
    def initCards
      initTreasureCardDeck
      initMonsterCardDeck
      initCultistCardDeck()
    end
    def initTreasureCardDeck()
      t=Treasure.new("!Si mi amo!", 4, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("Botas de investigacion", 3, [TreasureKind::SHOES])
      @unusedTreasures<<t
      t=Treasure.new("Capucha de Cthulhu", 3, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("A prueba de babas", 2, [TreasureKind::ARMOR])
      @unusedTreasures<<t
      t=Treasure.new("Botas de lluvia acida", 1, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Casco minero", 2, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("Ametralladora Thompson", 4, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Camiseta de la UGR", 3, [TreasureKind::ARMOR])
      @unusedTreasures<<t
      t=Treasure.new("Clavo de rail ferroviario", 3, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Cuchillo de sushi arcano", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Fez alopodo", 3, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("Hacha prehistorica", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("El aparato del Pr. Tesla", 4, [TreasureKind::ARMOR])
      @unusedTreasures<<t
      t=Treasure.new("Gaita", 4, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Insecticida", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Escopeta de 3 canones", 4, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Garabato mistico", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("La rebeca metalica", 2, [TreasureKind::ARMOR])
      @unusedTreasures<<t
      t=Treasure.new("Lanzallamas", 4, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Necro-comicon", 1, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Necronomicon", 5, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Linterna a 2 manos", 3, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Necro-gnomicon", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Necrotelecom", 2, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("Mazo de los antiguos", 3, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Necro-playboycon", 3, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Porra preternatural", 2, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Shogulador", 1, [TreasureKind::BOTHHANDS])
      @unusedTreasures<<t
      t=Treasure.new("Varita de atizamiento", 3, [TreasureKind::ONEHAND])
      @unusedTreasures<<t
      t=Treasure.new("Tentaculo de pega", 2, [TreasureKind::HELMET])
      @unusedTreasures<<t
      t=Treasure.new("Zapato deja-amigos", 1, [TreasureKind::SHOES])
      @unusedTreasures<<t
      shuffleTreasures
    end
    def initMonsterCardDeck()
     
      prize = Prize.new(2, 1)
      bc = SpecificBadConsequence.new('Pierdes tu armadura visible y otra oculta', 0, [TreasureKind::ARMOR],[TreasureKind::ARMOR])
      @unusedMonsters << Monster.new('3 Byakhess de bonanza', 8, bc, prize)
      prize = Prize.new(1, 1)
      bc = SpecificBadConsequence.new('Embobados con el lindo primigenio te descartas de tu casco visible', 0, [TreasureKind::HELMET], Array.new)
      @unusedMonsters << Monster.new('Chibithulhu', 2, bc, prize)
      prize = Prize.new(1, 1)
      bc = SpecificBadConsequence.new('El primordial bostezo contagioso. Pierdes el calzado visible', 0, [TreasureKind::SHOES], Array.new)
      @unusedMonsters << Monster.new('El sopor de Dunwich', 2, bc, prize)
      prize = Prize.new(4, 1)
      bc= SpecificBadConsequence.new('Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta', 0, [TreasureKind::ONEHAND], [TreasureKind::ONEHAND])
      @unusedMonsters << Monster.new('Angeles de la noche ibicenca', 14, bc, prize)
      prize = Prize.new(3, 1)
      bc = NumericBadConsequence.new('Pierdes todos tus tesoros visibles', 0, BadConsequence.MAXTREASURES, 0)
      @unusedMonsters << Monster.new('El gorron en el umbral', 10, bc, prize)
      prize = Prize.new(2, 1)
      bc = SpecificBadConsequence.new('Pierdes la armadura visible', 0, [TreasureKind::ARMOR], Array.new)
      @unusedMonsters << Monster.new('H.P Munchcraft', 6, bc, prize)
      prize = Prize.new(4, 1)
      bc = SpecificBadConsequence.new('Sientes bichos bajo la ropa. Descarta la armadura visible', 0, [TreasureKind::ARMOR], Array.new)
      @unusedMonsters << Monster.new('Bichgooth', 2, bc, prize)
      prize = Prize.new(4,2)
      bc = NumericBadConsequence.new('Pierdes 5 niveles y 3 tesoros visibles',5 , 3, 0)
      @unusedMonsters << Monster.new('El rey de rosa',13,bc, prize)
      prize = Prize.new(1,1)
      bc = NumericBadConsequence.new('Toses los pulmones y pierdes 2 niveles', 2, 0, 0)
      @unusedMonsters << Monster.new('La que redacta en las tinieblas', 2, bc, prize)
      prize = Prize.new(2, 1)
     bc = DeathBadConsequence.new('Estos monstruos resultan bastante superficiales y te aburres mortalmente. Estas muerto')
     @unusedMonsters << Monster.new('Los hondos', 8, bc, prize)
      prize = Prize.new(2, 1)
      bc = NumericBadConsequence.new('Pierdes 2 niveles y 2 tesoros ocultos', 2, 0, 2)
      @unusedMonsters << Monster.new('Semillas Cthulhu', 4, bc, prize)
      prize = Prize.new(2, 1)
      bc = SpecificBadConsequence.new('Te intentas escaquear. Pierdes una mano visble', 1, [TreasureKind::ONEHAND], Array.new)
      @unusedMonsters << Monster.new('Dameargo', 1, bc, prize)
      prize = Prize.new(1, 1)
      bc = NumericBadConsequence.new('Da mucho asquito. Pierdes 3 niveles', 3, 0, 0)
      @unusedMonsters << Monster.new('Pollipolipo volante', 3, bc, prize)
      prize = Prize.new(3, 1)
      bc = DeathBadConsequence.new('No le hace gracia que pronuncien mal su nombre. Estas muerto')
      @unusedMonsters << Monster.new('YskhtihyssgGoth', 12, bc, prize)
      prize = Prize.new(4, 1)
      bc = DeathBadConsequence.new('La familia te atrapa. Estas muerto')
      @unusedMonsters << Monster.new('Familia feliz', 1, bc, prize)
      prize = Prize.new(2, 1)
      bc = SpecificBadConsequence.new('La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible', 2, [TreasureKind::BOTHHANDS], Array.new)
      @unusedMonsters << Monster.new('Roboggoth', 8, bc, prize)
      prize = Prize.new(1, 1)
      bc = SpecificBadConsequence.new('Te asusta en la noche. Pierdes un casco visible', 0, [TreasureKind::HELMET], Array.new)
      @unusedMonsters << Monster.new('El espia', 5, bc, prize)
      prize = Prize.new(1, 1)
      bc = NumericBadConsequence.new('Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles', 2, 5, 0)
      @unusedMonsters << Monster.new('El lenguas', 20, bc, prize)
      prize = Prize.new(1, 1)
      bc = SpecificBadConsequence.new('Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos', 3,[TreasureKind::BOTHHANDS], Array.new)
      @unusedMonsters << Monster.new('Bicefalo', 20, bc, prize)
      
           
      shuffleMonsters
    end
    def initCultistCardDeck()
      @unusedCultists<<Cultist.new("Sectario 1",1)
      @unusedCultists<<Cultist.new("Sectario 2",2)
      @unusedCultists<<Cultist.new("Sectario 3",1)
      @unusedCultists<<Cultist.new("Sectario 4",2)
      @unusedCultists<<Cultist.new("Sectario 5",1)
      @unusedCultists<<Cultist.new("Sectario 6",1)
      shuffleMonsters()
    end
    def shuffleCultists()
      @unusedCultists=@unusedCultists.shuffle
    end
    def shuffleTreasures()
      @unusedTreasures=@unusedTreasures.shuffle
    end
    def shuffleMonsters()
      @unusedMonsters=@unusedMonsters.shuffle
    end
    
  end
end
