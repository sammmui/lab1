#pragma once
#include <vector>
#include <random>
#include <stdexcept>
#include <string>

class Card {
    private:
         int value;
         int suit;
    public:
      Card(int v, int s) : value(v), suit(s) {}
     std::string toString() const;

    auto operator<=>(const Card&) const = default;
};

class Deck {
private:
    std::vector<Card> cards;
    size_t currentIndex;
    int numSuits;
    std::mt19937 rng;

    void initializeDeck();
    void shuffleDeck();

public:
    explicit Deck(int numSuits);

    // Отримати наступну карту
    Card operator()();

    // Перевірити, чи колода потребує перетасування
    bool needsReshuffle() const { return currentIndex >= cards.size(); }
};