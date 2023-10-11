#pragma once
#include <compare>

struct Card
{
	Card(int number, int suit) : n(number), s(suit) {}

	inline auto operator<=>(const Card& otherCard) const
	{
		if (n > otherCard.n)
			return std::partial_ordering::greater;
		return std::partial_ordering::less;
	}

private:
	int n;
	int s;
};