////#include "ShaderTechnique.h"
//#include "GameObject.h"
////#include "../firstshaders/aiterror.h"
//#include "ShaderTechnique.h"
////using namespace ShaderTechnique2;
//
////using namespace glm;
//// initialize some window properties
////unsigned int windowWidth = 800;
////unsigned int windowHeight = 500;
////unsigned int windowPos_X = 800;
////unsigned int windowPos_Y = 400;
////const char* windowTitle = "A00273758: Rendering Project - Part 1";
//
//// some global GameObjects
//GameObject gameObject1;
//GameObject gameObject2;
//GameObject gameObject3;
//
//ShaderTechnique shader1;
////ShaderTechnique shader2;
//GLuint VBO;
//GLuint VBO1;
//const int NUMVERTS = 3;
//const int NUMVERTS1 = 3;
//
//// Our simple vertex container
//struct SimpleVertex
//{
//	vec3		pos;	// Position
//	vec4		colour;	// Colour
//};
//
//
////1.Create the shader objects in the main
////const GLchar* shader1 = "vertexshader.glsl";
////const GLchar* frag_shad = "vertexshader.glsl";
////2.on these created objects you then build the shader
//
//
////3.then with these you then set the shader of each game object
//
//
////4.then you can render the objects to the screen
//
////ShaderTech2 main_shader(vert_shad, frag_shad);
////main_shader.use();
//
//// The commented piece of code is the code that works for other GameObject class alternatives...
////1st is for Shader Instance...2nd line is for only inheritance
//static void renderSceneCallBack()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	gameObject1.shader->buildShader("vertexshader.glsl", "fragmentShader.glsl");
//	// gameObject1.shader.buildShader("vertexShader.glsl", "fragmentShader.glsl");
//	// gameObject1.buildShader("vertexShader.glsl", "fragmentShader.glsl");
//	gameObject1.render();
//
//	gameObject2.shader->buildShader("vertexShader2.glsl", "fragmentshader2.glsl");
//	// gameObject2.shader.buildShader("vertexshader2.glsl", "fragmentshader2.glsl");
//	// gameObject2.buildShader("vertexshader2.glsl", "fragmentshader2.glsl");
//	gameObject2.render();
//
//	gameObject3.shader->buildShader("vertexShader3.glsl", "fragmentshader3.glsl");
//	// gameObject3.shader.buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
//	// gameObject3.buildShader("vertexshader3.glsl", "fragmentshader3.glsl");
//	gameObject3.render();
//
//	glutSwapBuffers();
//}
//
//static void initializeGlutCallbacks()
//{
//	glutDisplayFunc(renderSceneCallBack);
//	glutIdleFunc(renderSceneCallBack);
//}
//
//static void createGameObjects()
//{
//	const int numVerts = 3;	// use this once or duplicate for each vbo
//
//	vec3 vert_gameObject1[numVerts];
//	vert_gameObject1[0] = vec3(-2.5f, 1.5f, 0.0f);
//	vert_gameObject1[1] = vec3(-1.5f, 1.5f, 0.0f);
//	vert_gameObject1[2] = vec3(-2.0f, 2.5f, 0.0f);
//
//	gameObject1.createVertexBuffer(vert_gameObject1, numVerts);
//
//	//gameObject1.setShader(&shader1);
//
//
//	gameObject2 = GameObject();
//	vec3 vert_gameObject2[numVerts];
//	vert_gameObject2[0] = vec3(0.0f, 0.0f, 0.0f);
//	vert_gameObject2[1] = vec3(1.0f, 0.0f, 0.0f);
//	vert_gameObject2[2] = vec3(0.5f, 1.0f, 0.0f);
//
//	gameObject2.createVertexBuffer(vert_gameObject2, numVerts);
//
//	/*gameObject3 = GameObject();
//	vec3 vert_gameObject3[numVerts];
//	vert_gameObject3[0] = vec3(-0.5f, -0.5f, 0.0f);
//	vert_gameObject3[1] = vec3(0.5f, -0.5f, 0.0f);
//	vert_gameObject3[2] = vec3(0.0f, -1.5f, 0.0f);*/
//
//	//gameObject3.createVertexBuffer(vert_gameObject3, numVerts);
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * NUMVERTS, vert_gameObject2, GL_STATIC_DRAW);
//	glDrawArrays(GL_TRIANGLES, 0, numVerts);
//
//
//
//	/*glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
//	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);*/
//
//	//llglGenBuffers(1, &VBO1);
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//	//glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * NUMVERTS1, vert_gameObject3, GL_STATIC_DRAW);
//
//
//	/*
//	Creating objects using a function
//	*/
//	//vec3 g1v1 = vec3(-2.5f, 1.5f, 0.0f);
//	//vec3 g1v2 = vec3(-1.5f, 1.5f, 0.0f);
//	//vec3 g1v3 = vec3(-2.0f, 2.5f, 0.0f);
//
//	//gameObject1.createGameObject(g1v1, g1v2, g1v3);
//
//	//vec3 g2v1 = vec3(0.0f, 0.0f, 0.0f);
//	//vec3 g2v2 = vec3(1.0f, 0.0f, 0.0f);
//	//vec3 g2v3 = vec3(0.5f, 1.0f, 0.0f);
//
//	//gameObject2.createGameObject(g2v1, g2v2, g2v3);
//
//}
//
//
////GLuint programID = LoadShaders("vertexshader.glsl", "fragmentShader.glsl");
////GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
////CreateShaders();
////GLuint vert_shad, frag_shad;
////
////
//
////const char* vert_shader = "vertexshader.glsl";
////const char* frag_shader = "fragmentShader.glsl";
////
////vert_shad = glCreateShader(GL_VERTEX_SHADER);
////glShaderSource(vert_shad, 1, &vert_shad, NULL);
////glCompileShader(vert_shad);
////Check_Shaders_Program(vert_shad, "vertexshader.glsl");
////
////glDeleteShader(vert_shad); // Flag shader object for automatic deletion (freeing memory) when no longer attached to a program object...
////glDeleteShader(frag_shad); // ... program object is deleted (glDeleteProgram ) within: main() when the application ends.
//////GLuint vertexShader;// object
//////vertexShader = glCreateShader(GL_VERTEX_SHADER);
//////std::string vertShaderSrc = ShaderTechnique::buildShader("vertexshader.glsl")
//////glShaderSource(VertexShaderId, 1, &vertexShader, NULL);
//////glCompileShader(VertexShaderId);
//
//
//
////Here we are using the glShaderSource() function to load our shader source to memory.
////This function accepts an array of strings, so before we call glShaderSource(), 
////we create a pointer to the start of the shaderCode array object using a still - to - be - created method.
////The first argument to glShaderSource() is the handle to the shader object.
////The second is the number of source code strings that are contained in the array.The third argument is a pointer to an array of source code strings.
////The final argument is an array of GLint values that contains the length of each source code string in the previous argument.
//
//
////
////GLuint vertexShader1 = glCreateShader(GL_VERTEX_SHADER);
////GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(800, 800);
//	glutInitWindowPosition(100, 80);
//	glutCreateWindow("Project Rendering part 1 running");
//
//
//	initializeGlutCallbacks();
//
//	// Must be done after glut is initialized!
//	GLenum res = glewInit();
//	if (res != GLEW_OK)
//	{
//		cerr << "Error: " << glewGetErrorString(res) << "\n";
//		return 1;
//	}
//
//	//createShaders();
//	//shader1.buildShader("vertexshader.glsl", "fragmentshader.glsl");
//	//gameObject2.shader->buildShader("vertexShader2.glsl", "fragmentshader2.glsl");
//	//gameObject3.shader->buildShader("vertexShader3.glsl", "fragmentshader3.glsl");
//
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//	createGameObjects();
//	// pointer to object
//	
//
//	
//
//	glutMainLoop();
//
//	return 0;
//}
