// TinyEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// External libraries
#include <SDL.h>
#include <iostream>
#include <string>

// Project classes
#include "Window.h"

//Screen dimensions constants
const int WINDOW_WIDTH	= 800;
const int WINDOW_HEIGHT	= 600;

const std::string WINDOW_TITLE = "Main Window";

Window mainWindow;

// Engine Initialization
bool Init();

// Engine De-Initialization
void ShutDown();


bool Init()
{
	// Initialization of the SDL events and video systems
	if (SDL_Init(SDL_INIT_EVENTS || SDL_INIT_VIDEO) < 0)			
	{
		std::cout << "SDL Initialization: FAILED" << std::endl;
		return false;
	}
	else
	{ 
		std::cout << "SDL Initialization: SUCCESS" << std::endl;
		
		mainWindow = Window(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, (Uint32)0);

		std::cout << "Main Window creation: SUCCESS" << std::endl;
	}

	// Initialization succeded
	return true;
}

void ShutDown()
{

	SDL_Quit();
}

int main(int argc, char ** argv)
{
	
	if (!Init())
	{
		std::cout << "Failed to initialize!" << std::endl;
		return 1;
	}

	// Main Loop Flag
	bool Quit = false;

	// Event handler
	SDL_Event Event;

	std::cout << "Main Loop: START" << std::endl;

	// Main loop
	while (!Quit)
	{
		while (SDL_PollEvent(&Event) != 0)
		{
			if (Event.type == SDL_QUIT)
			{
				// Breaks the main loop
				Quit = true;
			}
			else if (Event.type == SDL_KEYDOWN)
			{
				std::cout << "Key pressed is: " << Event.key.keysym.sym << std::endl;

			}
		}

	}

	std::cout << "Main Loop: END" << std::endl;

	std::cin.get();

	ShutDown();

    return 0;
}

