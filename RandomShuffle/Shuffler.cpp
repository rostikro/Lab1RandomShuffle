#include "shuffler.h"

#include <random>

/// <summary>
/// Populates the deck one time when class instance is created
/// </summary>
void Shuffler::PopulateDeckArr()
{
	for (int i = 0; i < cardAmount; i++)
		for (int j = 0; j < suitAmount; j++)
			deck.push_back(Card(i, j));
}

/// <summary>
/// Shuffles the deck using Fisher–Yates shuffle Algorithm
/// </summary>
void Shuffler::Shuffle()
{
	std::random_device rd;
	std::mt19937 e(rd());

	for (int i = deck.size() - 1; i > 0; i--)
	{
		int index = std::uniform_int_distribution(0, i)(e);
		std::swap(deck[i], deck[index]);
	}
}