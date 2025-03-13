#pragma once


#include <iostream>
#include <string>
#include <vector>

class TheGallows {
private:
	const std::vector <std::string> _hang{
		" -----\n |   |\n     |\n     |\n     |\n     |\n======",
		" -----\n |   |\n o   |\n     |\n     |\n     |\n======",
		" -----\n |   |\n o   |\n |   |\n     |\n     |\n======",
		" -----\n |   |\n o   |\n/|   |\n     |\n     |\n======",
		" -----\n |   |\n o   |\n/|\  |\n     |\n     |\n======",
		" -----\n |   |\n o   |\n/|\\  |\n/    |\n     |\n======",
		" -----\n |   |\n o   |\n/|\\  |\n/ \\  |\n     |\n======"
	};
	int _attempt; 
	const int _maxAttempt = 6;

public:
	void nextAttempt(int attempt);
	int GetMaxAttempt() const {
		return _maxAttempt;
	}
};