# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Monster.rb'
require_relative 'TreasureKind.rb'
module NapakalakiGame
  

class BadConsequence
  @@MAXTREASURES=10
  def BadConsequence.MAXTREASURES
   return @@MAXTREASURES
  end
  attr_accessor :text, :levels, :nVisibleTreasures, :nHiddenTreasures, :specificVisibleTreasures, :specificHiddenTreasures, :death
  def  initialize(aText, someLevels) 
    @text = aText;
    @levels = someLevels
  end
 
  
  
  def to_s()
    "#{@text}, niveles->#{@levels}"
  end

end

end
