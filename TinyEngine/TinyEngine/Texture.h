#pragma once
#include <string>
#include <utility>
#include "SDL.h"

class Texture
{
public:

	Texture();
	~Texture();

	void LoadFromFile(const std::string &);

	void Free();

	void RenderPoint(int x, int y) const;

	std::pair<int, int> & GetSize();

private:

	SDL_Texture * SDLTexure;
	std::pair<int, int> Size;

};

