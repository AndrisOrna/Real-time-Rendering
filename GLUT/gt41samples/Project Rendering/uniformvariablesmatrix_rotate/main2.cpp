#include "cylinder.h"
#include "GameObject.h"
#pragma once

#include"ShaderTechnique.h"
#define _USE_MATH_DEFINES 

#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <minwindef.h>

//GLuint VBO;


using namespace std;
using namespace glm;

//const int NUMVERTS = 3;

GameObject Triangle1;
ShaderTechnique Shader1;

mat4 worldToViewTransform;
mat4 projectionTransform;

// variables for object translation
float posX = 0.0f, posY = 0.0f;


static void renderSceneCallBack();
static void initializeGlutCallbacks();
// Globals.

//static int p = 6; // Number of grid columns.
//static int q = 4; // Number of grid rows
//static float* vertices = NULL; // Vertex array of the mapped sample on the cylinder.
//static float Xangle = 150.0, Yangle = 60.0, Zangle = 0.0; // Angles to rotate the cylinder.

//char* objName; // Pointer to object name.
//static int objID = 1; // Object ID.

//GLfloat angle = 0.8;
//double rotate_by_key = 0;
//double rotate_x = 0.5;
//double rotate_y = 0.5;

//void GoMenu(int value);
// Routine to draw a stroke character string.
//void writeStrokeString(void* font, char* string)
//{
//	char* c;
//
//	for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
//}
// Routine to write object name.
//void writeObjectName()
//{
//	glPushMatrix();
//	glTranslatef(-4.5, 10.0, -20.0);
//	glScalef(0.01, 0.01, 0.01);
//	writeStrokeString(GLUT_STROKE_ROMAN, objName);
//	glPopMatrix();
//}
void createObjects();
void createObjects()
{


	// Vertices coordinates
	//GameObjectDetails 
	const int numverts = 3;
	GameObjectDetails Triangle1_vertices[numverts]
	{
			{vec3(0.0f, 1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
			{vec3(-1.0f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
			{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};
	// Create vertex buffer
	// Create some vertices to put in our VBO.
	//glGenBuffers(1, &VBO)
	Triangle1.createVertexBuffer(Triangle1_vertices, numverts);
	Triangle1.setShader(&Shader1);
	//Triangle1.settingRotation();

	// Create vertex buffer



}



// Fuctions to map the grid vertex (u_i,v_j) to the mesh vertex (f(u_i,v_j), g(u_i,v_j), h(u_i,v_j)) on the cylinder.
//float f(int i, int j)
//{
//	return (cos((-1 + 2 * (float)i / p) * 3.14));
//}

//float g(int i, int j)
//{
//	return (sin((-1 + 2 * (float)i / p) * 3.14));
//}

//float h(int i, int j)
//{
//	return (-1 + 2 * (float)j / q);
//}

//void mouse(int button, int state, int x, int y)
//{
//	if (button == 3)
//	{
//		rotate_x -= 0.5;
//	}
//	else
//	{
//		rotate_x += 0.5;
//	}
//	glutPostRedisplay();
//}
// Routine to fill the vertex array with co-ordinates of the mapped sample points.
//void fillVertexArray(void)
//{
//	int i, j, k;
//
//	k = 0;
//	for (j = 0; j <= q; j++)
//		for (i = 0; i <= p; i++)
//		{
//			vertices[k++] = f(i, j);
//			vertices[k++] = g(i, j);
//			vertices[k++] = h(i, j);
//		}
//}




// Drawing routine.
static void renderSceneCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Shader1.updateShader(worldToViewTransform, projectionTransform);
	//Shader1.useThisShader();
	//Shader1.updateThisShader(worldToViewTransform, projectionTransform);
	//Triangle1.render();
	//int  i, j;
	//vertices = new float[3 * (p + 1) * (q + 1)];
	//glutWireSphere(2.0, 20, 20);
	//glVertexPointer(3, GL_FLOAT, 0, vertices);
	//glClearColor(0.0, 0.0, 0.0, 0.02);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glLoadIdentity();
	//gluLookAt(0.0, 3.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Shader1.updateThisShader(worldToViewTransform, projectionTransform);
	Triangle1.render();
	Triangle1.settingTranslation(posX, 0, 0.0f);
	//Triangle1.setShader(Shader1);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glColor3f(0.0, 0.0, 0.0);

	// Rotate scene.
	//glRotatef(Zangle, 0.0, 0.0, 1.0);
	//glRotatef(Yangle, 0.0, 1.0, 0.0);
	//glRotatef(Xangle, 1.0, 0.0, 0.0);

	//glRotatef(rotate_y, 0.0, 1.0, 0.0);
	//glScalef(rotate_x, rotate_y, 1.0);

	// Fill the vertex array.
	//fillVertexArray();

	// Draw objects.
//	switch (objID)
//	{
//	case 1:
//		// Make the approximating triangular mesh.
//		for (j = 0; j < q; j++)
//		{
//			glBegin(GL_TRIANGLE_STRIP);
//			for (i = 0; i <= p; i++)
//			{
//				glArrayElement((j + 1) * (p + 1) + i);
//				glArrayElement(j * (p + 1) + i);
//			}
//
//			glEnd();
//		}
//		objName = "Cylinder";
//		break;
//	case 2:
//
//
//		Triangle1.render();
//		//glutSolidCube(40);
//		//glutWireSphere(5.0, 40, 40);
//		objName = "Triangle 1";
//		break;
//	case 3:
//		glutSolidCube(7.0);
//		objName = "Solid Cube";
//		break;
//	case 4:
//		glutWireCube(7.0);
//		objName = "Wire Cube";
//		break;
//	case 5:
//		glutSolidCone(3.0, 8.0, 30, 30);
//		objName = "Solid Cone";
//		break;
//	case 6:
//		glutWireCone(3.0, 8.0, 30, 30);
//		objName = "Wire Cone";
//		break;
//	case 7:
//		glutSolidTorus(1.0, 4.0, 30, 30);
//		objName = "Solid Torus";
//		break;
//	case 8:
//		glutWireTorus(1.0, 4.0, 30, 30);
//		objName = "Wire Torus";
//		break;
//	case 9:
//		glScalef(3.0, 3.0, 3.0);
//		glutSolidDodecahedron();
//		objName = "Solid Dodecahedron";
//		break;
//	case 10:
//		glScalef(3.0, 3.0, 3.0);
//		glutWireDodecahedron();
//		objName = "Wire Dodecahedron";
//		break;
//	case 11:
//		glScalef(5.0, 5.0, 5.0);
//		glutSolidOctahedron();
//		objName = "Solid Octahecron";
//		break;
//	case 12:
//		glScalef(5.0, 5.0, 5.0);
//		glutWireOctahedron();
//		objName = "Wire Octahedron";
//		break;
//	case 13:
//		glScalef(6.0, 6.0, 6.0);
//		glutSolidTetrahedron();
//		objName = "Solid Tetrahedron";
//		break;
//	case 14:
//		glScalef(6.0, 6.0, 6.0);
//		glutWireTetrahedron();
//		objName = "Wire Tetrahedron";
//		break;
//	case 15:
//		glScalef(5.0, 5.0, 5.0);
//		glutSolidIcosahedron();
//		objName = "Solid Icosahedron";
//		break;
//	case 16:
//		glScalef(5.0, 5.0, 5.0);
//		glutWireIcosahedron();
//		objName = "Wire Icosahedron";
//		break;
//	case 17:
//		glutSolidTeapot(4.0);
//		objName = "Solid Teapot";
//		break;
//	case 18:
//		glutWireTeapot(4.0);
//		objName = "Wire Teapot";
//		break;
//	default:
//		break;
//	}
//	glPopMatrix();
//
//	// Write label after disabling lighting.
//	//glDisable(GL_LIGHTING);
//	//glColor3f(0.0, 0.0, 0.0);
//	writeObjectName();
//	//glEnable(GL_LIGHTING);
//	glutSwapBuffers();

	glutSwapBuffers();
}

// Initialization routine.
static void initializeGlutCallbacks()
{
	glutDisplayFunc(renderSceneCallBack);
	glutIdleFunc(renderSceneCallBack);
	//glutMouseFunc(processMouse);
	//glutKeyboardFunc(processKeyboardDown);
	//glutKeyboardUpFunc(processKeyboardUp);
	//glEnableClientState(GL_VERTEX_ARRAY);

	//glClearColor(0.0, 0.0, 0.0, 0.0);
}
// Callback routine for non-ASCII key entry.
//void specialKeyInputForChangingObjects(int key, int x, int y)
//{
//	if (key == GLUT_KEY_F1)
//	{
//		if (objID > 1) objID--;
//		else objID = 18;
//	}
//	if (key == GLUT_KEY_F2)
//	{
//		if (objID > 1) objID--;
//		else objID = 18;
//	}
//	if (key == GLUT_KEY_F3)
//	{
//		if (objID < 18) objID++;
//		else objID = 1;
//	}
//	if (key == GLUT_KEY_F4)
//	{
//		if (objID < 18) objID++;
//		else objID = 1;
//	}
//
//	Xangle = Yangle = Zangle = 0.0;
//	glutPostRedisplay();
//}



// OpenGL window reshape routine.
//void resize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
//	glMatrixMode(GL_MODELVIEW);
//
//}

// Keyboard input processing routine.
//void keyInputRotation(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 27:
//		exit(0);
//		break;
//	case 'x':
//		Xangle += 5.0;
//		if (Xangle > 360.0) Xangle -= 360.0;
//		glutPostRedisplay();
//		break;
//	case 'X':
//		Xangle -= 5.0;
//		if (Xangle < 0.0) Xangle += 360.0;
//		glutPostRedisplay();
//		break;
//	case 'y':
//		Yangle += 5.0;
//		if (Yangle > 360.0) Yangle -= 360.0;
//		glutPostRedisplay();
//		break;
//	case 'Y':
//		Yangle -= 5.0;
//		if (Yangle < 0.0) Yangle += 360.0;
//		glutPostRedisplay();
//		break;
//	case 'z':
//		Zangle += 5.0;
//		if (Zangle > 360.0) Zangle -= 360.0;
//		glutPostRedisplay();
//		break;
//	case 'Z':
//		Zangle -= 5.0;
//		if (Zangle < 0.0) Zangle += 360.0;
//		glutPostRedisplay();
//		break;
//	case '+':
//		rotate_x += 0.05;
//		glutPostRedisplay();
//		break;
//	case '-':
//		rotate_x -= 0.05;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//}

// Callback routine for non-ASCII key entry.
//void specialKeyInputForMatrices(int key, int x, int y)
//{
//	if (key == GLUT_KEY_LEFT) if (p > 3) p -= 1;
//	if (key == GLUT_KEY_RIGHT) p += 1;
//	if (key == GLUT_KEY_DOWN) if (q > 3) q -= 1;
//	if (key == GLUT_KEY_UP) q += 1;
//
//	glutPostRedisplay();
//}



//void keyboard(int key, int x, int y)
//{
//	if (key == GLUT_KEY_ALT_L)
//		rotate_x += 0.05;
//	if (key == GLUT_KEY_ALT_R)
//		rotate_x -= 0.05;
//	glutPostRedisplay();
//}
// Routine to output interaction instructions to the C++ window.
//void printInteraction(void)
//{
//	std::cout << "Interaction:" << std::endl;
//	std::cout << "Press left/right arrow keys to increase/decrease the number of grid columns for CYLINDER ONLY." << std::endl
//		<< "Press up/down arrow keys to increase/decrease the number of grid rows for CYLINDER ONLY." << std::endl
//		<< "Use mouse scroll to zoom in and out" << std::endl
//		<< "F1, F2, F3, F4  switching the objects" << std::endl
//		<< "Right mouse click to change colour maybe later the shaders(In progress)." << std::endl
//		<< "Press X, Y, Z to rotate objects." << std::endl;
//}

//void GoMenu(int value)
//{
//	switch (value)
//	{
//	case 1:
//		glColor3f(1.0, 0.0, 0.0);
//		break;
//	case 2:
//		glColor3f(0.0, 0.0, 1.0);
//		break;
//	case 3:
//		glColor3f(0.0, 1.0, 0.0);
//		break;
//	case 4:
//		exit(0);
//		break;
//	}
//	glutPostRedisplay();
//
//}

//Main routine.
int main(int argc, char** argv)
{
	//printInteraction();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rendering Project");
	initializeGlutCallbacks();
	//drawScene();
	//glutDisplayFunc(drawScene);
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		cerr << "Error: " << glewGetErrorString(res) << "\n";
		return 1;
	}
	
	Shader1.buildShader("vertexshader.glsl", "fragmentshader.glsl");

	// Enable the z-buffer
	//glEnable(GL_DEPTH_TEST);
	// GL_LESS - Passes if the incoming depth value is less than the stored depth value
	//glDepthFunc(GL_LESS);

	//Enable backface culling
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

	createObjects();


	//glutInitContextVersion(4, 3);
	//glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	// Creating Menu
	//int sub1 = glutCreateMenu(GoMenu);
	//glutAddMenuEntry("Color the object red", 1);
	//glutAddMenuEntry("Color the object blue", 2);
	//glutAddMenuEntry("Color the object green", 3);
	//glutCreateMenu(GoMenu);
	//glutAddSubMenu("Object Colours", sub1);
	//glutAddMenuEntry("Would You like to exit", 4);
	//glutAttachMenu(GLUT_RIGHT_BUTTON);


	//buildShaders();

	//glutReshapeFunc(resize);
	//initRendering();
	//glutKeyboardFunc(keyInputRotation);
	//glutSpecialFunc(specialKeyInputForMatrices);
	//glutSpecialFunc(specialKeyInputForChangingObjects);

	//glutSpecialFunc(keyboard);
	//glutMouseFunc(mouse);

	//glewExperimental = GL_TRUE;
	//glewInit();
	//setup();

	glutMainLoop();
	return 0;
}