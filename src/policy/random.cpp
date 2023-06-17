//algorithm
#include <cstdlib>
#include <iostream>

#include "../state/state.hpp"
#include "./random.hpp"
using namespace std;

/**
 * @brief Randomly get a legal action
 *
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move
 */
/*
Move Random::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();

  auto actions = state->legal_actions;
  return actions[(rand()+depth)%actions.size()];
}*/

int minimax(State *state, int depth, bool maximizingPlayer){
  // int now_res = state->game_state;
  // if(now_res == 1 && !maximizingPlayer){
  //   delete state;
  //   return 1000000;
  // }
  // if(now_res==DRAW){
  //   delete state;
  //   return 0;
  // }
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

Move Random::get_move(State *state, int depth){
  Move best_move = Move(Point(-1,-1),Point(-1,-1));
  int best_score = -1000000;

  for(Move move: state->legal_actions){
    int score = minimax(state->next_state(move), depth, true);
    //if(score > best_score){ // <-- originally this one.
    if(score>=best_score){ //this part can cause the opening move to be the same. find a new opening move. 
      best_move = move;
      best_score = score;
    }
  }
  //Debug.
  //std::cout << best_move.first.first << " " << best_move.first.second << " " << best_move.second.first << " " << best_move.second.second << std::endl;
  return best_move;
};
