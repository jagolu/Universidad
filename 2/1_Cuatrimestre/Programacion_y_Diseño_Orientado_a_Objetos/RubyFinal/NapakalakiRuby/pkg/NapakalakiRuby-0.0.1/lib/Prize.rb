# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
module NapakalakiGame
class Prize
  attr_accessor :levels, :treasures
  
  def initialize(t,l)
    @levels = l
    @treasures = t
  end
 end
end

