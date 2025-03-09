#pragma once


#include "the-gallows.h"
#include <ctime>
#include <random>
#include <cctype>


class words
{
private:
    std::vector<std::string> _WORDS;
    std::string _word;
    void getValidGuess(char& guess);
public:

    bool guess(char G, std::string& word, std::vector<char>& thing);

    words() {
        _WORDS = { "strawberry", "apple", "banana", "grape", "orange",
           "kiwi", "blueberry", "pear", "pineapple", "mango",
           "peach", "lemon", "watermelon", "cherry", "plum",
           "apricot", "papaya", "pomegranate", "fig", "coconut",
           "avocado", "applesauce", "tangerine", "nectarine", "elderberry",
           "blackberry", "dragonfruit", "cantaloupe", "jackfruit", "lime" };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, _WORDS.size() - 1);
        _word = _WORDS[distrib(gen)];
    }


    void DisWord(std::string& word, std::vector<char>& thing);
    bool isSolved(std::string& word, std::vector<char>& thing);
    std::string GetWord() {
        return _word;
    }
};