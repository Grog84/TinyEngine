#pragma once
#include <string>
#include <utility>
#include "SDL.h"

class Texture
{
public:

	Texture();
	Texture(const std::pair<int, int> & Size, SDL_Renderer & Renderer);
	~Texture();

	void LoadFromFile(const std::string &);

	void Free();

	void RenderPoint(int x, int y) const;

	std::pair<int, int> & GetSize();
	void SetSize(const std::pair<int, int> & Size);
	void SetSizeFromImage(const std::pair<int, int> & Size);

	SDL_Renderer & GetRenderer();
	void SetRenderer(SDL_Renderer & Renderer);

private:

	SDL_Texture * SDLTexture;
	SDL_Renderer * Renderer;

	std::pair<int, int> Size;

	Uint32 Format;

};

