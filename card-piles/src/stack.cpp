#include "stack.h"
#include "cards.h"

#include <algorithm>
#include <stdexcept>

void Stats::add(int length) {
    if (length <= 0) {
        throw std::invalid_argument("Stack length must be positive");
    }
    lengths.push_back(length);
    counts[length]++;
}

std::map<int, double> Stats::percentages() const {
    if (lengths.empty()) {
        return {};
    }
    size_t n = lengths.size();
    int max_l = *std::max_element(lengths.begin(), lengths.end());
    std::map<int, double> p;
    for (int l = 1; l <= max_l; ++l) {
        size_t c = counts.contains(l) ? counts.at(l) : 0;
        p[l] = static_cast<double>(c) * 100.0 / n;
    }
    return p;
}

int Stats::most_frequent() const {
    if (counts.empty()) {
        throw std::runtime_error("No stack data available");
    }
    auto max_it = std::max_element(counts.begin(), counts.end(), [](const auto& a, const auto& b) {
         return a.second < b.second;
        });
    return max_it->first;
}

double Stats::average() const {
    if (lengths.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (int l : lengths) {
        sum += l;
    }
    return sum / lengths.size();
}

double Stats::median() const {
    if (lengths.empty()) {
        return 0.0;
    }
    std::vector<int> sorted = lengths;
    std::sort(sorted.begin(), sorted.end());
    size_t n = sorted.size();
    if (n % 2 == 1) {
        return sorted[n / 2];
    } else {
        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    }
}

void process_stacks(Deck& deck, int num_cards, Stats& stats) {
    if (num_cards < 0) {
        throw std::invalid_argument("Number of cards cannot be negative");
    }
    bool first = true;
    int current = 0;
    Card prev;
    for (int i = 0; i < num_cards; ++i) {
        Card c = deck();
        if (first || (c <=> prev) >= 0) {
            ++current;
            prev = c;
            first = false;
        } else {
            stats.add(current);
            current = 1;
            prev = c;
        }
    }
    if (current > 0) {
        stats.add(current);
    }
}