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
class ShaderTechnique2
{
public:
	// default empty constructor
	ShaderTechnique2();

	string readFile(string fileName);// reads file

	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);// adds shader

	void buildShader(string vertexShaderPath, string fragmentShaderPath);
};

