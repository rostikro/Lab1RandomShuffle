#include "ShufflerWrapper.h"

void ShufflerWrapper::ShowResult()
{
	int major = -1, votes = 0;

	float average = 0;
	float median = 0;

	float sum = 0;
	for (int i = 0; i < lengthOfDecks.size(); i++)
	{
		// Majority vote
		if (votes == 0)
			major = lengthOfDecks[i];
		votes += lengthOfDecks[i] == major ? 1 : -1;

		sum += lengthOfDecks[i];
	}

	average = sum / lengthOfDecks.size();

	std::nth_element(lengthOfDecks.begin(), lengthOfDecks.begin() + lengthOfDecks.size() / 2, lengthOfDecks.end());
	if (lengthOfDecks.size() % 2 == 0)
	{
		std::nth_element(lengthOfDecks.begin(), lengthOfDecks.begin() + (lengthOfDecks.size() - 1) / 2, lengthOfDecks.end());
		median = (float)(lengthOfDecks[(lengthOfDecks.size() - 1) / 2] + lengthOfDecks[lengthOfDecks.size() / 2]) / 2.0f;
	}
	else
		median = (float)lengthOfDecks[lengthOfDecks.size() / 2];

	// STATISTICS OUTPUT
	std::cout << "Frequency:\n";
	for (int i = 0; i < frequency.size(); i++)
	{
		std::cout << i + 1 << ": " << (float)frequency[i] / lengthOfDecks.size() * 100 << "%" << std::endl;
	}

	std::cout << "Most frequent length: " << major;
	std::cout << "\nAverage length: " << average;
	std::cout << "\nMedian of lengths: " << median;
}

void ShufflerWrapper::Distribution()
{
	Card prev = shuffler->operator()();
	n--;

	int length = 1;

	while (n >= 0)
	{
		n--;
		Card curr = shuffler->operator()();

		if (curr <= prev)
		{
			lengthOfDecks.push_back(length);
			frequency[length - 1]++;
			length = 0;
		}

		prev = curr;
		length++;
	}
	std::cout << std::endl;
}