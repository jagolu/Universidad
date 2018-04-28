#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player{
    public:
      Player(int jug);
      Environment::ActionType Think();
      void Perceive(const Environment &env);
      double minimax_conPodaAB(const Environment &env,int jug, int prof,double a,double b,bool MaxMin);
    private:
      int jugador_;
      Environment actual_;
};
#endif
