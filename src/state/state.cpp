#include <iostream>
#include <sstream>
#include <cstdint>

#include "./state.hpp"
#include "../config.hpp"


/**
 * @brief evaluate the state
 *
 * @return int
 */
int State::evaluate(){
int piece_lock[7] = {0,1,4,5,6,17,700};
// int ene_pawn = 1.5;
// int ene_rook = 3;
// int ene_knight = 4.5;
// int ene_bishop = 6;
// int ene_queen = 7.5;
// int ene_king = 9;

int pawn_value = 2;
int rook_value = 6;
int knight_value = 7;
int bishop_value = 8;
int queen_value = 20;
int king_value = 1000;

int score = 0; //default heuristic at 0. My score.
for(int i=0; i<2; i++){ //select which board to loop through
  int i_player = i;
    for(int j=0; j<6; j++){
      for(int k=0; k<5; k++){
        auto piece = this->board.board[i][j][k];
        switch(piece){
          case 1: //pawn
            //if(i_player == player){
              if(i_player == 0){
                if(j-1 >=0 && k-1 >=0){
                    auto check_enemy = this->board.board[1-i_player][j-1][k-1];
                    if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  
                    auto check_ally = this->board.board[i_player][j-1][k-1];
                    if(check_ally == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_ally == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_ally == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_ally == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_ally == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_ally == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  }

                if(j-1 >=0 && k+1 < BOARD_W){
                    auto check_enemy = this->board.board[1-i_player][j-1][k+1];
                    if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  

                    auto check_ally = this->board.board[i_player][j-1][k+1];
                    if(check_ally == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_ally == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_ally == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_ally == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_ally == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_ally == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  }
              }
              else if(i_player == 1){
                if(j+1 < BOARD_H && k-1 >=0){
                    auto check_enemy = this->board.board[1-i_player][j+1][k-1];
                    if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];

                    auto check_ally = this->board.board[i_player][j+1][k-1];
                    if(check_ally == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_ally == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_ally == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_ally == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_ally == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_ally == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  }
                
                if(j+1 < BOARD_H && k+1 < BOARD_W){
                    auto check_enemy = this->board.board[1-i_player][j+1][k+1];
                    if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                  
                    auto check_ally = this->board.board[i_player][j+1][k+1];
                    if(check_ally == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                    else if(check_ally == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                    else if(check_ally == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                    else if(check_ally == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                    else if(check_ally == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                    else if(check_ally == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                    else score += piece_lock[0];
                }
              }
            //}
            score += (i_player == player)? pawn_value: -(pawn_value);
            break;
          case 2: //rook
            // if(i_player == player){
            for(int l=1; l< 6; l++){
              if(j-l >=0){
                auto check_enemy = this->board.board[1-i_player][j-l][k];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j+l < BOARD_H){
                auto check_enemy = this->board.board[1-i_player][j+1][k];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(k-l >=0){
                auto check_enemy = this->board.board[1-i_player][j][k-l];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(k+l < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j][k+l];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
            }
            
            score += (i_player == player)? rook_value: -(rook_value);
            break; 
          case 3: //knight
            // if(i_player == player){ //check eatable pieces around knight.
              if(j-2 >=0 && k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j-2>=0 && k+1 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j-1 >=0 && k+2 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j+1 <BOARD_H && k+2 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if( j+2 < BOARD_H && k+1 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j+2 < BOARD_H && k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j+1 < BOARD_H && k-2 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j-1 >=0 && k-2 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
            // }
            score += (i_player == player)? knight_value: -(knight_value);
            break;
          case 4:
            // if(i_player == player){
              for(int l=1; l<5; l++){
                if(j-l >= 0 && k-l >=0){
                  auto check_enemy = this->board.board[1-i_player][j-l][k-l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
                if(j-l >=0 && k+l < BOARD_W){
                  auto check_enemy = this->board.board[1-i_player][j-l][k+l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
                if(j+l < BOARD_H && k+l < BOARD_W){
                  auto check_enemy = this->board.board[1-i_player][j+l][k+l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
          
                }
                if(j+l < BOARD_H && k-l >=0){
                  auto check_enemy = this->board.board[1-i_player][j+l][k-l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
              }
            // }
            score += (i_player == player)? bishop_value : -(bishop_value);
            break;
          case 5:
            // if(i_player == player){
              for(int l=1; l<6; l++){
                if(j-l >=0){
                auto check_enemy = this->board.board[1-i_player][j-l][k];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(j+l < BOARD_H){
                auto check_enemy = this->board.board[1-i_player][j+1][k];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(k-l >=0){
                auto check_enemy = this->board.board[1-i_player][j][k-l];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
              if(k+l < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j][k+l];
                if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                else score += piece_lock[0];
              }
                //diagonal
              for(int l=1; l<5; l++){
                if(j-l >= 0 && k-l >=0){
                  auto check_enemy = this->board.board[1-i_player][j-l][k-l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
                if(j-l >=0 && k+l < BOARD_W){
                  auto check_enemy = this->board.board[1-i_player][j-l][k+l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
                if(j+l < BOARD_H && k+l < BOARD_W){
                  auto check_enemy = this->board.board[1-i_player][j+l][k+l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
        
                }
                if(j+l < BOARD_H && k-l >=0){
                  auto check_enemy = this->board.board[1-i_player][j+l][k-l];
                  if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                  else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                  else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                  else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                  else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                  else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                  else score += piece_lock[0];
                }
              }
            }
            score += (i_player == player)? queen_value : -(queen_value);
            break;
          case 6:
            if(j-1 >=0){
              if(k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j-1][k-1];
                if(i_player == 1) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                // else score += piece_lock[0];
              }
              if(k+1 <BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-1][k+1];
                if(i_player == 1) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                // else score += piece_lock[0];
              }
              auto check_enemy = this->board.board[1-i_player][j-1][k];
              if(i_player == 1) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
              // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
              if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
              // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
              // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
              // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
              // else score += piece_lock[0];
            }
            if(j+1 < BOARD_H){
              if(k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j+1][k-1];
                if(i_player == 0) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                // else score += piece_lock[0];
              }
              if(k+1 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j+1][k+1];
                if(i_player == 0) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
                // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
                if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
                // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
                // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
                // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
                // else score += piece_lock[0];
              }
              auto check_enemy = this->board.board[1-i_player][j+1][k];
              if(i_player == 0) if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
              // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
              if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
              // else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
              // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
              // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
              // else score += piece_lock[0];
            }
            if(k-1 >=0){
              auto check_enemy = this->board.board[1-i_player][j][k-1];
              if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
              // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
              else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
              else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
              // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
              // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
              // else score += piece_lock[0];
            }
            if(k+1 < BOARD_W){
              auto check_enemy = this->board.board[1-i_player][j][k+1];
              if(check_enemy == '1') score += (i_player == player)? piece_lock[1] : -(piece_lock[1]);
              // else if(check_enemy == '2') score += (i_player == player)? piece_lock[2] : -(piece_lock[2]);
              else if(check_enemy == '3') score += (i_player == player)? piece_lock[3] : -(piece_lock[3]);
              else if(check_enemy == '4') score += (i_player == player)? piece_lock[4] : -(piece_lock[4]);
              // else if(check_enemy == '5') score += (i_player == player)? piece_lock[5] : -(piece_lock[5]);
              // else if(check_enemy == '6') score += (i_player == player)? piece_lock[6] : -(piece_lock[6]);
              // else score += piece_lock[0];
            }
            //check for knights
            if(j-2 >=0 && k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j-2>=0 && k+1 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j-1 >=0 && k+2 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j+1 <BOARD_H && k+2 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if( j+2 < BOARD_H && k+1 < BOARD_W){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j+2 < BOARD_H && k-1 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j+1 < BOARD_H && k-2 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
              if(j-1 >=0 && k-2 >=0){
                auto check_enemy = this->board.board[1-i_player][j-2][k-1];
                if(check_enemy == '3') score += (i_player == player)? -(500) : (500);
              }
            //END check knight

            score += (i_player == player)? king_value : -(king_value);
            break;
          default:
            score += 0;
            break;
        }
      }
    }
  }
  return score; //return heuristic score.
}


/**
 * @brief return next state after the move
 *
 * @param move
 * @return State*
 */
State* State::next_state(Move move){
  Board next = this->board;
  Point from = move.first, to = move.second;

  int8_t moved = next.board[this->player][from.first][from.second];
  //promotion for pawn
  if(moved == 1 && (to.first==BOARD_H-1 || to.first==0)){
    moved = 5;
  }
  if(next.board[1-this->player][to.first][to.second]){
    next.board[1-this->player][to.first][to.second] = 0;
  }

  next.board[this->player][from.first][from.second] = 0;
  next.board[this->player][to.first][to.second] = moved;

  State* next_state = new State(next, 1-this->player);

  if(this->game_state != WIN)
    next_state->get_legal_actions();
  return next_state;
}


static const int move_table_rook_bishop[8][7][2] = { /// NOTE: Shared with Queen.
  {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}},                 //rook moves horizontal right
  {{0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}},          //rook moves moves horizontal left
  {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}},                 //rook moves vertical down
  {{-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}},          //rook moves vertical up
  {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}},                 //bishop moves right-down
  {{1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}},          //bishop moves right-up
  {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}},          //bishop moves left-down
  {{-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}},   //bishop moves left-up
};
static const int move_table_knight[8][2] = {
  {1, 2}, {1, -2},      //horizontal L - bottom hemisphere
  {-1, 2}, {-1, -2},    //horizontal L - top hemisphere
  {2, 1}, {2, -1},      //upright L - bottom hemisphere
  {-2, 1}, {-2, -1},    //upright L - top hemisphere
};
static const int move_table_king[8][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1},     //sideway moves
  {1, 1}, {1, -1}, {-1, 1}, {-1, -1},   //vertical moves
};


/**
 * @brief get all legal actions of now state
 *
 */
void State::get_legal_actions(){
  // [Optional]
  // This method is not very efficient
  // You can redesign it
  this->game_state = NONE;
  std::vector<Move> all_actions;
  auto self_board = this->board.board[this->player];
  auto oppn_board = this->board.board[1 - this->player];

  int now_piece, oppn_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece=self_board[i][j])){
        // std::cout << this->player << "," << now_piece << ' ';
        switch (now_piece){
          case 1: //pawn
            if(this->player && i<BOARD_H-1){
              //black
              if(!oppn_board[i+1][j] && !self_board[i+1][j])
                all_actions.push_back(Move(Point(i, j), Point(i+1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i+1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i+1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }else if(!this->player && i>0){
              //white
              if(!oppn_board[i-1][j] && !self_board[i-1][j])
                all_actions.push_back(Move(Point(i, j), Point(i-1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i-1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i-1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }
            break;

          case 2: //rook
          case 4: //bishop
          case 5: //queen
            int st, end;
            switch (now_piece){
              case 2: st=0; end=4; break; //rook
              case 4: st=4; end=8; break; //bishop
              case 5: st=0; end=8; break; //queen
              default: st=0; end=-1;
            }
            for(int part=st; part<end; part+=1){
              auto move_list = move_table_rook_bishop[part];
              for(int k=0; k<std::max(BOARD_H, BOARD_W); k+=1){
                int p[2] = {move_list[k][0] + i, move_list[k][1] + j};

                if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) break; //out of bound
                now_piece = self_board[p[0]][p[1]];
                if(now_piece) break;

                all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));

                oppn_piece = oppn_board[p[0]][p[1]];
                if(oppn_piece){
                  if(oppn_piece==6){
                    this->game_state = WIN;
                    this->legal_actions = all_actions;
                    return;
                  }else
                    break;
                };
              }
            }
            break;

          case 3: //knight
            for(auto move: move_table_knight){
              int x = move[0] + i;
              int y = move[1] + j;

              if(x>=BOARD_H || x<0 || y>=BOARD_W || y<0) continue;
              now_piece = self_board[x][y];
              if(now_piece) continue;
              all_actions.push_back(Move(Point(i, j), Point(x, y)));

              oppn_piece = oppn_board[x][y];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;

          case 6: //king
            for(auto move: move_table_king){
              int p[2] = {move[0] + i, move[1] + j};

              if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) continue;
              now_piece = self_board[p[0]][p[1]];
              if(now_piece) continue;

              all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));

              oppn_piece = oppn_board[p[0]][p[1]];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
        }
      }
    }
  }
  std::cout << "\n";
  this->legal_actions = all_actions; 
}


const char piece_table[2][7][5] = {
  {" ", "♙", "♖", "♘", "♗", "♕", "♔"},
  {" ", "♟", "♜", "♞", "♝", "♛", "♚"}
};
/**
 * @brief encode the output for command line output
 *
 * @return std::string
 */
std::string State::encode_output(){
  std::stringstream ss;
  int now_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece = this->board.board[0][i][j])){
        ss << std::string(piece_table[0][now_piece]);
      }else if((now_piece = this->board.board[1][i][j])){
        ss << std::string(piece_table[1][now_piece]);
      }else{
        ss << " ";
      }
      ss << " ";
    }
    ss << "\n";
  }
  return ss.str();
}


/**
 * @brief encode the state to the format for player
 *
 * @return std::string
 */
std::string State::encode_state(){
  std::stringstream ss;
  ss << this->player;
  ss << "\n";
  for(int pl=0; pl<2; pl+=1){
    for(int i=0; i<BOARD_H; i+=1){
      for(int j=0; j<BOARD_W; j+=1){
        ss << int(this->board.board[pl][i][j]);
        ss << " ";
      }
      ss << "\n";
    }
    ss << "\n";
  }
  return ss.str();
}
