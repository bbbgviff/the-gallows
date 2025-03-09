#include "list-of-words.h"


void words::getValidGuess(char& guess)
{
    while (true) {
        std::cout << "Введите одну букву: ";
        std::cin >> guess;

        if (std::cin.fail() || std::cin.peek() != '\n' || !std::isalpha(guess)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите одну букву" << std::endl;
        }
        else {

            guess = std::tolower(guess);
            break;
        }
    }
}

void words::DisWord(std::string& word, std::vector<char>& thing)
{

    for (size_t i = 0; i < word.length(); i++) {
        std::cout << thing[i] << " ";
    }
    std::cout << std::endl;
}

bool words::guess(char G, std::string& word, std::vector<char>& thing)
{
    getValidGuess(G);
    bool found = false;
    for (size_t i = 0; i < word.length();i++) {
        if (word[i] == G) {
            thing[i] = G;
            found = true;
        }
    }
    return found;
}

bool words::isSolved(std::string& word, std::vector<char>& thing) {
    std::string guessed(thing.begin(), thing.end());

    if (word == guessed) {
        std::cout << "Поздравляю! Вы угадали слово: " << word << std::endl;
        return true;
    }
    return false;
}