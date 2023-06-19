#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
int max(int a,int b) {
    return a>b?a:b;
}
int min(int a,int b) {
    return a<b?a:b;
}

int Minimax::minimax(State* root ,int depth , int maximizeplayer) {
    if (depth == 0) {
        return root->evaluate();
    }
    root->get_legal_actions();
    if (root->legal_actions.empty()) {
        return root->evaluate();
    }

    int value;
    if (maximizeplayer) {
        value = INT_MIN;
        for (auto state : root->legal_actions) {
            int eval = minimax(root->next_state(state) , depth-1 ,0);
            value = max(value,eval);
        }
        return value;
    }
    else {
        value = INT_MAX;
        for (auto state : root->legal_actions) {
            int eval = minimax(root->next_state(state) , depth-1 ,1);
            value = min(value,eval);
        }
        return value;
    }
}

Move Minimax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
        state->get_legal_actions();
    int maxvalue = -2e9;
    auto next_moves = state->legal_actions;
    Move next_move;
    for (auto next : next_moves) {
        int tmp = minimax(state->next_state(next), 4, 0);
        if (tmp > maxvalue) {
            maxvalue = tmp;
            next_move = next;
        }
    }
    return next_move;
//   auto actions = state->legal_actions;
//   return actions[(rand()+depth)%actions.size()];
}