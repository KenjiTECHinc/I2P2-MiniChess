#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
/*
class Random{
public:
  static Move get_move(State *state, int depth);
};*/

class Random{
public:
  static Move get_move(State *state, int depth); //get all legal actions
};

int minimax_alphabeta(State *state, int depth, bool maximizingPlayer, int alpha, int beta);
