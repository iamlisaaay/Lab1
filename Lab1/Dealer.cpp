#include "Dealer.h"

using namespace std; 

Dealer::Dealer(int cards_per_suit) : cards_per_suit(cards_per_suit), pos(0) {
    random_device r;
    random = std::mt19937(r());
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
    deck.reserve(4 * static_cast<std::size_t>(cards_per_suit));
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= cards_per_suit; ++rank) {
            deck.push_back(Card{ rank, suit });
        }
    }
    
    std::shuffle(deck.begin(), deck.end(), random);
    pos = 0;
}

std::vector<int> createStacks(int cards_per_suit, int n) {
    Dealer dealer(cards_per_suit);
    if (n <= 0) return {};
    std::vector<int> stacks;

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
