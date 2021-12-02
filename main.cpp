#include <iostream>

#include "tic_tac_toe.h"

int main()
{
    ttt::tic_tac_toe game;
    while (!game.is_game_over())
    {
        int input;
        do
        {
            std::cout << "input (0-8): ";
            std::cin >> input;
        }
        while (!game.is_possible_turn(input) && []() {std::cout << "Invalid turn!" << std::endl; return true; }());

        game.make_turn(input);
        std::cout << game.str();
    }
    auto winner = game.get_winner();
    if (winner.has_value())
    {
        std::cout << "Winner is " << ttt_side::chr(winner.value()) << "!" << std::endl;
    }
    else
    {
        std::cout << "Draw!" << std::endl;
    }
}
