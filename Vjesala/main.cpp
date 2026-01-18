#include "UI.h"
#include "Hangman.h"
#include "Statistics.h"
#include "WordManager.h"

#include <iostream>
#include <set>
#include <string>
#include <cctype>

using namespace std;

int main() {
    UI ui;
    Hangman hangman;
    Statistics<std::string> stats("Hangman");

    WordManager wm;

    wm.loadWords("words.txt");

    char again = 'y';
    const int MAX_MISTAKES = 6;

    while (again == 'y' || again == 'Y') {
        hangman.reset();
        set<char> usedLetters;
        int mistakes = 0;
        bool hintUsed = false;  

        ui.displayWelcome();
        ui.displayRules();

        auto cats = wm.getCategories();
        cout << "\nDostupne kategorije:\n";
        int idx = 1;
        for (auto& c : cats)
            cout << idx++ << ". " << c.first << endl;

        int choice;
        cout << "\nOdaberi broj kategorije: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        wm.chooseCategory(choice);


        int difficulty;
        cout << "Odaberite tezinu (1=Easy, 2=Medium, 3=Hard): ";
        cin >> difficulty;
        if (difficulty < 1 || difficulty > 3) difficulty = 1; 
        cin.ignore(10000, '\n');
        wm.pickWord(difficulty);


        while (mistakes < MAX_MISTAKES && !wm.guessed()) {
            ui.displayGame(wm.getHidden(), usedLetters, hangman);

            cout << "Unesite slovo (ili ? za hint): ";
            string input = ui.getInput();
            if (input.empty())
                continue;

            char letter = tolower(input[0]);

            if (letter == '?') {
                if (!hintUsed) {
                    for (size_t i = 0; i < wm.getWord().size(); i++) {
                        if (wm.getHidden()[i] == '_') {
                            letter = wm.getWord()[i];
                            wm.reveal(letter);
                            usedLetters.insert(letter);
                            hintUsed = true;
                            cout << "Hint: Otkriveno slovo '" << letter << "'!\n";
                            break;
                        }
                    }
                }
                else {
                    cout << "Hint je vec iskoristen!\n";
                }
                continue; 
            }

            if (!isalpha(letter)) {
                cout << "Unesite slovo abecede!\n";
                continue;
            }

            if (usedLetters.count(letter)) {
                cout << "Slovo je vec iskoristeno!\n";
                continue;
            }

            usedLetters.insert(letter);

            if (wm.hasLetter(letter)) {
                wm.reveal(letter);
            }
            else {
                mistakes++;
                hangman.addMistake();
            }
        }

        bool win = wm.guessed();
        ui.displayEnd(win, wm.getWord());

        if (win)
            stats.addWin();
        else
            stats.addLoss();

        stats.display();

        cout << "\nZelite igrati ponovno? (y/n): ";
        cin >> again;
        cin.ignore(10000, '\n');
        cout << endl;
    }

    cout << "Hvala na igri!\n";
    return 0;
}
