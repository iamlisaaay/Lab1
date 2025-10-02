#include "Dealer.h"

using namespace std;

Dealer::Dealer(int cards_per_suit, mt19937& val) : cards_per_suit(cards_per_suit), val(val) {
    if (cards_per_suit < 1) throw std::invalid_argument("cards_per_suit must be >= 1");
    newDeck();
}

Card Dealer::operator()() {
    if (pos >= deck.size()) {
        newDeck();
    }
    return deck[pos++];
}

void Dealer::newDeck() {
    deck.clear();
    deck.reserve(4 * static_cast<size_t>(cards_per_suit));
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= cards_per_suit; ++rank) {
            deck.push_back(Card{ rank, suit });
        }
    }
    shuffle(deck.begin(), deck.end(), val);
    pos = 0;
}
