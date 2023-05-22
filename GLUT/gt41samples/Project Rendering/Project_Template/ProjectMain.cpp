#include "ShaderTechnique.h"
#include "RenderObject.h"
#include <glm/gtc/matrix_transform.hpp>

const int windowWidth = 1024;
const int windowHeight = 768;

// some GameObjects
RenderObject triangleA;

// some shaders
ShaderTechnique shaderA;


GLuint gTransformLocation;

// Update the gTransform variable in the Vertex Shade on the GPU
mat4 trans = mat4(1.0f);
mat4 rotat = mat4(1.0f);
mat4 sca = mat4(1.0f);

float scaleValue;

void createGameObjects()
{
	const int numVerts = 3;	// use this once or duplicate for each vbo

	VertexData objA_Data[numVerts] = {
		{vec3(0.0f, 1.0f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
		{vec3(-1.0f, 0.0f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
		{vec3(0.0f, 0.0f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
	};

	triangleA.createBuffer(objA_Data, numVerts);
	triangleA.setShader(&shaderA);
}

static void renderSceneCallBack()
{
	// Clear the back buffer and the z-buffer
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	scaleValue += 0.009f;
	
	// simple scale that goes between 0 and 1
	sca = scale(mat4(1.0f), vec3(cosf(scaleValue), sinf(scaleValue), 1.0f));

	mat4 full = sca;
	glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &full[0][0]);

	triangleA.render();

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
	glutCreateWindow("Project");

	initializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		cerr << "Error: " << glewGetErrorString(res) << "\n";
		return 1;
	}

	// build (all) shaders	
	shaderA.buildShader("vertexshader.glsl", "fragmentshader.glsl");

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
