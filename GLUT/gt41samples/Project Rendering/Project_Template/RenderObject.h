#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "ShaderTechnique.h"

using namespace std;
using namespace glm;

struct VertexData
{
	vec3		pos;
	vec4		color;
	vec3		normal;
};

class RenderObject
{
private:
	GLuint vbo; // global vertex buffer object
	GLuint numOfVertices; // max number of vertices
	GLuint mode;	// primitive topologies mode
	ShaderTechnique* shader; // pointer to the attached shader

	mat4 finalTransform = mat4(1.0f);
	mat4 trans = mat4(1.0f);
	mat4 rot = mat4(1.0f);
	mat4 sca = mat4(1.0f);

public:
	RenderObject();

	// Creates a buffer based on the array of vertices passed into the function
	void createBuffer(VertexData vertices[], int numverts);

	// sets the shader (initailizes)
	void setShader(ShaderTechnique* s);

	// binds the vbo to the pipeline and draws the points/vertices on to the screen
	void render();
};