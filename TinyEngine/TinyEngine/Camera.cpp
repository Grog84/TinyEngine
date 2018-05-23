#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(Texture & RenderTarget)
{
}


Camera::~Camera()
{
}

void Camera::InitializeRenderer()
{
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}