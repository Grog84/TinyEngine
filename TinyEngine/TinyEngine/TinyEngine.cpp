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

Window * mainWindow;

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
		
		mainWindow = new Window(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, (Uint32)0);

		std::cout << "Main Window creation: SUCCESS" << std::endl;

		mainWindow->InitializeSurface();

		std::cout << "Main Window Surface initialization: SUCCESS" << std::endl;

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

	ShutDown();

	std::cin.get();

    return 0;
}

SDL_LockSurface(drawTarget);

struct Pixel
{
	uint8_t R = 0;
	uint8_t G = 0;
	uint8_t B = 0;
	uint8_t A = 0;
};

//Pixel * pixels = static_cast<Pixel *>(drawTarget->pixels);
//
//int x_center = size.first / 2;
//int y_center = size.second / 2;
//
//float DistMax = sqrt(x_center*x_center + y_center * y_center);
//
//for (int i = 0; i < size.first * size.second; i++)
//{
//	Pixel * p = pixels + i;
//
//	int x = i % size.first;
//	int y = i / size.first;
//
//	int xDiff = x - x_center;
//	int yDiff = y - y_center;
//
//	float dist = sqrt(xDiff*xDiff + yDiff * yDiff);
//
//	p->R = dist / DistMax * 255;
//	p->G = 255 * (1 - dist / DistMax) * abs(sin(sinParam2));
//	p->B = dist / DistMax * 255 * abs(sin(sinParam));
//
//	p->A = 255;
//	// p->A = dist / DistMax * 255 * abs(sin(sinParam));
//}

//SDL_UnlockSurface(drawTarget);
//
//
//SDL_BlitSurface(drawTarget, nullptr, screen, nullptr);
//
//window.UpdateWindowSurface();
//
//currentTime = SDL_GetPerformanceCounter();
//deltaTime = (double)((currentTime - lastTime) * 1000 / SDL_GetPerformanceFrequency());
//
//// increment = currentTime - lastTime;
//
//lastTime = currentTime;
//
///*sinParam += increment;
//sinParam2 += increment * 2;*/
//
//sinParam += deltaTime * 0.001;
//sinParam2 += deltaTime * 2 * 0.001;
//
////std::cout << deltaTime * 0.01 << std::endl;
////std::cout << deltaTime * 2 * 0.01 << std::endl;
//
//SDL_FreeSurface(drawTarget);
