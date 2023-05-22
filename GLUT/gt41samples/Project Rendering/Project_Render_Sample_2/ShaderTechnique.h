#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Windows.h>
#include "aiterror.h"
#include <vector>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;


class ShaderTechnique
{
public:
	GLuint gModelToWorldTransformLocation;
	GLuint gWorldToViewTransformLocation;
	GLuint gProjectionTransformLocation;
	
	// default constructor
	ShaderTechnique();

	// reads (shader) file and returns the content of file as a string
	string readShaderFile(string fileName);

	// creates a type of shader object (Vertex & Fragment) and then compiles and attaches the shader object to the program object
	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);

	// links and validates the shader program and sets it into pipeline
	void buildShader(string vertexShaderPath, string fragmentShaderPath);

	// enables the shader for the gameObject
	void useShader();

	void updateShader(mat4 worldToViewTransform, mat4 projectionTransform);
	GLuint getShaderProgram();

	//void rotate();

	

private:
	GLuint shaderProgram;

	mat4 worldToViewTransform;
	mat4 projectionTransform;

};

