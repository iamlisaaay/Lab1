#include "Card.h"
#include <map>
#include <algorithm>

using namespace std;

std::strong_ordering Card::operator<=>(const Card& other) const {
    return rank <=> other.rank;
}

