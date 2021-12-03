#pragma once

namespace ttt_side {
	enum class side
	{
		x = 0,
		o = 1
	};

	inline side get_opposite_side(side s)
	{
		return static_cast<side>(abs(static_cast<int>(s) - 1));
	}
	inline char chr(side s)
	{
		switch (s)
		{
			case side::x:
				return 'X';
			case side::o:
				return 'O';
		}
	}
}