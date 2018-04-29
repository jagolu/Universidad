# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
require_relative 'BadConsequence.rb'
require_relative 'Treasure.rb'
require_relative 'TreasureKind.rb'
require_relative 'Monster.rb'
require_relative 'CombatResult.rb'
require_relative 'Dice.rb'
module NapakalakiGame
  class Player
    @@MAXLEVEL=10
    def self.MAXLEVEL
      @@MAXLEVEL
    end
    attr_accessor :name, :level, :hiddenTreasures, :visibleTreasures, :dead, :pendingBadConsequence, :enemy
    def initialize(name)
      @name=name
      @dead=true
      @level=1
      @visibleTreasures=Array.new
      @hiddenTreasures=Array.new
    end
    def getHiddenTreasures()
      return @hiddenTreasures
    end
    def getVisibleTreasures()
      return @visibleTreasures
    end
    def isDead()
      if(@dead)then
        return true
      else
        return false
      end
    end
    def combat(m)
      myLevel=getCombatLevel
      monsterLevel=m.combatlevel
        if(myLevel>monsterLevel)then
          applyPrize(m)
          if @level>=10 then
            return CombatResult::WINGAME
          else
            return CombatResult::WIN
          end
        else
          applyBadConsequence(m)
          return CombatResult::LOSE
        end
    end
    def makeTreasureVisible(t)
        canI=self.canMakeTreasureVisible(t)
        if(canI)then
          @visibleTreasures<<t
          @hiddenTreasures.delete(t)
        end
    end
    def discardVisibleTreasure(t)
      @visibleTreasures.delete(t)
      if( (@pendingBadConsequence!=nil) && (!@pendingBadConsequence.isEmpty) )then
        @pendingBadConsequence.substractVisibleTreasure(t)
      end
      self.diefNoTreasures()
    end
    def discardHiddenTreasure(t)
      @hiddenTreasures.delete(t)
      if( (@pendingBadConsequence!=nil) && (!@pendingBadConsequence.isEmpty) )then
        @pendingBadConsequence.substractHiddenTreasure(t)
      end
      self.diefNoTreasures()
    end
    def validState()
      if (@pendingBadConsequence==nil) then
        return true
      elsif(@pendingBadConsequence.isEmpty && @hiddenTreasures.size<=4)then
        return true
      else
        return false
      end
    end
    def initTreasures()
      dealer=CardDealer.instance
      dice=Dice.instance
      bringToLife
      treasure=dealer.nextTreasure
      @hiddenTreasures<<treasure
      number=dice.nextNumber
      if(number>1)then
        treasure=dealer.nextTreasure
        @hiddenTreasures<<treasure
      end
      if(number==6)then
        treasure=dealer.nextTreasure
        @hiddenTreasures<<treasure
      end
    end
    def stealTreasure()
      t=Treasure.new
      t=nil
      if(self.canISteal && @enemy.canYouGiveMeATreasure())then
        t=@enemy.giveMeATreasure
        @hiddenTreasures<<t
        self.haveStolen
      end
      return t
    end
    def setEnemy(enemy)
      @enemy=enemy
    end
    def canISteal()
      return @canISteal
    end
    def discardAllTreasures()
      vt=@visibleTreasures
      hd=@hiddenTreasures
      vt.each { |t|  
        discardVisibleTreasure(t)
      }
      hd.each { |t|  
        discardHiddenTreasure(t)
      }
    end
    def bringToLife()
      @dead=false
    end
    def getCombatLevel()
      nc=0
      nc=@level+nc
      visibleTreasures.each { |vt|  
        nc=nc+vt.Bonus
      }
      return nc
    end
    def incrementLevels(l)
      @level=@level+l
    end
    def decrementLevels(l)
      @level=@level-l
      if (@level<1)then
        @level=1
      end
    end
    def setPendingBadConsequence(b)
      @pendingBadConsequence=b
    end
    def applyPrize(m)
      nLevels=m.getLevelsGained
      self.incrementLevels(nLevels)
      nTreasures=m.getTreasuresGained
      if(nTreasures>0)then
        dealer=CardDealer.getInstance
        for i in(0.. nTreasures)
          @hiddenTreasures<<dealer.nextTreasure()
        end
      end
    end
    def applyBadConsequence(m)
      nLevels=m.badConsequence.levels
      decrementLevels(nLevels)
      @pendingBadConsequence=m.badConsequence.adjustToFitTreasureLists(@visibleTreasures, @hiddenTreasures)
      setPendingBadConsequence(@pendingBadConsequence)
    end
    def canMakeTreasureVisible(t)
      podemos=true
      @visibleTreasures.each { |t2|  
        if(t2.type==t.type)then
          podemos=false
        end
        if( (t2.type==TreasureKind::ONEHAND || t2.type==TreasureKind::BOTHHANDS) && (t.type==TreasureKind::ONEHAND || t.type==TreasureKind::BOTHHANDS) )then
          podemos=false
        end
      }
      return podemos
    end
    def howManyVisibleTreasures(tKind)
      count=0
      @visibleTreasures.each { |i|  
        if(i.type==tKind)then
          count=count+1
        end
      }
      return count
    end
    def diefNoTreasures()
      if(hiddenTreasures.empty? && visibleTreasures.empty?)then
        dead=true
      end
    end
    def giveMeATreasure()
      if(canYouGiveMeATreasure)then
        i=rand(@hiddenTreasures.size)
        t=@hiddenTreasures.at(i)
        @hiddenTreasures.delete_at(i)
        return t
      else
        return nil
      end
    end
    def canYouGiveMeATreasure()
      if(hiddenTreasures.empty?)
        return false
      else 
        return true
      end
    end
    def haveStolen()
      @canISteal=false
    end
    def to_s() 
      "#{@name}"
    end
    
   
  end
end
