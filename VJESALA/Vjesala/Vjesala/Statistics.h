#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Statistics {
private:
    int games;
    int wins;
    int losses;
    T gameName;

public:
    Statistics(const T& name);

    void addWin();
    void addLoss();
    void display() const;
};

template <typename T>
Statistics<T>::Statistics(const T& name) : games(0), wins(0), losses(0), gameName(name) {}

template <typename T>
void Statistics<T>::addWin() {
    wins++;
    games++;
}

template <typename T>
void Statistics<T>::addLoss() {
    losses++;
    games++;
}

template <typename T>
void Statistics<T>::display() const {
    cout << "\nSTATISTIKA za igru: " << gameName << "\n";
    cout << "Igre: " << games << "\n";
    cout << "Pobjede: " << wins << "\n";
    cout << "Porazi: " << losses << "\n";
}

#endif
