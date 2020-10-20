

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controller.h"
#include <algorithm>

int main()
{
	try {
		std::srand((unsigned)std::time(NULL));
		Controller game; // run the game
		game.start();
	}
	catch (FileNotFoundException& fne)
	{
		std::cerr << fne.what();
		exit(-1);
	}

	catch (UnidentifiedColl& c) {
		std::cerr << c.what();
		exit(-1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return 0;
}