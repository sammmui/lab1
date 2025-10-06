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