#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Windows.h>
#include "aiterror.h"

using namespace std;
using namespace glm;

const int windowWidth = 1024;
const int windowHeight = 768;

GLuint gModelToWorldTransformLocation;
GLuint gWorldToViewTransformLocation;
GLuint gProjectionTransformLocation;


GameObject::GameObject()
{
	VBO = NULL;
	numOfVertices = 0;

	objectDetails.shader = NULL;
}

void GameObject::createVertexBuffer(GameObjectDetails vertices[], int numverts)
{
	cout << "Creating VBO..." << endl;

	numOfVertices = numverts;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GameObjectDetails) * numOfVertices, vertices, GL_STATIC_DRAW);
}
void GameObject::createVertexBuffer(vec3 vertices[], int numverts)
{
	numOfVertices = numverts;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * numOfVertices, vertices, GL_STATIC_DRAW);
}
void GameObject::setShader(ShaderTechnique* s)
{
	cout << "Setting Shader..." << endl;

	objectDetails.shader = s;
}
void GameObject::render()
{
	glClear(GL_COLOR_BUFFER_BIT);


	// Create our world space to view space transformation matrix
	mat4 worldToViewTransform = lookAt(
		vec3(0.0f, 0.0f, 10.0f), // The position of your camera, in world space
		vec3(0.0f, 0.0f, 0.0f), // where you want to look at, in world space
		vec3(0.0f, 1.0f, 0.0f)  // Camera up direction (set to 0,-1,0 to look upside-down)
	);

	// Create out projection transform
	mat4 projectionTransform = perspective(45.0f, (float)windowWidth / (float)windowHeight, 1.0f, 100.0f);

	// Update the transforms in the shader program on the GPU
	glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
	glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), (const GLvoid*)12);

	// Create a new model to world transform
	mat4 scalem = mat4(1.0f);
	scalem = scale(scalem, vec3(0.5f, 0.5f, 0.5f));

	static float angle = 0.0f;
	angle += 1.0f;
	mat4 rot = mat4(1.0f);
	rot = rotate(rot, angle, vec3(0.0f, 1.0f, 0.0f));

	static float y = 0.0f;
	y += 0.01f;
	mat4 trans = mat4(1.0f);
	trans = translate(trans, vec3(0.0f, y, 0.0f));

	mat4 modelToWorldTransform = rot * scalem;

	glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glutSwapBuffers();
	//cout << "Rendering Object..." << endl;
	//glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), 0);
	//objectDetails.shader->useThisShader();
	//glDrawArrays(GL_TRIANGLES, 0, numOfVertices);
	//glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(1);
	
}
void GameObject::settingTranslation(float translateX, float translateY, float translateZ)
{
	//translating = translate(mat4(1.0f), vec3(translateX, translateY, translateZ));
}

