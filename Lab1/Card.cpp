#include "Card.h"
#include <map>
#include <algorithm>

using namespace std;

strong_ordering Card::operator<=>(const Card& other) const {
    return rank <=> other.rank;
}

void analyzeStacks(const vector<int>& stacks) {

    if (stacks.empty()) {
        cout << "No data.\n";
        return;
    }
    int n = stacks.size();

    map<int, int> freq;
    for (int len : stacks) {
        freq[len]++;
    }

    cout << "Percentage of stacks by length:\n";
    for (auto [len, count] : freq) {
        double percent = 100.0 * count / n;
        cout << "Length " << len << " appears in " << percent << "%\n";
    }

    int bestCount = 0;

   
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if (it->second > bestCount) {
            bestCount = it->second;
        }
    }
    vector<int> modes;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if (it->second == bestCount) {
            modes.push_back(it->first);
        }
    }
    cout << "Most frequent length(s): ";
    for (size_t i = 0; i < modes.size(); i++) {
        cout << modes[i];
        if (i + 1 < modes.size()) cout << ", ";
    }
    cout << "\n";



    double sum = 0;
    for (int len : stacks) {
        sum += len;
    }
    double avg = sum / n;
    cout << "Average length: " << avg << "\n";

    vector<int> sorted = stacks;
    sort(sorted.begin(), sorted.end());
    double median;
    if (n % 2 == 1) {
        median = sorted[n / 2];
    }
    else {
        median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    }
    cout << "Median length: " << median << "\n";
}
