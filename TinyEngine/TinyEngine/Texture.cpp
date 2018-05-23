#include "stdafx.h"
#include "Texture.h"
#include "SDL_Image.h"

Texture::Texture()
{
	SDLTexture = nullptr;
	Renderer = nullptr;

	SetSize(std::pair<int, int>(1, 1));

	Format = (Uint32)SDL_PIXELFORMAT_RGBA8888;
}


Texture::Texture(const std::pair<int, int>& InSize, SDL_Renderer & InRenderer)
{
	SDLTexture = nullptr;
	Renderer = &InRenderer;

	SetSize(InSize);

	Format = (Uint32)SDL_PIXELFORMAT_RGBA8888;
}

Texture::~Texture()
{
	Free();
}

void Texture::LoadFromFile(const std::string & path)
{
	Free();		// gets rid of previously loaded textures

	SDL_Surface * LoadedSurface = IMG_Load(path.c_str());

	if (LoadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		if (Renderer == nullptr)
		{
			printf("Unable to load image %s! Renderer not Defined!");
		}
		else
		{
			SDLTexture = SDL_CreateTextureFromSurface(Renderer, LoadedSurface);
			std::pair<int, int> ImageSize = std::pair<int, int>(LoadedSurface->w, LoadedSurface->h);
			SetSizeFromImage(ImageSize);
		}
		
		SDL_FreeSurface(LoadedSurface);

	}
}

void Texture::Free()
{
	if (SDLTexture != nullptr)
	{
		SDL_DestroyTexture(SDLTexture);
	}
}

void Texture::RenderPoint(int x, int y) const
{
}

std::pair<int, int>& Texture::GetSize()
{
	return Size;
}

void Texture::SetSize(const std::pair<int, int>& InSize)
{
	if (InSize.first > 0 && InSize.second > 0)
	{
		Size = InSize;	
		int QueryRes = SDL_QueryTexture(SDLTexture, &Format, NULL, &Size.first, &Size.second);
		if (QueryRes != 0)
		{
			printf("Unable to set the Texture Size! SDL Error: %s\n", SDL_GetError());
		}
	}
	else
	{
		printf("Unable to set the Texture Size! Negative Size Value(s)");
	}
}

void Texture::SetSizeFromImage(const std::pair<int, int> & InSize)
{
	if (InSize.first > 0 && InSize.second > 0)
	{
		Size = InSize;
	}
	else
	{
		printf("Unable to set the Texture Size from a Loaded Image! Negative Size Value(s)");
	}
}


SDL_Renderer & Texture::GetRenderer()
{
	// TODO: insert return statement here
}

void Texture::SetRenderer(SDL_Renderer & Renderer)
{
}
