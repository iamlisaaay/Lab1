#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


map<int, int> getFrequencies(const vector<int>& stacks) {
    map<int, int> freq;
    for (int len : stacks) {
        freq[len]++;
    }
    return freq;
}

void printPercentages(const vector<int>& stacks) {
    int n = stacks.size();
    map<int, int> freq = getFrequencies(stacks);

    cout << "Percentage of stacks by length:\n";
    for (auto [len, count] : freq) {
        double percent = 100.0 * count / n;
        cout << "Length " << len << " appears in " << percent << "%\n";
    }
}

void printModes(const vector<int>& stacks) {
    map<int, int> freq = getFrequencies(stacks);

    int bestCount = 0;
    for (auto& [len, count] : freq) {
        if (count > bestCount) bestCount = count;
    }

    vector<int> modes;
    for (auto& [len, count] : freq) {
        if (count == bestCount) modes.push_back(len);
    }

    cout << "Most frequent length(s): ";
    for (size_t i = 0; i < modes.size(); i++) {
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
    vector<int> stacks = { 2, 3, 5, 5, 3, 2 };

    if (stacks.empty()) {
        cout << "No data.\n";
        return 0;
    }

    printPercentages(stacks);
    printModes(stacks);
    printAverage(stacks);
    printMedian(stacks);

    return 0;
}