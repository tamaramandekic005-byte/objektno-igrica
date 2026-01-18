#ifndef HANGMANBASE_H
#define HANGMANBASE_H

class HangmanBase {
public:
    virtual void reset() = 0;
    virtual void addMistake() = 0;
    virtual void draw() const = 0;
    virtual ~HangmanBase() {}
};

#endif

