#include "stdafx.h"
#include <SDL.h>
#include <utility>
#include <string>

class Window
{
public:
	Window();
	Window(const std::string & winName, unsigned int x, unsigned int y, int width, int height, Uint32 flags);

	const std::pair< int, int > & GetSize() const;

	void InitializeSurface();

	~Window();

private:

	int Width;
	int Height;

	std::pair< int, int > Size;

	SDL_Window * SdlWindow;
	SDL_Surface * Surface;
};
