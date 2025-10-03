#include "Dealer.h"

using namespace std;

Dealer::Dealer(int cards_per_suit) : cards_per_suit(cards_per_suit), pos(0) {
    if (cards_per_suit < 1) throw invalid_argument("cards_per_suit must be >= 1");
    random_device r;
    random = mt19937(r());
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
    
    shuffle(deck.begin(), deck.end(), random);
    pos = 0;
}

vector<int> createStacks(int cards_per_suit, int n) {
    Dealer dealer(cards_per_suit);
    if (n <= 0) return {};
    vector<int> stacks;

    Card prev = dealer();
    int current_len = 1;
    for (int i = 1; i < n; ++i) {
        Card current = dealer();
        if (current > prev) {
            ++current_len;
        }
        else {
            stacks.push_back(current_len);
            current_len = 1;
        }
        prev = current;
    }
    stacks.push_back(current_len);
    return stacks;
}
