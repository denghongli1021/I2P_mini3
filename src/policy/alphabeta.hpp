#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class AlpBe{
public:
  static int alphabeta(State& root ,int depth , bool maximizeplayer,int alpha,int beta);
  static Move get_move(State *state, int depth);
};