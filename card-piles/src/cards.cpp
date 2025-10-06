#include <cards.h>
#include <algorithm>
#include <random>
#include <sstream>

std::string Card::toString() const {
    static const std::string suitNames[] = {"♠", "♥", "♦", "♣"};
    static const std::string valueNames[] =
    {
        "", "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };
 std::ostringstream out;
    out << valueNames[value] << suitNames[suit];
    return out.str();
}
Deck::Deck(int numSuits)
    : currentIndex(0),
      numSuits(numSuits),
      numValues(13),
      rng(std::random_device{}())
{
    initializeDeck();
    shuffleDeck();
}
void Deck::initializeDeck() {
    cards.clear();
    for (int s = 0; s < numSuits; ++s) {
        for (int v = 1; v <= numValues; ++v) {
            cards.emplace_back(v, s);
        }
    }
}
void Deck::shuffleDeck() {
    std::shuffle(cards.begin(), cards.end(), rng);
    currentIndex = 0;
}

Card Deck::operator()() {
    if (needsReshuffle()) {
        shuffleDeck();
    }
    return cards[currentIndex++];
}
bool Deck::needsReshuffle() const {
    return currentIndex >= cards.size();
};

