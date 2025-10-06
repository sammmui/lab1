#include <iostream>
#include <limits>
#include "cards.h"
#include "stack.h"

using namespace std;

int main() {
    try {
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

        Deck deck(suits, 13);
        Stats stats;
        process_stacks(deck, num_cards, stats);

        auto percents = stats.percentages();
        cout << "Percentages:\n";
        for (const auto& [l, p] : percents) {
            cout << "Length " << l << ": " << p << "%\n";
        }

        cout << "Most frequent length: " << stats.most_frequent() << "\n";
        cout << "Average length: " << stats.average() << "\n";
        cout << "Median length: " << stats.median() << "\n";

        // Experiment section
        cout << "\nExperiment: dependence on number of cards per suit (ranks), with suits=4, num_cards=1000000\n";
        cout << "ranks\taverage\tmedian\n";
        const int exp_suits = 4;
        const int exp_cards = 1000000;
        for (int ranks = 4; ranks <= 52; ranks += 2) {
            Deck exp_deck(exp_suits, ranks);
            Stats exp_stats;
            process_stacks(exp_deck, exp_cards, exp_stats);
            cout << ranks << "\t" << exp_stats.average() << "\t" << exp_stats.median() << "\n";
        }

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
