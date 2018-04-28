# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.

require_relative 'Monster.rb'
require_relative 'CardDealer.rb'
require_relative 'Player.rb'
require_relative 'Treasure.rb'
require_relative 'CombatResult.rb'
module NapakalakiGame
  require "singleton"
  class Napakalaki
    include Singleton
    attr_accessor :currentPlayer, :players, :dealer, :currentMonster
    def initialize
      @currentPlayer=nil
      @players=nil
      @dealer=nil
      @currentMonster=nil
    end
    def discardVisibleTreasures(treasures)
      treasures.each { |t|  
        @currentPlayer.discardVisibleTreasure(t)
        @dealer.giveTreasureBack(t)
      }
    end
    def discardHiddenTreasures(treasures)
      treasures.each { |t|  
        @currentPlayer.discardHiddenTreasure(t)
        @dealer.giveTreasureBack(t)
      }
    end
    def makeTreasuresVisible(treasures)
      treasures.each { |t|  
        @currentPlayer.makeTreasureVisible(t)
      }
    end
    def initGame(players)
      initPlayers(players)
      setEnemies();
      @dealer.initCards
      nextTurn
    end
    def getCurrentPlayer()
      return @currentPlayer
    end
    def getCurrentMonster()
      return @currentMonster
    end
    def nextTurn()
      stateOK=nextTurnAllowed()
      if(stateOK)then
        puts "Si puede pasar"
        @currentPlayer=nextPlayer()
        @currentMonster=@dealer.nextMonster
        if(@currentPlayer.isDead)then
          @currentPlayer.initTreasures
        end
      end
      return stateOK
    end
    def endOfGame(result)
      if(result==CombatResult::WINGAME)then
        return true
      else
        return false
      end
    end
    def initPlayers(names)
      @dealer=CardDealer.instance
      @players=Array.new
      names.each { |i|  
        @players<<Player.new(i)
      }
    end
    def nextPlayer()
      total=@players.length-1
      if(@currentPlayer==nil)then
        nextI=rand(total)
      else
        cpi=@players.index(@currentPlayer)
        if(cpi==total)then
          nextI=0
        else
          nextI=cpi+1
        end
      end
      @currentPlayer=@players.at(nextI)
      return @currentPlayer
    end
    def nextTurnAllowed
      if(@currentPlayer==nil)then
        return true
      else
        return @currentPlayer.validState
      end
    end
    def developCombat
      a=@currentPlayer.combat(@currentMonster)
      @dealer.giveMonsterBack(@currentMonster)
      if(a==CombatResult::LOSEANDCONVERT)then
        puts "Vamos a convertirnos"
        c=dealer.nextCultist
        cp=CultistPlayer.new(@currentPlayer,c)
        @players.insert(@players.index(@currentPlayer), cp)
        @players.each { |p|  
          if(p.getEnemy==@currentPlayer)then
            p.setEnemy(cp)
          end
        }
        @currentPlayer=cp
      end
      return a
    end
    def setEnemies()
      @players.each { |i|  
        otro=true
        while(otro)do
          a=rand(@players.size)
          if(i!=@players.at(a))then
            i.setEnemy(@players.at(a))
            otro=false
          end
        end
      }
    end
  end
end
