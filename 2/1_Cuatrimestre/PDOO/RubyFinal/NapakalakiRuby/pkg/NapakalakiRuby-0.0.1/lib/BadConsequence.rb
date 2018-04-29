# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'Monster.rb'
require_relative 'TreasureKind.rb'
module NapakalakiGame
  

class BadConsequence
  @@MAXTREASURES=10
  def self.MAXTREASURES
    @@MAXTREASURES
  end
  attr_accessor :text, :levels, :nVisibleTreasures, :nHiddenTreasures, :specificVisibleTreasures, :specificHiddenTreasures, :death
  def  initialize(aText, someLevels=0, someVisibleTreasures, someHiddenTreasures, someSpecificVisibleTreasures, someSpecificHiddenTreasures, death) 
    @text = aText;
    @levels = someLevels
    @nVisibleTreasures = someVisibleTreasures
    @nHiddenTreasures = someHiddenTreasures
    @specificVisibleTreasures = someSpecificVisibleTreasures
    @specificHiddenTreasures = someSpecificHiddenTreasures
    @death = death
  end
  
  def BadConsequence.MAXTREASURES
   return @@MAXTREASURES
  end
  def isEmpty()
    if(@nVisibleTreasures==0 && @nHiddenTreasures==0 && @specificHiddenTreasures.empty? && @specificVisibleTreasures.empty?)then
        return true
    else
      return false
    end
  end
 
  def substractVisibleTreasure(t)
    if(@nVisibleTreasures!=0)then
      @nVisibleTreasures=@nVisibleTreasures-1
    end
    if(!@specificVisibleTreasures.empty?)then
      i=0
      encontrado=false
      @specificVisibleTreasures.each { |t2|  
        if(t2==t.type && !encontrado)then
          encontrado=true
          i=@specificVisibleTreasures.index(t2)
        end
      }
      if(encontrado)then
        @specificVisibleTreasures.delete_at(i)
      end
    end
  end
  
  def substractHiddenTreasure(t)
    if(@nHiddenTreasures!=0)then
      @nHiddenTreasures=@nHiddenTreasures-1
    end
    if(!@specificHiddenTreasures.empty?)then
      encontrado=false
      @specificHiddenTreasures.each { |t2|  
        if(t2==t.type && !encontrado)then
          encontrado=true
          @specificHiddenTreasures.delete(t2)
        end
      }
    end
  end
  
  def self.newLevelNumberOfTreasures (t, l, v, h)
    new(t,l,v,h,Array.new, Array.new, false) 
  end
  def self.newLevelSpecificTreasures (t, l, v, h)
    new(t,l,0,0,v,h,false)
  end

  def self.newDeath (t,death)
    new(t,Player.MAXLEVEL,@@MAXTREASURES,@@MAXTREASURES,Array.new,Array.new ,death)
  end
  def adjustTreasures(a,b)
    treasures=Array.new
    b.each { |t|  
      encontrado=false
      a.each { |t2|  
        if(t2==t.type && !encontrado)then
          treasures<<t2
          encontrado=true
        end
      }
    }
    return treasures
  end
  def adjustToFitTreasureLists(v,h)
    pbc=nil
    if(@nVisibleTreasures !=0 || @nHiddenTreasures!=0)then
      nvt=[@nVisibleTreasures, v.size].min
      nht=[@nHiddenTreasures,h.size].min
      pbc=BadConsequence.newLevelNumberOfTreasures("", 0, nvt, nht);
    elsif(!@specificVisibleTreasures.empty? || !@specificHiddenTreasures.empty?)then
      svt=Array.new
      sht=Array.new
      svt=adjustTreasures(@specificVisibleTreasures,v)
      sht=adjustTreasures(@specificHiddenTreasures,h)
      pbc=BadConsequence.newLevelSpecificTreasures("",0, svt, sht)
    end
    return pbc
  end
  
  def to_s()
    "#{@text}, niveles perdidos=#{@levels}, tesoros visibles=#{@nVisibleTreasures}, tesoros escondidos=#{@nHiddenTreasures}, muerte=#{@death}"
  end

end

end
