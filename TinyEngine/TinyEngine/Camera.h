#pragma once

#include "Vector3.h"
#include "Texture.h"
#include "Actor.h"

enum CameraMode { OPENGL, RAYTRACING };

class Camera : Actor
{
public:

	Camera();
	Camera(Texture & RenderTarget);

	~Camera();

	void InitializeRenderer();

	void SetRenderingTarget(Texture & RenderingTarget);


protected:
	
	Texture			* RenderView;
	SDL_Renderer	* Renderer;

};

