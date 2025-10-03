#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

class Dealer {
private:
	int cards_per_suit;
	std::vector<Card> deck;
	std::size_t pos;
	std::mt19937 random;

	void newDeck();

public:
	Dealer(int cards_per_suit);
	Card operator()();
};

std::vector<int> createStacks(int cards_per_suit, int n);
