#pragma once

#include <map>
#include <vector>

class Deck;
class Card;

class Stats {
private:
    std::vector<int> lengths;
    std::map<int, size_t> counts;

public:
    void add(int length);
    std::map<int, double> percentages() const;
    int most_frequent() const;
    double average() const;
    double median() const;
};

void process_stacks(Deck& deck, int num_cards, Stats& stats);
