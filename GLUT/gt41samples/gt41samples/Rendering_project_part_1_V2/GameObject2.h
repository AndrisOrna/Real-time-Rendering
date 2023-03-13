#pragma once

#include "ShaderTechnique2.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h


class GameObject2
{
public:
	GLuint vbo; // vertex buffer object
	GLuint numOfVertices; // max number of vertices

	ShaderTechnique2 * shader; // pointer to shader

	// default constructor
	GameObject2();


	void createVertexBuffer(vec3 vertices[], int numverts);

	void render();
};



