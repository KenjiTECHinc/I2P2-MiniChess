//algorithm
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "../state/state.hpp"
#include "./mini_alphabeta.hpp"
using namespace std;
std::ofstream fout("test.txt", std::ios::app);
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

int mini_alphabeta(State *state, int depth, bool maximizingPlayer, int alpha, int beta){
//  if(state->game_state == WIN && maximizingPlayer){
//      delete state;
//      return -1000000;
//  }
//  else if(now_res == 1 && !maximizingPlayer){
//   delete state;
//   return 1000000;
//  }
  // if(now_res==DRAW){
  //   delete state;
  //   return 0;
  // }
  if(depth==3){
    int score = state->evaluate();
    delete state;
    return score;
  }
  if(maximizingPlayer){
    int best = -1000000;
    for(auto move: state->legal_actions){
      best = max(best, mini_alphabeta(state->next_state(move), depth+1,false, alpha, beta));
      alpha = max(alpha, best);
      if(alpha >= beta) break;
    }
    fout << "This is maximizing player's best: "
    return best;
  }
  else{
    int best = 1000000;
    for(auto move: state->legal_actions){
      best = min(best, mini_alphabeta(state->next_state(move), depth+1,true, alpha, beta));
      beta = min(beta, best);
      if(beta <= alpha) break;  
    }
    return best;
  }
  //return best;
};

Move Mini_AlphaBeta::get_move(State *state, int depth){
  Move best_move = state->legal_actions[state->legal_actions.size() - 1];
  int best_score = -1000000;

  for(Move move: state->legal_actions){
    int score = mini_alphabeta(state->next_state(move), depth, true, -1000000, 1000000);
    //if(score > best_score){ // <-- originally this one.
    if(score>best_score){ //this part can cause the opening move to be the same. find a new opening move. 
      best_move = move;
      best_score = score;
    }
  }
  //Debug.
  return best_move;
};
