#ifndef UI_H
#define UI_H

#include <string>
#include <set>
#include "Hangman.h"

using namespace std;

class UI {
public:
    void displayWelcome() const;
    void displayRules() const;

    void displayGame(const string& word, const set<char>& used, const Hangman& h) const;

    string getInput() const;
    void displayEnd(bool win, const string& word) const;
};

#endif 
