# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

module NapakalakiGame
  class Cultist
    attr_accessor :name, :gainedLevels
    def initialize(name, gainedLevels)
      @name=name
      @gainedLevels=gainedLevels
    end
    def getGainedLevels()
      return gainedLevels
    end
  end
end
