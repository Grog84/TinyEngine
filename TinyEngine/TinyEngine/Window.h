#include "stdafx.h"
#include <SDL.h>
#include <utility>
#include <string>
#include "Pixel.h"

class Window
{
public:
	Window();
	Window(const std::string & winName, unsigned int x, unsigned int y, int width, int height, Uint32 flags);

	const std::pair< int, int > & GetSize() const;

	void InitializeSurface();


	// Window surface related methods

	void LockSurface();
	void UnlockSurface();

	Pixel * GetSurfacePixels();   // not const since it could lock the surface
	
	void ClearSurface();
	void UpdateSurface();

	~Window();

private:

	int Width;
	int Height;

	std::pair< int, int > Size;

	SDL_Window * SdlWindow;
	SDL_Surface * Surface;

	bool isSurfaceLocked;
};
