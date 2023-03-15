#pragma once
#include "ClassB.h"

class ClassA
{
public: // forgot to mention that it is public, will not work in project4.cpp
	GLuint VBO;
	GLuint numOfVertices;
	ClassB* shader;

	ClassA();

	void createVertexBuffer(vec3 vertices[], int numverts);
	void render();
};

