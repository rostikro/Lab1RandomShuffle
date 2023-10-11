#pragma once

#include "shuffler.h"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

class ShufflerWrapper
{
public:
	ShufflerWrapper(int cards, int n) : n(n), shuffler(std::make_unique<Shuffler>(cards)), frequency(cards) {}

	inline void Start()
	{
		Distribution();
		ShowResult();
	}

private:
	void ShowResult();
	void Distribution();

private:
	std::unique_ptr<Shuffler> shuffler = nullptr;
	int n;

	// STATISTICS
	std::vector<int> lengthOfDecks;
	std::vector<int> frequency;
};