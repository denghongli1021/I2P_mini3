#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  static int minimax(State* root ,int depth , int self1);
  static Move get_move(State *state, int depth);
};