// RandomShuffle.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "ShufflerWrapper.h"

int main()
{
	int a, n;

	std::cout << "Enter the number of cards of each suit: ";
	std::cin >> a;
	std::cout << "Enter the number of cards to be dealt: ";
	std::cin >> n;

	try
	{
		if (a < 1)
			throw std::runtime_error("\tThe number of cards of each suit must be greater than 0.");
		if (n < 1)
			throw std::runtime_error("\tThe number of cards to be dealt must be greater than 0.");

		ShufflerWrapper shuffler(a, n);
		shuffler.Start();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return 1;
	}

	return 0;
}
