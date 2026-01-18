#pragma once
#include <iostream>
#include <string>

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
Statistics<T>::Statistics(const T& name)
    : games(0), wins(0), losses(0), gameName(name) {}

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
    std::cout << "\nSTATISTIKA za igru: " << gameName << "\n";
    std::cout << "Igre: " << games << "\n";
    std::cout << "Pobjede: " << wins << "\n";
    std::cout << "Porazi: " << losses << "\n";
}
