#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "ShaderTechnique.h"




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
	//RenderObject gameObjectProperties;
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
	//void rotate() {
	//	mat4 worldToViewTransform = lookAt(
	//				vec3(0.0f, 0.0f, 10.0f), // The position of your camera, in world space
	//				vec3(0.0f, 0.0f, 0.0f), // where you want to look at, in world space
	//				vec3(0.0f, 1.0f, 0.0f)  // Camera up direction (set to 0,-1,0 to look upside-down)
	//			);
	//			// Create out projection transform
	//			//mat4 projectionTransform = perspective(45.0f, (float)windowWidth / (float)windowHeight, 1.0f, 100.0f);
	//		
	//			// Update the transforms in the shader program on the GPU
	//			//glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
	//			//glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);
	//		
	//			glEnableVertexAttribArray(0);
	//			glEnableVertexAttribArray(1);
	//			//glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	//			//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
	//			//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
	//		
	//			// Create a new model to world transform
	//			mat4 scalem = mat4(1.0f);
	//			scalem = scale(scalem, vec3(0.5f, 0.5f, 0.5f));
	//		
	//			static float angle = 0.0f;
	//			angle += 1.0f;
	//			mat4 rot = mat4(1.0f);
	//			//rot = rotate(rot, angle, vec3(0.0f, 1.0f, 0.0f));
	//}
	//void rotate();
};