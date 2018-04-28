# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Player.rb'
require_relative 'Monster.rb'
module NapakalakiGame
  class CultistPlayer < Player
    @@totalCultistPlayers=0
    def CultistPlayer.totalCultistPlayers
      return @@totalCultistPlayers
    end
    attr_accessor :myCultistCard
    def initialize(p,c)
      @myCultistCard=c
      super(p.name)
      InicializarTodas(p)
    end
    def giveMeATreasure
      return super.stealTreasure
    end
    def canYouGiveMeATreasure()
      if(super.getHiddenTreasures.size!=0)then
        return true
      else
        return false
      end
    end
    def to_s
      "Soy un cultist  #{@myCultistCard}--->#{super.to_s}"
    end
    protected
    def getCombatLevel()
      return getCombatLevel
    end
    def getOponentLevel(m)
      return m.getCombatLevelAgainstCultistPlayer()
    end
    def shouldConvert
      return false
    end
  end
end
