#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"
using namespace std;

/**
 * @brief Get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
Move Minimax::get_move(State *state, int depth){
  Move best_move = state->legal_actions[state->legal_actions.size()-1];
  int best_score = -1000000000;

  for(Move move: state->legal_actions){
    int score = minimax(state->next_state(move), depth,true);
    if(score>best_score){
      best_move = move;
      best_score = score;
    }
  }

  return best_move;
};

int Minimax::minimax(State *state, int depth, bool maximizingPlayer){
  int now_res = state->game_state;
  if(now_res == 1){
    delete state;
    return -1000000;
  }
  if(now_res==DRAW){
    delete state;
    return 0;
  }
  if(depth==3){
    int score = state->evaluate();
    delete state;
    return score;
  }
  int best;
  if(maximizingPlayer){
    best = -1000000;
    for(auto move: state->legal_actions){
    int score = minimax(state->next_state(move), depth+1,false);
    if (score>=best)
      best = score;
    }
  }
  else{
    best = 1000000;
    for(auto move: state->legal_actions){
    int score = minimax(state->next_state(move), depth+1,true);
    if (score<=best)
      best = score;
    }
  }
  return best;
};
