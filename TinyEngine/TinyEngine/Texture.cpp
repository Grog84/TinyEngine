#include "stdafx.h"
#include "Texture.h"
#include "SDL_Image.h"

Texture::Texture()
{
	SDLTexure = nullptr;
	Size = std::pair<int, int>(0, 0);
}


Texture::~Texture()
{
	Free();
}

void Texture::LoadFromFile(const std::string & path)
{
	Free();		// ets rid of previously loaded textures

	SDL_Texture * NewTexture = nullptr;

	SDL_Surface * LoadedSurface = IMG_Load(path.c_str());

	if (LoadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		// SDL_SetColorKey(LoadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
	}
}

void Texture::Free()
{
}

void Texture::RenderPoint(int x, int y) const
{
}

std::pair<int, int>& Texture::GetSize()
{
	// TODO: inserire l'istruzione return qui
	return Size;
}
