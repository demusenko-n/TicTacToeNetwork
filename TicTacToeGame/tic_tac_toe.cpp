#include "tic_tac_toe.h"
#include <algorithm>
#include <iostream>

ttt::tic_tac_toe::tic_tac_toe() : current_turn_(side::x)
{}

bool ttt::tic_tac_toe::is_possible_turn(int cell_index) const
{

	return cell_index >= 0 && cell_index <= 8 && !board_[cell_index].has_value();
}

std::optional<ttt_side::side> ttt::tic_tac_toe::get_winner() const
{
	return winner_;
}

bool ttt::tic_tac_toe::is_game_over() const
{
	return winner_.has_value() || std::ranges::all_of(board_.cbegin(), board_.cend(), [](std::optional<side> v) {return v.has_value(); });
}

std::string ttt::tic_tac_toe::str() const
{
	std::string result;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			const std::optional<side>& cell = board_[i * 3 + j];

			char symbol;
			if (!cell.has_value())
			{
				symbol = ' ';
			}
			else 
			{
				symbol = chr(cell.value());
			}
			result += symbol;
		}
		result += '\n';
	}

	return result;
}

void ttt::tic_tac_toe::make_turn(int cell_index)
{
	if (!is_possible_turn(cell_index))
		throw std::exception("illegal move");
	if (winner_.has_value())
		throw std::exception("game over");

	board_[cell_index] = current_turn_;
	if (is_winning_move(cell_index))
	{
		winner_ = current_turn_;
	}

	current_turn_ = get_opposite_side(current_turn_);
}

bool ttt::tic_tac_toe::is_winning_move(int index) const
{
	int row = index / 3;
	int column = index % 3;

	bool is_on_main = row == column;
	bool is_on_secondary = row + column == 2;

	return board_[column] == board_[column + 3] && board_[column] == board_[column + 6] //victory by column
		|| board_[row*3] == board_[row*3 + 1] && board_[row*3 + 1] == board_[row*3 + 2] 		//by row
		|| is_on_main && board_[0] == board_[4] && board_[4] == board_[8] 				//by main diag
		|| is_on_secondary && board_[2] == board_[4] && board_[4] == board_[6];			//by secondary diag
}
