#include <cstdlib>
#include <climits>
#include <iostream>
#include "../state/state.hpp"
#include "./alphabeta.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
// int self2 = 0;
// int setyet2 = 0;

int max(int a,int b) {
    return a>b?a:b;
}
int min(int a,int b) {
    return a<b?a:b;
}

int AlpBe::alphabeta(State* root ,int depth , int self2,int alpha,int beta) {
    //std::cout << "alphabeta depth : " << depth << "\n";
    if (depth == 0) {
        return root->evaluate(self2);
    }
    root->get_legal_actions();
    if (root->legal_actions.empty()) {
        return root->evaluate(self2);
    }

    int eval;
    if (root->player == self2) {
        eval = INT_MIN;
        for (auto state : root->legal_actions) {
            eval = max(eval,alphabeta(root->next_state(state) , depth-1 ,self2 ,alpha,beta));
            alpha = max(alpha,eval);
            if (alpha >= beta) {
                break;
            }
        }
        return eval;
    }
    else {
        eval = INT_MAX;
        for (auto state : root->legal_actions) {
            eval = min(eval,alphabeta(root->next_state(state) , depth-1 ,self2 ,alpha,beta));
            beta = min(beta,eval);
            if (beta <= alpha) {
                break;
            }
        }
        return eval;
    }
}
 
Move AlpBe::get_move(State *state, int depth){
    // if (!setyet2) {
    //     setyet2 = 1;
    //     self2 = state->player;
    // }
    if(!state->legal_actions.size())
        state->get_legal_actions();
    int maxvalue = -2e9;
    depth += 1;
    depth -= 1;
    auto next_moves = state->legal_actions;
    Move next_move;
    
    for (auto next : next_moves) {
        int tmp = alphabeta(state->next_state(next), 4 , state->player ,INT_MIN , INT_MAX);
        // 這裡應該還要改
        if (tmp > maxvalue) {
            maxvalue = tmp;
            next_move = next;
        }
    }
    return next_move;
//   auto actions = state->legal_actions;
//   return actions[(rand()+depth)%actions.size()];
}