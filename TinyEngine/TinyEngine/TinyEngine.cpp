// TinyEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char ** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL Initialization FAILED" << std::endl;
	}
	else
	{
		std::cout << "SDL Initialized correctly" << std::endl;

	}

	std::cin.get();

    return 0;
}

