#pragma once

#include <glm/glm.hpp>
#include <GL/freeglut.h>

using namespace glm;

class tusRenderObj
{
private:
	GLuint numVerts;
	GLuint vbo;

public:
	void createBuffer(vec3 verts[], GLuint nv);
	void render();
};
