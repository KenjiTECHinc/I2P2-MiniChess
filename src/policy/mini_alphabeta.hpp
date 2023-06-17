#pragma once
#include "../state/state.hpp"
#include <vector>
using namespace std;


/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */

class Mini_AlphaBeta{
public:
  static Move get_move(State *state, int depth); //get all legal actions
};
int mini_alphabeta(State *state, int depth, bool maximizingPlayer, int alpha, int beta);
