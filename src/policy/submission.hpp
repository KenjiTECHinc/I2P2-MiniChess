#pragma once
#include "../state/state.hpp"
#include <vector>
using namespace std;


/**
 * @brief Policy class for random policy,
 * your policy class should have get_move method
 */

class submission{
public:
  static Move get_move(State *state, int depth); //get all legal actions
};
int submission_abp(State *state, int depth, bool maximizingPlayer, int alpha, int beta);
