#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
//#include "../Chapter3/GlutObjects/dependencies/glm/gtc/matrix_transform.hpp"
#include <Windows.h>
#include "aiterror.h"
//#include "../../C++ Projects/3rdparty/include/GL/glew.h"
using namespace std;
using namespace glm;

class ShaderTechnique
{
public:
	ShaderTechnique(); //default
	unsigned int m_RendererID;
	GLint GetUniformLocation(const std::string& name);
	void SetUniform2f(const std::string& name, const glm::vec2& value);
	//ShaderTechnique();
	string readFile(string fileName);
	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);
	void buildShader(string vertexShaderPath, string FragmentShaderPath);

	//GLint GetUniformLocation(const std::string& name);

};



