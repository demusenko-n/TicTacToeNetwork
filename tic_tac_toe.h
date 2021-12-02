#pragma once
#include <array>
#include <optional>
#include <string>

#include "side.h"

namespace ttt
{
	using namespace ttt_side;
	class tic_tac_toe
	{

		std::array<std::optional<side>, 9> board_;
		side current_turn_;
		std::optional<side> winner_;

	public:
		tic_tac_toe();

		[[nodiscard]]
		bool is_possible_turn(int cell_index)const;

		[[nodiscard]]
		std::optional<side> get_winner()const;

		[[nodiscard]]
		bool is_game_over()const;

		[[nodiscard]]
		std::string str()const;

		void make_turn(int cell_index);

	private:
		[[nodiscard]]
		bool is_winning_move(int index)const;
	};
}

