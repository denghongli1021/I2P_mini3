// #include <cstdlib>

// #include "../state/state.hpp"
// #include "./alphabeta.hpp"

// int max(int a,int b) {
//     return a>b?a:b;
// }
// int max(int a,int b) {
//     return a<b?a:b;
// }
// /**
//  * @brief Randomly get a legal action
//  * 
//  * @param state Now state
//  * @param depth You may need this for other policy
//  * @return Move 
//  */
// static int alphabeta(State& root ,int depth , bool maximizeplayer,int alpha,int beta) {
//     if (depth == 0 || ) {
//         return ;
//     }
//     int value;
//     if (maximizeplayer) {
//         value = -INT_MAX;
//         for (auto& state:) {
            
//             int eval = minimax(state , depth-1 ,!maximizeplayer);
//             value = max(value,eval);
//         }
//         return value;
//     }
//     else {
//         value = INT_MAX;
//         for (auto& state:) {
            
//             int eval = minimax(state , depth-1 ,!maximizeplayer);
//             value = min(value,eval);
//         }
//         return value;
//     }
// }

// Move AlpBe::get_move(State *state, int depth){
//     if(!state->legal_actions.size())
//         state->get_legal_actions();

//     int maxvalue = -2e9;
//     auto next_moves = state->legal_actions;
//     Move next_move;
//     for (auto &next : next_moves) {
//         int tmp = state->next_state(next)->evaluate();
//         if (tmp > maxvalue) {
//             maxvalue = tmp;
//             next_move = next;
//         }
//     }
//     if (next_move.first == next_move.second) {
//         next_move = next_moves[(rand()+depth)%next_moves.size()];
//     }
//     return next_move;
// //   if(!state->legal_actions.size())
// //     state->get_legal_actions();
  
// //   auto actions = state->legal_actions;
// //   return actions[(rand()+depth)%actions.size()];
// }