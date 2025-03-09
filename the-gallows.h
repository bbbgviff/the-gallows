#pragma once


#include <iostream>
#include <vector>
#include <string>

class hang
{
private:
    int _Stad = 0;
    static const int _MaxTry;
    const std::vector<std::string> _HANGMAN = {
        "\n\n\n\n\n\n=========" ,
        "\n\n\n\n\n  |\n=========" ,
        "\n\n\n\n  |\n  |\n=========" ,
        "\n\n\n  |\n  |\n  |\n=========" ,
        "\n\n  |\n  |\n  |\n  |\n=========" ,
        "\n  |\n  |\n  |\n  |\n  |\n=========" ,
        "  ____\n  |  |\n  |  O\n  | /|\\\n  |  |\n  | / \\\n  |\n========="
    };
public:
    void NextStud(int tries);
    static const int GetTry() {
        return _MaxTry;
    }
};