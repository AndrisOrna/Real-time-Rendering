#include <iostream>
#include <string>
//#include "Camera.h"
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <glm/gtc/matrix_transform.hpp>
#include "../../C++ Projects/3rdparty/include/glm/detail/type_vec.hpp"
#include "ShaderTechnique.h"
#include "GameObject.h"
//#include "../Chapter3/GlutObjects/dependencies/glm/gtc/matrix_transform.hpp"
//#include "../../C++ Projects/3rdparty/include/GL/glew.h"
//#include "../Chapter3/GlutObjects/Libraries/include/glad/glad.h"

using namespace std;
using namespace glm;
//using namespace glm;
// initialize some window properties
//unsigned int windowWidth = 800;
//unsigned int windowHeight = 500;
//unsigned int windowPos_X = 800;
//unsigned int windowPos_Y = 400;
//const char* windowTitle = "A00273758: Rendering Project - Part 1";
//GLuint gTransformLocation;
// some global GameObjects
//GameObject gameObject1;
//GameObject gameObject2;
//GameObject gameObject3;

static int objID = 1; // Object ID.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate objects.
static std::string objName; // Pointer to object name.


const int windowWidth = 1024;
const int windowHeight = 768;

GLuint VBO;
GLuint VBO1;
const int NUMVERTS = 3;
const int NUMVERTS1 = 3;

//Uniform variables
GLuint gModelToWorldTransformLocation;
GLuint gWorldToViewTransformLocation;
GLuint gProjectionTransformLocation;

//Camera camera(windowWidth, windowHeight, glm::vec3(0.0f, 0.0f, 2.0f));


// Our simple vertex container
struct SimpleVertex
{
	vec3		pos;	// Position
	vec4		colour;	// Colour
};

void writeStrokeString(void* font, std::string str)
{
	//char* c;
	//for (c = str; *c != '\0'; c++)
	for(int i=0; i<str.length(); i++)
	{
		glutStrokeCharacter(font, str[i]);
	}
}

static void drawTransformTriangle()
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS1);

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

	//mat4 modelToWorldTransform = trans * rot * scalem;
	mat4 modelToWorldTransform = rot;
	glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);


	//glDrawArrays(GL_TRIANGLES, 0, NUMVERTS1);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	//glutSwapBuffers();
}

// Routine to write object name.
void writeObjectName()
{
	glPushMatrix();
	glTranslatef(-4.5, 10.0, -20.0);
	glScalef(0.01, 0.01, 0.01);
	writeStrokeString(GLUT_STROKE_ROMAN, objName);
	glPopMatrix();
}
// The commented piece of code is the code that works for other GameObject class alternatives...
//1st is for Shader Instance...2nd line is for only inheritance

void drawScene1()
{
	glClear(GL_COLOR_BUFFER_BIT);  // if it is missing | GL_DEPTH_BUFFER_BIT it will not draw it
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);


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

	//mat4 modelToWorldTransform = trans * rot * scalem;
	mat4 modelToWorldTransform = rot;
	glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);

	glLoadIdentity();
	// Position the objects for viewing.
	gluLookAt(0.0, 3.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLineWidth(2.0); // Thicken the wireframes.
	// Commands to turn the objects.
	glPushMatrix();
	glRotatef(Zangle, 0.0, 0.0, 1.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	glRotatef(Xangle, 1.0, 0.0, 0.0);

	// Draw objects.
	switch (objID)
	{
		case 1:
			//glutSolidSphere(5.0, 40, 40);
			drawScene1();
			objName = "First Triangle";
			break;
		case 2:
			//drawTransformTriangle();
			//glutWireSphere(5.0, 40, 40);
			objName = "Triangle Transform press X,Y,Z to rotate";
			break;
		case 3:
			//gameObject1.shader->buildShader("vertexshader.glsl", "fragmentShader.glsl");
			//drawTransformTriangle();
			glutWireSphere(5.0, 40, 40);
			objName = "Triangle Camera view ";
			break;
		case 4:
			//drawTransformTriangle();
			//glutWireSphere(5.0, 40, 40);
			//objName = "Triangle Uniform variable";
			break;
		default:
			break;
	}

	glPopMatrix();

	// Write label after disabling lighting.
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 0.0, 0.0);
	writeObjectName();
	glEnable(GL_LIGHTING);


	//gameObject1.shader->buildShader("vertexshader.glsl", "fragmentShader.glsl");
	// gameObject1.shader.buildShader("vertexShader.glsl", "fragmentShader.glsl");
	// gameObject1.buildShader("vertexShader.glsl", "fragmentShader.glsl");
	//gameObject1.render();

	//gameObject2.shader->buildShader("vertexShader2.glsl", "fragmentshader2.glsl");
	// gameObject2.shader.buildShader("vertexshader2.glsl", "fragmentshader2.glsl");
	// gameObject2.buildShader("vertexshader2.glsl", "fragmentshader2.glsl");
	//gameObject2.render();

	//gameObject3.shader->buildShader("vertexShader3.glsl", "fragmentshader3.glsl");
	// gameObject3.shader.buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
	// gameObject3.buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
	//gameObject3.render();
	/*glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);*/

	glutSwapBuffers();
}
static void initializeGlutCallbacks()
{
	glutDisplayFunc(drawScene1);
	glutIdleFunc(drawScene1);
}
static void createVertexBuffer()
{
	// Create some vertices to put in our VBO.
	// Create vertex buffer
	SimpleVertex vertices[] =
	{
		{vec3(0.0f, 0.7f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		{vec3(-1.0f, 0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		{vec3(1.0f,0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)}
	};

	SimpleVertex vertices1[] =
	{
		{vec3(0.2f, 0.5f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f), vec4(0.3f, 1.0f, 1.0f, 1.0f)},
		{vec3(0.9f,0.9f, 0.9f), vec4(0.5f, 1.0f, 1.0f, 0.7f)}
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * NUMVERTS, vertices, GL_STATIC_DRAW);


	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * NUMVERTS1, vertices1, GL_STATIC_DRAW);
}

//static void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
//{
//	GLuint shaderObj = glCreateShader(shaderType);
//
//	if (shaderObj == 0)
//	{
//		std::stringstream ss;
//		ss << "Error creating shader type " << shaderType << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	const GLchar* p[1];
//	p[0] = pShaderText;
//	GLint Lengths[1];
//	Lengths[0] = strlen(pShaderText);
//	glShaderSource(shaderObj, 1, p, Lengths);
//	glCompileShader(shaderObj);
//	GLint success;
//	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		GLchar InfoLog[1024];
//		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
//		std::stringstream ss;
//		ss << "Error compiling shader type " << shaderType << ": " << InfoLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glAttachShader(shaderProgram, shaderObj);
//}
//
//const string readFileToString(char* filename)
//{
//	ifstream file(filename, ios::in);
//	if (file.is_open())
//	{
//		stringstream continut;
//		continut << file.rdbuf();
//		continut << '\0';
//		return continut.str();
//	}
//	return "";
//}
//
//static void buildShaders()
//{
//	GLuint shaderProgram = glCreateProgram();
//
//	if (shaderProgram == 0)
//	{
//		AIT_ASSERT(0, "Error creating shader program\n");
//	}
//
//	string VS = readFileToString("vertexshader.glsl");
//	string FS = readFileToString("fragmentshader.glsl");
//
//	addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
//	addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);
//
//	GLint success = 0;
//	GLchar errorLog[1024] = { 0 };
//
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (success == 0)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		std::stringstream ss;
//		ss << "Error linking shader program: " << errorLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glValidateProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		cerr << "Error linking shader program: " << errorLog << endl;
//		std::stringstream ss;
//		ss << "Error linking shader program: " << errorLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glUseProgram(shaderProgram);
//
//	gModelToWorldTransformLocation = glGetUniformLocation(shaderProgram, "gModelToWorldTransform");
//	assert(gModelToWorldTransformLocation != 0xFFFFFFFF);
//	gWorldToViewTransformLocation = glGetUniformLocation(shaderProgram, "gWorldToViewTransform");
//	assert(gWorldToViewTransformLocation != 0xFFFFFFFF);
//	gProjectionTransformLocation = glGetUniformLocation(shaderProgram, "gProjectionTransform");
//	assert(gProjectionTransformLocation != 0xFFFFFFFF);
//
//}
// Initialization routine.
void setup(void)
{
	// Material property vectors.
	float matSpec[] = { 0.0, 1.0, 1.0, 1.0 };
	float matShine[] = { 50.0 };
	float matAmbAndDif[] = { 0.0, 0.1, 1.0, 1.0 };

	// Light property vectors.
	float lightAmb[] = { 0.0, 0.1, 1.0, 1.0 };
	float lightDifAndSpec[] = { 0.0, 0.1, 1.0, 1.0 };
	float lightPos[] = { 0.0, 7.0, 3.0, 0.0 };
	float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

	// Material properties of the objects.
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matAmbAndDif);

	// Light0 properties.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Poperties of the ambient light.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

	glEnable(GL_LIGHTING); // Enable lighting calculations.
	glEnable(GL_LIGHT0); // Enable particular light source.
	glEnable(GL_DEPTH_TEST); // Enable depth testing.

	glEnable(GL_NORMALIZE); // Enable automatic normalization of normals.

	glClearColor(1.0, 1.0, 1.0, 0.0);
}



// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'x':
		Xangle += 5.0;
		if (Xangle > 360.0) Xangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'X':
		Xangle -= 5.0;
		if (Xangle < 0.0) Xangle += 360.0;
		glutPostRedisplay();
		break;
	case 'y':
		Yangle += 5.0;
		if (Yangle > 360.0) Yangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Y':
		Yangle -= 5.0;
		if (Yangle < 0.0) Yangle += 360.0;
		glutPostRedisplay();
		break;
	case 'z':
		Zangle += 5.0;
		if (Zangle > 360.0) Zangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Z':
		Zangle -= 5.0;
		if (Zangle < 0.0) Zangle += 360.0;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN)
	{
		if (objID > 1) objID--;
		else objID = 3;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (objID > 1) objID--;
		else objID = 3;
	}
	if (key == GLUT_KEY_UP)
	{
		if (objID < 3) objID++;
		else objID = 1;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (objID < 3) objID++;
		else objID = 1;
	}

	Xangle = Yangle = Zangle = 0.0;
	glutPostRedisplay();
}


// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "You are able to rotate, scale and change camera view:" << std::endl;
	std::cout << "Press the arrow keys to cycle through the objects." << std::endl
		<< "Press X, Y, Z to turn the objects." << std::endl
		<< "Press + or - to to zoom in and out" << std::endl;
}
// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}



//static void initializeGlutCallbacks()
//{
//	glutDisplayFunc(renderSceneCallBack);
//}

//static void createGameObjects()
//{
//	const int numVerts = 3;	// use this once or duplicate for each vbo
//
//	gameObject1 = GameObject();
//	vec3 vert_gameObject1[numVerts];
//	vert_gameObject1[0] = vec3(-2.5f, 1.5f, 0.0f);
//	vert_gameObject1[1] = vec3(-1.5f, 1.5f, 0.0f);
//	vert_gameObject1[2] = vec3(-2.0f, 2.5f, 0.0f);
//
//	gameObject1.createVertexBuffer(vert_gameObject1, numVerts);
//
//	gameObject2 = GameObject();// takes buffer from GameObject.cpp
//	vec3 vert_gameObject2[numVerts];
//	vert_gameObject2[0] = vec3(0.0f, 0.0f, 0.0f);
//	vert_gameObject2[1] = vec3(1.0f, 0.0f, 0.0f);
//	vert_gameObject2[2] = vec3(0.5f, 1.0f, 0.0f);
//
//	gameObject2.createVertexBuffer(vert_gameObject2, numVerts);
//
//	gameObject3 = GameObject();
//	vec3 vert_gameObject3[numVerts];
//	vert_gameObject3[0] = vec3(-0.5f, -0.5f, 0.0f);
//	vert_gameObject3[1] = vec3(0.5f, -0.5f, 0.0f);
//	vert_gameObject3[2] = vec3(0.5f, -1.5f, 0.0f);
//
//	gameObject3.createVertexBuffer(vert_gameObject3, numVerts);



	/*
	Creating objects using a function
	*/
	//vec3 g1v1 = vec3(-2.5f, 1.5f, 0.0f);
	//vec3 g1v2 = vec3(-1.5f, 1.5f, 0.0f);
	//vec3 g1v3 = vec3(-2.0f, 2.5f, 0.0f);

	//gameObject1.createGameObject(g1v1, g1v2, g1v3);

	//vec3 g2v1 = vec3(0.0f, 0.0f, 0.0f);
	//vec3 g2v2 = vec3(1.0f, 0.0f, 0.0f);
	//vec3 g2v3 = vec3(0.5f, 1.0f, 0.0f);

	//gameObject2.createGameObject(g2v1, g2v2, g2v3);

//}
//GLuint programID = LoadShaders("vertexshader.glsl", "fragmentShader.glsl");

//int main(int argc, char** argv)
//{
//	printInteraction();
//	glutInit(&argc, argv);
// 
//	glutInitContextVersion(4, 3);
//	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
// 
// 
// 
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(800, 800);
//	glutInitWindowPosition(100, 80);
//	glutCreateWindow("Project Rendering");
//
//	glutDisplayFunc(renderSceneCallBack);
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(keyInput);
//	glutSpecialFunc(specialKeyInput);
//
//	glewExperimental = GL_TRUE;
//
//
//	//initializeGlutCallbacks();
//
//	// Must be done after glut is initialized!
//	/*GLenum res = glewInit();
//	if (res != GLEW_OK)
//	{
//		cerr << "Error: " << glewGetErrorString(res) << "\n";
//		return 1;
//	}*/
//	glewInit();
//	setup();
//	//createGameObjects();
//	// pointer to object
//	
//	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	glutMainLoop();
//
//	return 0;
//}

// Main routine.
int main(int argc, char** argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rendering Project");
	initializeGlutCallbacks();

	//glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	//buildShaders();
	glewExperimental = GL_TRUE;
	glewInit();
	// Create a vertex buffer
	createVertexBuffer();
	setup();

	glutMainLoop();
}