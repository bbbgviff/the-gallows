#include <iostream>
#include "list-of-words.h"
#include "the-gallows.h"


hang Hang = hang();
words Word;

int main() {
    setlocale(0, "ru");
    std::string word = Word.GetWord();

    std::vector<char> gueses(word.length(), '_');
    int tries = 0;
    std::cout << "Добро пожаловать в игру 'Виселица'!" << std::endl;
    while (tries < Hang.GetTry()) {
        Hang.NextStud(tries);
        Word.DisWord(word, gueses);

        char guess = 'a';

        bool isFound = Word.guess(guess, word, gueses);
        if (!isFound) {
            tries++;
            system("cls");
            std::cout << "Неправильно, осталось " << (Hang.GetTry() - tries) << " попыток." << std::endl;
        }
        else {
            system("cls");
            std::cout << "Правильно, осталось " << (Hang.GetTry() - tries) << " попыток." << std::endl;
            if (Word.isSolved(word, gueses)) {
                Hang.NextStud(tries);
                break;
            }
        }
    }
    if (tries == Hang.GetTry()) {
        Hang.NextStud(tries);
        std::cout << "Вы проиграли! Загаданное слово: " << word << std::endl;
    }
}