//algorithm
#include <cstdlib>
#include <algorithm>
#include <iostream>

#include "../state/state.hpp"
#include "./mini_alphabeta.hpp"
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

int mini_alphabeta(State *state, int depth, bool maximizingPlayer, int alpha, int beta){
  // int now_res = state->game_state;
  // if(now_res == 1 && !maximizingPlayer){
  //   delete state;
  //   return 1000000;
  // }
  // if(now_res==DRAW){
  //   delete state;
  //   return 0;
  // }
  if(depth==4){
    int score = state->evaluate();
    delete state;
    return score;
  }
  int best;
  if(maximizingPlayer){
    best = -1000000;
    for(auto move: state->legal_actions){
      int score = mini_alphabeta(state->next_state(move), depth+1,false, alpha, beta);
      if(score > alpha){
        if (score>=best) best = score;
        alpha = score;
      }
      if(alpha >= beta) break;
    }
    return alpha;
  }
  else{
    best = 1000000;
    for(auto move: state->legal_actions){
      int score = mini_alphabeta(state->next_state(move), depth+1,true, alpha, beta);
      if(score < beta){  
        if (score<=best) best = score;
        beta = score;
      }
      if(alpha >= beta) break;  
    }
    return beta;
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
  //std::cout << best_move.first.first << " " << best_move.first.second << " " << best_move.second.first << " " << best_move.second.second << std::endl;
  return best_move;
};
