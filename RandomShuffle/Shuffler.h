#pragma once

#include <vector>
#include "card.h"

class Shuffler
{
public:
	Shuffler(int cards) : cardAmount(cards)
	{
		PopulateDeckArr();
		Shuffle();
	}

	inline Card operator()()
	{
		nextIndex++;
		if (nextIndex == deck.size())
		{
			nextIndex = 0;
			Shuffle();
		}

		return deck[nextIndex];
	}

private:
	void PopulateDeckArr();
	void Shuffle();

private:
	const int suitAmount = 4;
	int cardAmount;

	std::vector<Card> deck;
	int nextIndex = -1;
};
