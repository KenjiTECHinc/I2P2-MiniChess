//algorithm
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "../state/state.hpp"
#include "./submission.hpp"
using namespace std;
//std::ofstream fout("test.txt", std::ios::app);
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

int submission_abp(State *state, int depth, bool maximizingPlayer, int alpha, int beta){
  if(depth==5){
    return state->evaluate();
    //int score= state->evaluate();
    //delete state;
    //return score;
  }
  if(maximizingPlayer){
    int maximize_best = -1000000000;
    for(auto move: state->legal_actions){
      maximize_best = max(maximize_best, submission_abp(state->next_state(move), depth+1,false, alpha, beta));
      alpha = max(alpha, maximize_best);
      if(alpha >= beta) break;
    }
    //fout << "This is maximizing player's best at depth " << depth << ": " << max_best << endl;
    return maximize_best;
  }
  else{
    int minimize_best = 1000000000;
    for(auto move: state->legal_actions){
      minimize_best = min(minimize_best, submission_abp(state->next_state(move), depth+1,true, alpha, beta));
      beta = min(beta, minimize_best);
      if(beta <= alpha) break;  
    }
    //fout << "This is minimizing player's best at depth " << depth << ": " << min_best << endl;
    return minimize_best;
  }
  //return best;
};

Move submission::get_move(State *state, int depth){
  if(!state->legal_actions.size())state->get_legal_actions();
  Move best_move; //= state->legal_actions[state->legal_actions.size() - 1];
  int best_score = -1000000000;

  for(Move move: state->legal_actions){
    int score = submission_abp(state->next_state(move), depth, false, -1000000000, 1000000000); //start as minimizer?
    if(score>best_score){ //this part can cause the opening move to be the same. find a new opening move. 
      best_move = move;
      best_score = score;
    }
  }
  //if(best_move.first == best_move.second) best_move = state->legal_actions[0];
  //Debug.
  //fout << "Best move is " << best_move.first.first << " " << best_move.first.second << " to " << best_move.second.first << " " << best_move.second.first << endl;
  return best_move;
};
