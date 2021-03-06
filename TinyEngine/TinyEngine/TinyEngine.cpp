// TinyEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// External libraries
#include <SDL.h>
#include <iostream>
#include <string>

// Project classes
#include "Window.h"
#include "Pixel.h"
#include "CmdSystem.cpp"

//Screen dimensions constants
const int WINDOW_WIDTH	= 800;
const int WINDOW_HEIGHT	= 600;

const std::string WINDOW_TITLE = "Main Window";

Window * mainWindow;
CmdSystemLocal * m_CmdSystem;

float DELTA_TIME;
float CURRENT_TIME, LAST_TIME;

// Engine Initialization
bool Init();

// Engine De-Initialization
void ShutDown();

//CmdSystem Initialization
void InitializeCmdSystem();


void InitializeCmdSystem()
{
	m_CmdSystem = new CmdSystemLocal();

	// Adding Commands
}


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
		
		mainWindow = new Window(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, (Uint32)0);

		std::cout << "Main Window creation: SUCCESS" << std::endl;

		mainWindow->InitializeSurface();

		std::cout << "Main Window Surface initialization: SUCCESS" << std::endl;

		// TODO: Substitute with main camera initialization
		/*mainWindow->InitializeRenderer();

		std::cout << "Main Window Renderer initialization: SUCCESS" << std::endl;*/

	}

	// Initialization succeded
	return true;
}

void ShutDown()
{
	delete mainWindow;

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

	Pixel * pixels = mainWindow->GetSurfacePixels();

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

			// updateCamera();

			// updateSceneElements();

			// renderScene();

			// swapBuffers();

		}



		CURRENT_TIME = SDL_GetPerformanceCounter();
		DELTA_TIME = ((CURRENT_TIME - LAST_TIME) * 1000 / SDL_GetPerformanceFrequency());
		LAST_TIME = CURRENT_TIME;
	}	

	std::cout << "Main Loop: END" << std::endl;

	ShutDown();

	std::cin.get();

    return 0;
}


