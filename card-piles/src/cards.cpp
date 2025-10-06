#include <cards.h>
#include <algorithm>
#include <random>

std::string Card::toString() const {
    static const std::string suitNames[] = {"♠", "♥", "♦", "♣"};
    static const std::string valueNames[] =
    {
        "", "A", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K"
    };
