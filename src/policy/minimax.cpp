#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
// int self1 = 0;
// int setyet1 = 0;

int Minimax::minimax (State* root ,int depth ,int self1) {
    if (depth == 0) {
        return root->evaluate(self1);
    }
    root->get_legal_actions();
    if (root->legal_actions.empty()) {
        return root->evaluate(self1);
    }

    int value;
    if (root->player == self1) {
        value = INT_MIN;
        for (auto state : root->legal_actions) {
            int eval = minimax(root->next_state(state) , depth-1 ,self1);
            if (value < eval) {
                value = eval;
            }
        }
        return value;
    }
    else {
        value = INT_MAX;
        for (auto state : root->legal_actions) {
            int eval = minimax(root->next_state(state) , depth-1 ,self1);
            if (value > eval) {
                value = eval;
            }
        }
        return value;
    }
}

Move Minimax::get_move(State *state, int depth){
    // if (!setyet1) {
    //     self1 = state->player;
    //     setyet1 = 1;
    // }
    state->get_legal_actions();
    int maxvalue = -2e9;
    auto next_moves = state->legal_actions;
    Move next_move;
    for (auto next : next_moves) {
        int tmp = minimax(state->next_state(next), depth-1, state->player);
        if (tmp > maxvalue) {
            maxvalue = tmp;
            next_move = next;
        }
    }
    return next_move;
//   auto actions = state->legal_actions;
//   return actions[(rand()+depth)%actions.size()];
}