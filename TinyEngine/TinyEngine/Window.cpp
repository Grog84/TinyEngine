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
	
}

const std::pair<int, int>& Window::GetSize() const
{
	return Size;
}


Window::~Window()
{
	std::cout << "Destroyer called" << std::endl;
	SDL_DestroyWindow(SdlWindow);
}
