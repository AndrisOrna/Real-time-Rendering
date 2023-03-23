#pragma once

#include "ShaderTechnique.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

struct ObjectProperties
{
	vec3		pos;
	vec4		color;
	vec3		normal;

	ShaderTechnique* shader; // pointer to the attached shader
};

class GameObject
{
public:
	// default constructor
	GameObject();

	ShaderTechnique * shader; // pointer to shader

	void createVertexBuffer(vec3 gameObjectProperties[], int numverts);

	void createVertexBuffer(ObjectProperties properties[], int numverts);

	void render();

	void setShaderForGameObject(ShaderTechnique* s);
private:
	GLuint vbo; // vertex buffer object
	GLuint numOfVertices; // max number of vertices

	ObjectProperties gameObjectProperties;
	
};



