#ifndef WORDMANAGER_H
#define WORDMANAGER_H
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class WordManager {
private:
    map<string, vector<string>> categories;
    string selectedCategory;
    string secretWord;
    string hiddenWord;

public:
    void loadWords(const string& filename);
    void chooseCategory(int choice);
    void pickWord(int difficulty);

    bool hasLetter(char letter) const;
    void reveal(char letter);
    bool guessed() const;

    const string& getHidden() const;
    const string& getWord() const;
    const map<string, vector<string>>& getCategories() const {
        return categories;
    }
};

#endif