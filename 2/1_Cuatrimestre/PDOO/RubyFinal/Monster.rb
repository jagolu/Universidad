# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Prize.rb'
require_relative 'Player.rb'
require_relative 'CultistPlayer.rb'
require_relative 'BadConsequence.rb'
module NapakalakiGame
class Monster
  attr_reader :name, :combatlevel, :prize, :badConsequence, :levelChangeAgainstCultistPlayer
  def initialize(n, l, b, p,ic=0)
    @name = n
    @combatlevel = l
    @prize = p
    @badConsequence = b
    @levelChangeAgainstCultistPlayer=ic
  end
  def self.MonsterAgainstCultistPlayer(n,l,bc,p,ic)
    new(n,l,bc,p,ic)
  end
  def getLevelsGained()
    return prize.levels
  end
  def getTreasuresGained()
    return prize.treasures
  end
  def getCombatLevelAgainstCultistPlayer
    return @combatLevel+@levelChangeAgainstCultistPlayer
  end
  def to_s()
    "#{@name}, nivel->#{@combatLevel}  #{@prize.to_s}   #{@badConsequence.to_s}"
  end
  
  
  
  
  
  
  
  
  
  def to_s
   "#{@name}, nivel de combate = #{@combatlevel}  " +badConsequence.to_s
  end
end
end
