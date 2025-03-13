#pragma once


#include "the-gallows.h"
#include <fstream>
#include <ctime>
#include <cstdlib> 

class Words {
private:
	std::string _filename; 
public:
    //Words() = default;
    Words(std::string filename) {
        _filename = filename;

        std::ofstream file(_filename);
        if (file.is_open()) {
            file << "lion" << std::endl;
            file << "dog" << std::endl;
            file << "cat" << std::endl;
            file.close();
            std::cout << "The file " << filename << " has been created" << std::endl;
        }
        else {
            std::cout << "Error: failed to create a file" << std::endl;
        }
        srand(static_cast<unsigned>(time(0)));
    }
    std::string getRandomWord();
    bool attempt(char& attempt);
    void wordOutput(std::string& word, std::vector<char>& symbols);
    bool tries(char a, std::string word, std::vector<char>& symbols);
    bool TheWordIsFound(std::string word, std::vector<char>& symbols);
};