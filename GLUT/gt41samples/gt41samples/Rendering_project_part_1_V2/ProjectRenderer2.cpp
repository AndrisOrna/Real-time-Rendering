#include "ShaderTechnique2.h"
#include "GameObject2.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
//#include <GLFW/glfw3.h>


// some global GameObjects
GameObject2 gameObjectTriangle;
GameObject2 gameObjectTriangle2;
GameObject2 gameObjectSquare;
//GameObject gameObject3;
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate objects.
static int objID = 1; // Object ID.

static float Xvalue = 0.0, Yvalue = 0.0; // Co-ordinates of the sphere.
static float Angle = 0.0; // Angle to rotate the sphere.
//struct SimpleVertex
//{
//	glm::vec3		pos;	// Position
//	glm::vec4		colour;	// Colour
//};
static void renderSceneCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Set the position of the sphere.
	glTranslatef(Xvalue, Yvalue, -5.0);
	glRotatef(Angle, 1.0, 1.0, 1.0);
	gameObjectTriangle.shader->buildShader("vertexShader.glsl", "fragmentShader.glsl");
	gameObjectTriangle.render();

	gameObjectTriangle2.shader->buildShader("vertexshader.glsl", "fragmentshader2.glsl");
	gameObjectTriangle2.render();

	gameObjectSquare.shader->buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
	gameObjectSquare.render();

	gameObjectSquare.shader->buildShader("vertexshader_interpolation.glsl", "fragmentshader_interpolation.glsl");
	gameObjectSquare.render();
	glutSwapBuffers();
}

// Callback routine for non-ASCII key entry.
//void specialKeyInput(int key, int x, int y)
//{
//	if (key == GLUT_KEY_UP) Yvalue += 0.1;
//	if (key == GLUT_KEY_DOWN) Yvalue -= 0.1;
//	if (key == GLUT_KEY_LEFT) Xvalue -= 0.1;
//	if (key == GLUT_KEY_RIGHT) Xvalue += 0.1;
//	glutSwapBuffers();
//	//glutPostRedisplay();
//}
// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		Xvalue = Yvalue = Angle = 0.0;
		glutSwapBuffers();
		//glutPostRedisplay();
		break;
	case ' ':
		Angle += 10.0;
		glutSwapBuffers();
		//glutPostRedisplay();
		break;
	case 27:
		exit(0);
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

static void initializeGlutCallbacks()
{
	glutDisplayFunc(renderSceneCallBack);
}

static void createGameObjects()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//////// Triangle 1 ////

	glLoadIdentity();
	// Position the objects for viewing.
	gluLookAt(0.0, 3.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLineWidth(2.0); // Thicken the wireframes.

	// Commands to turn the objects.
	glPushMatrix();
	glRotatef(Zangle, 0.0, 0.0, 1.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	glRotatef(Xangle, 1.0, 0.0, 0.0);

	// Set the position of the sphere.
	//glTranslatef(Xvalue, Yvalue, -5.0);
	//glRotatef(Angle, 1.0, 1.0, 1.0);

	// Draw objects.
	switch (objID)
	{
	case 1:
		const int numVertsTriangle = 3;	// use this once or duplicate for each vbo

		gameObjectTriangle = GameObject2();
		vec3 vert_gameObject1[numVertsTriangle];
		vert_gameObject1[0] = vec3(-2.5f, 1.5f, 0.0f);
		vert_gameObject1[1] = vec3(-1.5f, 1.5f, 0.0f);
		vert_gameObject1[2] = vec3(-2.0f, 2.5f, 0.0f);

		gameObjectTriangle.createVertexBuffer(vert_gameObject1, numVertsTriangle);
		//glutSolidSphere(5.0, 40, 40);
		//objName = "Solid Sphere";
		break;
	case 2:
		const int numvertstriangle2 = 3;	// use this once or duplicate for each vbo

		gameObjectTriangle2 = GameObject2();
		vec3 vert_gameobject2[numvertstriangle2];
		vert_gameobject2[0] = vec3(2.5f, -1.5f, 0.0f);
		vert_gameobject2[1] = vec3(1.5f, -1.5f, 0.0f);
		vert_gameobject2[2] = vec3(2.0f, -2.5f, 0.0f);

		gameObjectTriangle2.createVertexBuffer(vert_gameobject2, numvertstriangle2);
		//glutWireSphere(5.0, 40, 40);
		//objName = "Wire Sphere";
		break;
	
	default:
		break;
	}
	//glPopMatrix();

	// Write label after disabling lighting.
	//glDisable(GL_LIGHTING);
	//glColor3f(0.0, 0.0, 0.0);
	//writeObjectName();
	//glEnable(GL_LIGHTING);

	glutSwapBuffers();
}
	

	//////// Triangle 2 ////

	


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

// Drawing routine.

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

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
	//drawScene();
	createGameObjects();
	glutKeyboardFunc(keyInput);

	// Register the callback function for non-ASCII key entry.
	glutSpecialFunc(specialKeyInput);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

	return 0;
}