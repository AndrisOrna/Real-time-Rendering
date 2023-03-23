#pragma once
#include "ShaderTechnique.h"

class GameObject
{
public: // forgot to mention that it is public, will not work in project4.cpp
	GLuint VBO;
	GLuint numOfVertices;
	ShaderTechnique* shader;

	GameObject();

	void createVertexBuffer(vec3 vertices[], int numverts);
	void render();

};
