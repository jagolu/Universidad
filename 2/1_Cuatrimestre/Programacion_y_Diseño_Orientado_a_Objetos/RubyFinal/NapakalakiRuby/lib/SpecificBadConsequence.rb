# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'TreasureKind.rb'
module NapakalakiGame
  class SpecificBadConsequence < BadConsequence
    def initialize(text,levels,svt,sht)
      super(text,levels)
      @specificHiddenTreasures=sht
      @specificVisibleTreasures=svt
    end
    def getSpecificHiddenTreasures()
      return @specificHiddenTreasures
    end
    def getSpecificVisibleTreasures()
      return @specificVisibleTreasures
    end
    def substractVisibleTreasure(t)
      if(!@specificVisibleTreasures.empty?)then
        encontrado=false
        @specificVisibleTreasures.each { |t2|  
          if(t2==t.type && !encontrado)then
            encontrado=true
          end
        }
        if(encontrado)then
          @specificVisibleTreasures.delete(t.type)
        end
      end
    end
    def substractHiddenTreasure(t)
      if(!@specificHiddenTreasures.empty?)then
        encontrado=false
        @specificHiddenTreasures.each { |t2|  
          if(t2==t.type && !encontrado)then
            encontrado=true
          end
        }
        if(encontrado)then
          @specificHiddenTreasures.delete(t.type)
        end
      end
    end
    def isEmpty()
      if(@specificHiddenTreasures.empty? && @specificVisibleTreasures.empty?)then
        return true
      else
        return false
      end
    end
    def adjustTreasures(a,b)
      a2=a
      treasures=Array.new
      a2.each { |tk|  
        encontrado=false
        i=0
        b.each { |t|  
          if(t.type==tk && !encontrado)then
            encontrado=true
            treasures<<tk
            a2.delete_at(i)
          end
        }
        i=i+1
      }
      return treasures
    end
    def adjustToFitTreasureLists(v,h)
      pbc=nil
      if(!@specificVisibleTreasures.empty? || !@specificHiddenTreasures.empty?)then
        svt=Array.new
        sht=Array.new
        svt=adjustTreasures(@specificVisibleTreasures,v)
        sht=adjustTreasures(@specificHiddenTreasures,h)
        puts "specific-->#{svt}   #{sht}"
        pbc=SpecificBadConsequence.new("",0, svt, sht)
      end
      return pbc
    end
  end
end
#