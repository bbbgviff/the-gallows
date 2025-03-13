#include "the-gallows.h"
#include "words.h"

int main() {
	int tries = 0;
	Words words{"abc.txt"};
	TheGallows theGallows;
	std::string receivedWord = words.getRandomWord();

	std::vector <char> attempt;
	for (int i = 0; i < receivedWord.length(); ++i) {
		attempt.push_back('_');
	}
	std::cout << "Welcome to the Gallows game!\nRule: Enter the characters to guess the word. You have 6 attempts!" << std::endl;
	while (tries < theGallows.GetMaxAttempt()) {
		theGallows.nextAttempt(tries);
		words.wordOutput(receivedWord, attempt);

		bool result = false;
		char bufer;
		while (!result) {
			char random;
			while (true) {
				std::cout << "Enter a character: " << std::endl;
				std::cin >> random;

				if (std::cin.peek() != '\n') {
					std::cout << "Error: enter one character" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}
			result = words.attempt(random);
			if (result == 1) {
				bufer = random;
				break;
			}
		}
			bool right = words.tries(bufer, receivedWord, attempt);
			if (!right) {
				++tries;
				std::cout << "Wrong! There are still attempts left: " << theGallows.GetMaxAttempt() - tries << std::endl;
			}
			else {
				std::cout << "Right!There are still attempts left: " << theGallows.GetMaxAttempt() - tries << std::endl;
				if (words.TheWordIsFound(receivedWord, attempt)) {
					theGallows.nextAttempt(tries);
					break;
				}
			}
			if (tries == theGallows.GetMaxAttempt()) {
				theGallows.nextAttempt(tries);
				std::cout << "You've lost! The hidden word: " << receivedWord << std::endl;
			}
	}
}