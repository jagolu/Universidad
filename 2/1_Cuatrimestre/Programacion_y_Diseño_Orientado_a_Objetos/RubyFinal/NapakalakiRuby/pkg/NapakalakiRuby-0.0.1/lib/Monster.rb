# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Prize.rb'
require_relative 'BadConsequence.rb'
module NapakalakiGame
class Monster
  attr_reader :name, :combatlevel, :prize, :badConsequence
  def initialize(n, l, b, p)
    @name = n
    @combatlevel = l
    @prize = p
    @badConsequence = b
  end
  def getLevelsGained()
    return prize.levels
  end
  def getTreasuresGained()
    return prize.treasures
  end
  
  
  
  
  
  
  
  
  
  def to_s
   "#{@name}, nivel de combate = #{@combatlevel}  " +badConsequence.to_s
  end
end
end
