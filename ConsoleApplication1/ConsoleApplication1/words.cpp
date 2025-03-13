#include "words.h"

//рандом слово из файла 
std::string Words::getRandomWord() {
	std::vector <std::string> word;
	std::ifstream file(_filename);

	if (file.is_open()) {
		std::string buf;
		while (std::getline(file, buf)) {
			word.push_back(buf);
		}
		file.close();
		if (word.empty()) {
			std::cout << "Error: the file is empty" << std::endl;
		}

		int randomIndex = rand() % word.size();
		return word[randomIndex];
	}
	else {
		std::cout << "Error: the file was not opened" << std::endl;
		return 0;
	}
}

//проверка на правитльность ввода символа 
bool Words::attempt(char& attempta) {
		if (!std::isalpha(attempta)) {
			std::cout << "Error: re-enter the character" << std::endl;
			std::cin.ignore(10000, '\n');
			return 0;
		}
		else {
			attempta = std::tolower(attempta);
			return 1;
		}
}
//вывод текущего состояния слова
void Words::wordOutput(std::string& word, std::vector<char>& symbols) {
	for (int i = 0; i < word.length(); ++i) {
		std::cout << symbols[i] << ' ';
	}
	std::cout << std::endl;
}

//поиск символа в слове 
bool Words::tries(char a, std::string word, std::vector<char>& symbols) {
		bool found = 0;
		attempt(a);
		for (int i = 0; i < word.length(); ++i) {
			if (a == word[i]) {
				symbols[i] = a;
				found = 1;
			}
		}
		return found;
}

//проверка найдено ли слово 
bool Words::TheWordIsFound(std::string word, std::vector<char>& symbols) {
	std::string attempt;
	for (int i = 0; i < symbols.size(); ++i) {
		if (symbols[i] != '_') {
			attempt += symbols[i];
		}
	}
	if (word == attempt) {
		std::cout << "You guessed the right word!" << std::endl;
		return 1;
	}
	return 0;
}