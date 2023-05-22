#include "ShaderTechnique.h"
#include "RenderObject.h"
#include <glm/gtc/matrix_transform.hpp>

const int windowWidth = 1024;
const int windowHeight = 768;

// some GameObjects
RenderObject Triangle1;
RenderObject Triangle2;
RenderObject Triangle3;

// some shaders
ShaderTechnique shader1;

//GLuint gTransformLocation;

// Update the gTransform variable in the Vertex Shade on the GPU
mat4 trans = mat4(1.0f);
mat4 rotat = mat4(1.0f);
mat4 sca = mat4(1.0f);

//float scaleValue;

void createGameObjects()
{
	const int numVerts = 3;	// use this once or duplicate for each vbo
	///  TRIANGLE 1  //////////
	VertexData Data_Triangle1[numVerts] = {
		{vec3(0.0f, 1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		{vec3(-1.0f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};

	Triangle1.createBuffer(Data_Triangle1, numVerts);
	Triangle1.setShader(&shader1);

	///  TRIANGLE 2  //////////
	VertexData Data_Triangle2[numVerts] = {
		{vec3(0.0f, -1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		{vec3(1.0f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};

	Triangle2.createBuffer(Data_Triangle2, numVerts);
	Triangle2.setShader(&shader1);


	///  TRIANGLE 3  //////////
	VertexData Data_Triangle3[numVerts] = {
		{vec3(0.2f, -0.1f, 0.2f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		{vec3(0.2f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};

	Triangle3.createBuffer(Data_Triangle3, numVerts);
	Triangle3.setShader(&shader1);

}

	
	
static void renderSceneCallBack()
{
	// Clear the back buffer and the z-buffer
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	// Create our world space to view space transformation matrix
	
	//scaleValue += 0.009f;

	//// simple scale that goes between 0 and 1
	//sca = scale(mat4(1.0f), vec3(cosf(scaleValue), sinf(scaleValue), 1.0f));

	//mat4 full = sca;
	//glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &full[0][0]);

	Triangle1.render();
	Triangle2.render();
	Triangle3.render();
	glutSwapBuffers();
}

static void initializeGlutCallbacks()
{
	glutDisplayFunc(renderSceneCallBack);
	glutIdleFunc(renderSceneCallBack);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Project Rendering");

	initializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		cerr << "Error: " << glewGetErrorString(res) << "\n";
		return 1;
	}

	// build (all) shaders	
	shader1.buildShader("vertexshader.glsl", "fragmentshader.glsl");

	//// Enable the z-buffer
	//glEnable(GL_DEPTH_TEST);
	//// GL_LESS - Passes if the incoming depth value is less than the stored depth value
	//glDepthFunc(GL_LESS);

	////Enable backface culling
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CW);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	createGameObjects();	// creates set of gameObjects

	glutMainLoop();

	return 0;
}
