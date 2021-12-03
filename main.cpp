#include <iostream>

#include "tic_tac_toe.h"


//server, always moves first
int main()
{
    ttt::tic_tac_toe game;
    bool yourTurn = true;


    while (!game.is_game_over())
    {
        int input;
        if (yourTurn)
        {
            do
            {
                std::cout << "input (0-8): ";
                std::cin >> input;
            } while (!game.is_possible_turn(input) && []() {std::cout << "Invalid turn!" << std::endl; return true; }());
            //sendToClient(input);
        }
        else
        {
            input = 0;//getFromClient();
        }

        game.make_turn(input);
        std::cout << game.str();

        yourTurn = !yourTurn;
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

//client, moves second
int clientmain()
{
    ttt::tic_tac_toe game;
    bool yourTurn = false;

    while (!game.is_game_over())
    {
        int input;
        do
        {
            std::cout << "input (0-8): ";
            std::cin >> input;
        } while (!game.is_possible_turn(input) && []() {std::cout << "Invalid turn!" << std::endl; return true; }());

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


