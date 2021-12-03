#include <boost/asio.hpp>
#include <iostream>
#include "TicTacToeGame/tic_tac_toe.h"

class Client
{
    boost::asio::io_service service_;
    boost::asio::ip::tcp::endpoint ep_;
    boost::asio::ip::tcp::socket socket_;
public:
    Client(const std::string& address, boost::asio::ip::port_type port) : ep_(boost::asio::ip::address::from_string(address), port), socket_(service_)
    {
        socket_.connect(ep_);
    }

    void Send(const std::string& message)
    {
        socket_.send(boost::asio::buffer(message));
    }

    std::string Read()
    {
        char buf[5];
        socket_.receive(boost::asio::buffer(buf, 5));
        return std::string(buf, sizeof buf);
    }
};


int main()
{
    try
    {
		Client cl("127.0.0.1", 2001);
        ttt::tic_tac_toe game;
        bool yourTurn = false;


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

                cl.Send(std::to_string(input));
            }
            else
            {
                std::cout << "Waiting opponent to make turn..." << std::endl;
                input = std::stoi(cl.Read());
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
	catch (...)
	{
        std::cout << "Server is offline." << std::endl;
	}
    

    
}

