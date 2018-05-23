#pragma once

#include "Vector3.h"
#include "Texture.h"

enum CameraMode { OPENGL, RAYTRACING };

class Camera
{
public:

	Camera();
	Camera(Texture & RenderTarget);

	~Camera();

	void Render();

	void InitializeRenderer();

	const Vector3 & GetCameraCenter() const;
	void SetCameraCenter(Vector3 & Position);

	void SetRenderingTarget(Texture & RenderingTarget);


protected:

	Vector3 CameraCenter;
	
	Texture			* RenderView;
	SDL_Renderer	* Renderer;

};

