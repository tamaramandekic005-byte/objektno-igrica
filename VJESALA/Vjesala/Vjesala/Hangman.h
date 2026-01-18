#ifndef HANGMAN_H
#define HANGMAN_H

#include "HangmanBase.h"

class Hangman : public HangmanBase {
private:
    int mistakes;

public:
    Hangman();
    void reset() override;
    void addMistake() override;
    void draw() const override;

};

#endif
