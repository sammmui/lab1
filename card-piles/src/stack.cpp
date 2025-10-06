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
  
}