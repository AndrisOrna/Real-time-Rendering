#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <Windows.h>

#include "aiterror.h"

using namespace std;
using namespace glm;

/// A class that can load, compile and link a vertex and fragment shader onto gameobject(s)
class ShaderTechnique
{
public:
	GLuint gModelToWorldTransformLocation;
	GLuint gWorldToViewTransformLocation;
	GLuint gProjectionTransformLocation;
	// default empty constructor
	ShaderTechnique();

	GLuint getShaderProgram();

	string readFile(string fileName);// reads file

	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);// adds shader

	void buildShader(string vertexShaderPath, string fragmentShaderPath);
	void useShader();
	void updateShader(mat4 worldToViewTransform, mat4 projectionTransform);
private:
	GLuint shaderProgram;

	mat4 worldToViewTransform;
	mat4 projectionTransform;
};

