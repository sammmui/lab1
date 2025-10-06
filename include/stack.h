#pragma once
#include <vector>
#include <map>
#include <string> 
#include <iostream>

class Stats {
    private:
    std:vector<int> pile_lenghts;

    public:
    void addPile(int lenght);
    double mean() const;
    double median() const;
    int mode() const;
    std:map<int, double> percentages() const;
    void printReport() const;
};
