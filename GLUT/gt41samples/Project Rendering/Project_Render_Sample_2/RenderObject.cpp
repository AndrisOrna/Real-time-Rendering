#include "RenderObject.h"
//#include "ShaderTechnique.h"
#include <glm/gtc/matrix_transform.hpp>


float scaleValue;

RenderObject::RenderObject()
{
	vbo = NULL;
	numOfVertices = 0;
	shader = NULL;
}

void RenderObject::createBuffer(VertexData vertices[], int numverts)
{
	cout << "Creating buffer...." << endl;
	numOfVertices = numverts;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * numOfVertices, vertices, GL_STATIC_DRAW);
}

void RenderObject::render()
{
	cout << "rendering...." << endl;
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 40, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 40, (const GLvoid*)12);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 40, (const GLvoid*)28);
	
	shader->useShader();

	glDrawArrays(GL_TRIANGLES, 0, numOfVertices);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

//void RenderObject::rotate()
//{
//	mat4 worldToViewTransform = lookAt(
//		vec3(0.0f, 0.0f, 10.0f), // The position of your camera, in world space
//		vec3(0.0f, 0.0f, 0.0f), // where you want to look at, in world space
//		vec3(0.0f, 1.0f, 0.0f)  // Camera up direction (set to 0,-1,0 to look upside-down)
//	);
//	// Create out projection transform
//	//mat4 projectionTransform = perspective(45.0f, (float)windowWidth / (float)windowHeight, 1.0f, 100.0f);
//
//	// Update the transforms in the shader program on the GPU
//	glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
//	//glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);
//
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
//	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
//
//	// Create a new model to world transform
//	mat4 scalem = mat4(1.0f);
//	scalem = scale(scalem, vec3(0.5f, 0.5f, 0.5f));
//
//	static float angle = 0.0f;
//	angle += 1.0f;
//	mat4 rot = mat4(1.0f);
//	//rot = rotate(rot, angle, vec3(0.0f, 1.0f, 0.0f));
//}

void RenderObject::setShader(ShaderTechnique* s)
{
	shader = s;
}
