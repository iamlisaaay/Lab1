#pragma once
#include <iostream>
#include <string>
#include <compare> 
#include <vector>
using namespace std;
class Card {
public:
    int suit;  
    int rank;  

    Card(int s = 0, int r = 0) : suit(s), rank(r) {}
    std::strong_ordering operator<=>(const Card& other) const;


    friend ostream& operator<<(ostream& os, const Card& c) {

        os <<"suit: " << c.suit << "rank: " << c.rank;
        return os;
    }
};

void analyzeStacks(const vector<int>& stacks);
