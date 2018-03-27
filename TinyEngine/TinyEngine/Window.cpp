#include "stdafx.h"

#include "Window.h"
#include <cassert>
#include <iostream>

Window::Window(){}


Window::Window(const std::string & winName, unsigned int x, unsigned int y, int width, int height, Uint32 flags)
{
	// Creates the SDL window and assignes the pointer
	SdlWindow = SDL_CreateWindow(winName.c_str(), x, y, width, height, flags);

	// In case of failed creation SdlWindow is NULL
	assert(SdlWindow);

	Width	= width;
	Height	= height;

	Size = std::pair< int, int >(Width, Height);

	Surface = SDL_GetWindowSurface(SdlWindow);
	
	isSurfaceLocked = false;
}

const std::pair<int, int>& Window::GetSize() const
{
	return Size;
}

void Window::InitializeSurface()
{
	SDL_FillRect(Surface, NULL, SDL_MapRGB(Surface->format, 0, 0, 0));
}

void Window::LockSurface()
{
	SDL_LockSurface(Surface);
	isSurfaceLocked = true;
}

void Window::UnlockSurface()
{
	SDL_UnlockSurface(Surface);
	isSurfaceLocked = false;
}

Pixel * Window::GetSurfacePixels()
{
	if (!isSurfaceLocked)
	{
		std::cout << "Surface not Locked!" << std::endl;
		std::cout << "I'm Locking it for you!" << std::endl;
		LockSurface();
	}
	return static_cast<Pixel *>(Surface->pixels);
}

void Window::ClearSurface()
{
	SDL_FreeSurface(Surface);
}

void Window::UpdateSurface()
{
	SDL_UpdateWindowSurface(SdlWindow);
}


Window::~Window()
{
	std::cout << "Destroyer called" << std::endl;
	SDL_DestroyWindow(SdlWindow);
}
