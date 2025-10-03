#pragma once
#include "Card.h"
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

class Dealer {
private:
	int cards_per_suit;
	vector<Ñard> deck;
	size_t pos;
	mt19937 random;

	void newDeck();

public:
	Dealer(int cards_per_suit);
	Card operator()();
};

vector<int> createStacks(int cards_per_suit, int n);
