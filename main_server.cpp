//#include <iostream>
//#include <boost/asio.hpp>
//#include "TicTacToeGame/tic_tac_toe.h"
//
//class Server
//{
//    boost::asio::io_service service_;
//    boost::asio::ip::tcp::endpoint ep_;
//    boost::asio::ip::tcp::socket socket_;
//    boost::asio::ip::tcp::acceptor acc_;
//public:
//    Server(boost::asio::ip::port_type port) : ep_(boost::asio::ip::tcp::v4(), port), socket_(service_), acc_(service_, ep_)
//    {
//        std::cout << "Waiting for client..." << std::endl;
//        acc_.accept(socket_);
//    }
//
//    void Send(const std::string& message)
//    {
//         socket_.send(boost::asio::buffer(message));
//    }
//
//    std::string Read()
//    {
//        char buf[5];
//        socket_.receive(boost::asio::buffer(buf, 5));
//        return std::string(buf, sizeof buf);
//    }
//};
//
//
//int main()
//{
//	try
//	{
//        Server srv(2001);
//
//        ttt::tic_tac_toe game;
//        bool yourTurn = true;
//
//
//        while (!game.is_game_over())
//        {
//            int input;
//            if (yourTurn)
//            {
//                do
//                {
//                    std::cout << "input (0-8): ";
//                    std::cin >> input;
//                } while (!game.is_possible_turn(input) && []() {std::cout << "Invalid turn!" << std::endl; return true; }());
//
//                srv.Send(std::to_string(input));
//            }
//            else
//            {
//                std::cout << "Waiting opponent to make turn..." << std::endl;
//                input = std::stoi(srv.Read());
//            }
//
//            game.make_turn(input);
//            std::cout << game.str();
//
//            yourTurn = !yourTurn;
//        }
//
//        auto winner = game.get_winner();
//        if (winner.has_value())
//        {
//            std::cout << "Winner is " << ttt_side::chr(winner.value()) << "!" << std::endl;
//        }
//        else
//        {
//            std::cout << "Draw!" << std::endl;
//        }
//        return 0;
//	}
//	catch (...)
//	{
//        std::cout << "Client is offline" << std::endl;
//	}
//    
//}
