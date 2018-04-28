# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

module NapakalakiGame
  class DeathBadConsequence < NumericBadConsequence
    def initialize(text)
      super(text,Player.MAXLEVEL,BadConsequence.MAXTREASURES,BadConsequence.MAXTREASURES)
    end
    def isEmpty()
      isEmpty
    end
  end
end
