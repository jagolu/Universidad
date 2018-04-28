# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

module NapakalakiGame
  class Treasure
    attr_accessor :name, :bonus, :type
    def initialize(n, bonus, t)
      @name=n
      @bonus=bonus
      @type=t
    end
    def to_s()
      "#{@name} tipo: #{@type} bonus->#{@bonus}"
    end
  end
end
