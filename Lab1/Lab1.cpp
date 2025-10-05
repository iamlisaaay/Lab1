//Автори: Данченко Анастасія, Гопко Анастасія група К-27
//Варіант 4
//Компілятор: Microsoft (R) C/C++ Optimizing Compiler

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Dealer.h"
#include "Card.h"
#include <stdexcept>
using namespace std;

std::map<int, int> getFrequencies(const std::vector<int>& stacks) {
    std::map<int, int> freq;
    for (int len : stacks) {
        freq[len]++;
    }
    return freq;
}

void printPercentages(const std::vector<int>& stacks) {
    int n = stacks.size();
    std::map<int, int> freq = getFrequencies(stacks);

    cout << "Percentage of stacks by length:\n";
    for (auto [len, count] : freq) {
        double percent = 100.0 * count / n;
        cout << "Length " << len << " appears in " << percent << "%\n";
    }
}

void printModes(const std::vector<int>& stacks) {
    std::map<int, int> freq = getFrequencies(stacks);

    int bestCount = 0;
    for (auto& [len, count] : freq) {
        if (count > bestCount) bestCount = count;
    }

    std::vector<int> modes;
    for (auto& [len, count] : freq) {
        if (count == bestCount) modes.push_back(len);
    }

    cout << "Most frequent length(s): ";
    for (std::size_t i = 0; i < modes.size(); i++) {
        cout << modes[i];
        if (i + 1 < modes.size()) cout << ", ";
    }
    cout << "\n";
}

void printAverage(const vector<int>& stacks) {
    double sum = 0;
    for (int len : stacks) sum += len;
    cout << "Average length: " << sum / stacks.size() << "\n";
}

void printMedian(const vector<int>& stacks) {
    vector<int> sorted = stacks;
    sort(sorted.begin(), sorted.end());
    int n = sorted.size();
    double median;
    if (n % 2 == 1) median = sorted[n / 2];
    else median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    cout << "Median length: " << median << "\n";
}


int main() {
    try {
        int cards_per_suit, n;
        cout << "Enter the number of cards per suit: ";
        cin >> cards_per_suit;
        if (cards_per_suit < 1) throw std::invalid_argument("There must be at least 1 card in the deck.");
        cout << "\nEnter the number of cards to deal: ";
        cin >> n;
        if (n < 1) throw std::invalid_argument("It is impossible to form stacks from such a number of cards.");

        auto stacks = createStacks(cards_per_suit, n);

        printPercentages(stacks);
        printModes(stacks);
        printAverage(stacks);
        printMedian(stacks);

        return 0;
    }

    catch (const std::exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}
