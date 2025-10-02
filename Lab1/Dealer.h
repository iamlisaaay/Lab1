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
	vector<card> deck;
	size_t pos = 0;
	mt19937& val;

	void newDeck();

public:
	Dealer(int cards_per_suit, mt19937& val);
	Card operator()();
};