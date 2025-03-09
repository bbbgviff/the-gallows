#include "the-gallows.h"


const int hang::_MaxTry = 6;
void hang::NextStud(int tries)
{
	std::cout << _HANGMAN[tries] << std::endl;
}
