#include "ShaderTechnique.h"
#include "GameObject.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <glm/gtc/matrix_transform.hpp>
//#include <GLFW/glfw3.h>
const int windowWidth = 1024;
const int windowHeight = 768;

// some global GameObjects
GameObject gameObjectTriangle;
GameObject gameObjectTriangle2;
GameObject gameObjectTriangle3;
GameObject gameObjectSquare;
ShaderTechnique s;
GLuint VBO;
const int NUMVERTS = 3;
//GameObject gameObject3;
ShaderTechnique Shader1;

mat4 worldToViewTransform;
mat4 projectionTransform;
//GLuint gModelToWorldTransformLocation1;
//GLuint gModelToWorldTransformLocation2;
//GLuint gModelToWorldTransformLocation3;
//GLuint gWorldToViewTransformLocation;
//GLuint gProjectionTransformLocation;
void createGameObjects();
static void renderSceneCallBack();
struct SimpleVertex
{
	glm::vec3		pos;	// Position
	glm::vec4		colour;	// Colour
};


static void renderSceneCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Create our world space to view space transformation matrix
	mat4 worldToViewTransform = lookAt(
		vec3(0.0f, 0.0f, 10.0f), // The position of your camera, in world space
		vec3(0.0f, 0.0f, 0.0f), // where you want to look at, in world space
		vec3(0.0f, 1.0f, 0.0f)  // Camera up direction (set to 0,-1,0 to look upside-down)
	);
	mat4 projectionTransform = perspective(45.0f, (float)windowWidth / (float)windowHeight, 1.0f, 100.0f);


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

	Shader1.updateShader(worldToViewTransform, projectionTransform);

	
	//glUniformMatrix4fv(gModelToWorldTransformLocation1, 1, GL_FALSE, &modelToWorldTransform[0][0]);



	//glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);

	gameObjectTriangle.render();

	//gameObjectTriangle2.render();
//
	//gameObjectTriangle3.render();

	/*gameObjectSquare.shader->buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
	gameObjectSquare.render();

	gameObjectSquare.shader->buildShader("vertexshader_interpolation.glsl", "fragmentshader_interpolation.glsl");
	gameObjectSquare.render();*/

	glutSwapBuffers();
}

static void initializeGlutCallbacks()
{
	glutDisplayFunc(renderSceneCallBack);
	glutIdleFunc(renderSceneCallBack);
}

static void createGameObjects()
{
	//////// Triangle 1 ////
	const int numVertsTriangle = 3;	// use this once or duplicate for each vbo

	ObjectProperties Triangle1Details[numVertsTriangle]=
	{
		{vec3(0.0f, 1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)},
		{vec3(-1.0f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f), vec3(0.0f, 0.0f, 1.0f)}
	}
	/*gameObjectTriangle = GameObject();
	vec3 vert_gameObject1[numVertsTriangle];
	vert_gameObject1[0] = vec3(-2.5f, 1.5f, 0.0f);
	vert_gameObject1[1] = vec3(-1.5f, 1.5f, 0.0f);
	vert_gameObject1[2] = vec3(-2.0f, 2.5f, 0.0f);*/;
	//gameObjectTriangle.render(GL_TRIANGLES, 0, numVertsTriangle);
	gameObjectTriangle.createVertexBuffer(Triangle1Details, numVertsTriangle);
	gameObjectTriangle.setShaderForGameObject(&s);

	//////// Triangle 2 ////

	const int numVertsTriangle2 = 3;	// use this once or duplicate for each vbo

	gameObjectTriangle2 = GameObject();
	vec3 vert_gameObject2[numVertsTriangle2];
	vert_gameObject2[0] = vec3(2.5f, -1.5f, 0.0f);
	vert_gameObject2[1] = vec3(1.5f, -1.5f, 0.0f);
	vert_gameObject2[2] = vec3(2.0f, -2.5f, 0.0f);

	gameObjectTriangle2.createVertexBuffer(vert_gameObject2, numVertsTriangle2);
	gameObjectTriangle2.setShaderForGameObject(&s);
	//////// Triangle 3 ////

	//const int numVertsTriangle3 = 3;	// use this once or duplicate for each vbo

	//gameObjectTriangle3 = GameObject2();
	//vec3 vert_gameObject3[numVertsTriangle3];
	//vert_gameObject3[0] = vec3(1.5f, -1.5f, 0.0f);
	//vert_gameObject3[1] = vec3(1.5f, -1.5f, 0.0f);
	//vert_gameObject3[2] = vec3(1.0f, -2.5f, 0.0f);

	//gameObjectTriangle3.createVertexBuffer(vert_gameObject3, numVertsTriangle3);
	// Create vertex buffer
	/*SimpleVertex vertices[] =
	{
		{vec3(0.0f, 1.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		{vec3(-1.0f, 0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		{vec3(1.0f,0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)}
	};*/

	/*glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * NUMVERTS, vertices, GL_STATIC_DRAW);*/

	/// /////////////   SQUARE   ////////
	//const int numVertsSquare = 5;
	//gameObjectSquare = GameObject(GL_QUADS);
	//gameObjectSquare = GameObject2();
	//vec3 vert_gameObject3[numVertsSquare];
	////glColor3f(0.0f, 1.0f, 0.0f);

	//vert_gameObject3[0] = vec3(-0.8f, 0.1f, 0.0f);// left bottom
	//vert_gameObject3[1] = vec3(-0.2f, 0.1f, 0.0f);// left top
	//vert_gameObject3[2] = vec3(-0.2f, 0.7f, 0.0f);// right top
	//vert_gameObject3[3] = vec3(-0.8f, 0.7f, 0.0f);// left bottom
	//gameObjectSquare.createVertexBuffer(vert_gameObject3, numVertsSquare);

	////////////   Interpolated object  ////////
	/*SimpleVertex vertices[] =
	{
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		{glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		{glm::vec3(0.0f, 0.5f, 0.0f),  glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};*/

#ifndef Other Objects, working on square
	/*glBegin(GL_QUADS);
	glColor3ub(0, 150, 254);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.4, 0.3);
	glEnd();
	glFlush();*/

	/*const int numVertsSquare = 4;
	gameObjectSquare = GameObject();
	vec4 verticesOf_gameObjectSquare[numVertsSquare];
	verticesOf_gameObjectSquare[0] = vec4(0.0f, 0.0f, 0.0f);
	verticesOf_gameObjectSquare[1] = vec4(1.0f, 0.0f, 0.0f);
	verticesOf_gameObjectSquare[2] = vec4(0.5f, 1.0f, 0.0f);
	verticesOf_gameObjectSquare[3] = vec4(1.0f, 1.0f, 0.9f);

	gameObjectSquare.createVertexBuffer(verticesOf_gameObjectSquare, numVertsSquare);*/

	//const int numVerts3 = 4;

	//gameObjectSquare = GameObject();
	//vec3 vertices4[numVerts3];
	//////glColor3f(0.0f, 1.0f, 0.0f);

	//vertices4[0] = vec3(-0.7f, 0.4f, 0.0f);// left bottom
	//vertices4[1] = vec3(-0.7f, 0.7f, 0.0f);// left top
	//vertices4[2] = vec3(0.7f, 0.2f, 0.0f);// right top
	//vertices4[3] = vec3(0.7f, -0.2f, 0.0f);// right bottom

	//gameObjectSquare.createVertexBuffer(vertices4, numVerts3);


	/*gameObject3 = GameObject();
	vec3 vert_gameObject3[numVerts];
	vert_gameObject3[0] = vec3(-0.5f, -0.5f, 0.0f);
	vert_gameObject3[1] = vec3(0.5f, -0.5f, 0.0f);
	vert_gameObject3[2] = vec3(0.0f, -1.5f, 0.0f);

	gameObject3.createVertexBuffer(vert_gameObject3, numVerts);*/
#endif 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rendering Objects part 1 version 2 running");


	initializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		cerr << "Error: " << glewGetErrorString(res) << "\n";
		return 1;
	}

	s.buildShader("vertexshader2.glsl", "fragmentshader2.glsl");

	glClearColor(0.3f, 0.2f, 0.0f, 0.0f);

	createGameObjects();


	glutMainLoop();

	return 0;
}