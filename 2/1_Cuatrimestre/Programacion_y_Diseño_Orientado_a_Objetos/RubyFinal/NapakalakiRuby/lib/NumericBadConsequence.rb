# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

module NapakalakiGame
  class NumericBadConsequence < BadConsequence
    def initialize(text,level,nVisibleTreasures,nHiddenTreasures)
      super(text,level)
      @nHiddenTreasures=nHiddenTreasures
      @nVisibleTreasures=nVisibleTreasures
    end
    def getNVisibleTreasures
      return @nVisibleTreasures
    end
    def getNHiddenTreasures
      return @nHiddenTreasures
    end
    def substractVisibleTreasure(t)
      if(@nVisibleTreasures!=0)then
        @nVisibleTreasures=@nVisibleTreasures-1
      end  
    end
    def substractHiddenTreasure(t)
      if(@nHiddenTreasures!=0)then
        @nHiddenTreasures=@nHiddenTreasures-1
      end
    end
    def adjustToFitTreasureLists(v,h)
      pbc=nil
      if(@nVisibleTreasures !=0 || @nHiddenTreasures!=0)then
        nvt=[@nVisibleTreasures,v.size].min
        nht=[@nHiddenTreasures,h.size].min 
        pbc=NumericBadConsequence.new("", 0, nvt, nht);
      end
      return pbc
    end
    def isEmpty()
      if(@nVisibleTreasures==0 && @nHiddenTreasures==0)then
        return true
      else
        return false
      end
    end
  end
end
