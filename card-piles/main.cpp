#include <iostream>
#include <limits>
#include "cards.h"
#include "stack.h"

using namespace std;

int main() {
    int suits;
    cout << "Enter number of suits: ";
    cin >> suits;
    if (cin.fail() || suits <= 0) {
        cerr << "Error: Invalid number of suits (must be a positive integer)\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    int num_cards;
    cout << "Enter number of cards to deal: ";
    cin >> num_cards;
    if (cin.fail() || num_cards < 0) {
        cerr << "Error: Invalid number of cards (must be a non-negative integer)\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    