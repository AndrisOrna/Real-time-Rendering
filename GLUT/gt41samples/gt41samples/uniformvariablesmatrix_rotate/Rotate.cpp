//#include "ShaderTechnique.h"
//#include "GameObject.h"
//#include "../firstshaders/aiterror.h"
//#include "ShaderTechnique.h"
//using namespace ShaderTechnique2;

//using namespace glm;
// initialize some window properties
//unsigned int windowWidth = 800;
//unsigned int windowHeight = 500;
//unsigned int windowPos_X = 800;
//unsigned int windowPos_Y = 400;
//const char* windowTitle = "A00273758: Rendering Project - Part 1";

// some global GameObjects
//GameObject gameObject1;
//GameObject gameObject2;
//GameObject gameObject3;

//ShaderTechnique shader1;
//ShaderTechnique shader2;



//1.Create the shader objects in the main
//const GLchar* vert_shad = "vertexshader.glsl";
//const GLchar* frag_shad = "vertexshader.glsl";
//2.on these created objects you then build the shader


//3.then with these you then set the shader of each game object


//4.then you can render the objects to the screen

//ShaderTech2 main_shader(vert_shad, frag_shad);
//main_shader.use();

// The commented piece of code is the code that works for other GameObject class alternatives...
//1st is for Shader Instance...2nd line is for only inheritance
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
//}
//
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
//	gameObject3 = GameObject();
//	vec3 vert_gameObject3[numVerts];
//	vert_gameObject3[0] = vec3(-0.5f, -0.5f, 0.0f);
//	vert_gameObject3[1] = vec3(0.5f, -0.5f, 0.0f);
//	vert_gameObject3[2] = vec3(0.0f, -1.5f, 0.0f);
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
//GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

//CreateShaders();
//GLuint vert_shad, frag_shad;
//
//

//const char* vert_shader = "vertexshader.glsl";
//const char* frag_shader = "fragmentShader.glsl";
//
//vert_shad = glCreateShader(GL_VERTEX_SHADER);
//glShaderSource(vert_shad, 1, &vert_shad, NULL);
//glCompileShader(vert_shad);
//Check_Shaders_Program(vert_shad, "vertexshader.glsl");
//
//glDeleteShader(vert_shad); // Flag shader object for automatic deletion (freeing memory) when no longer attached to a program object...
//glDeleteShader(frag_shad); // ... program object is deleted (glDeleteProgram ) within: main() when the application ends.
////GLuint vertexShader;// object
////vertexShader = glCreateShader(GL_VERTEX_SHADER);
////std::string vertShaderSrc = ShaderTechnique::buildShader("vertexshader.glsl")
////glShaderSource(VertexShaderId, 1, &vertexShader, NULL);
////glCompileShader(VertexShaderId);



//Here we are using the glShaderSource() function to load our shader source to memory.
//This function accepts an array of strings, so before we call glShaderSource(), 
//we create a pointer to the start of the shaderCode array object using a still - to - be - created method.
//The first argument to glShaderSource() is the handle to the shader object.
//The second is the number of source code strings that are contained in the array.The third argument is a pointer to an array of source code strings.
//The final argument is an array of GLint values that contains the length of each source code string in the previous argument.


//
//GLuint vertexShader1 = glCreateShader(GL_VERTEX_SHADER);
//GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);


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
//	createGameObjects();
//	// pointer to object
//
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	glutMainLoop();
//
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <Windows.h>
//#include "aiterror.h"
//#define _USE_MATH_DEFINES 
//#include "GameObject.h"
//#include "Rendering_Project2.cpp"
////#include "../ProjectV4/Rendering_Project.cpp"
//
//GameObject obj;
//GameObject obj1;
//GameObject obj2;
//GameObject obj3;
////static int p = 6; // Number of grid columns.
////static int q = 4; // Number of grid rows
////static float* vertices = NULL;
////static float Xangle = 150.0, Yangle = 60.0, Zangle = 0.0; // Angles to rotate
//using namespace std;
//using namespace glm;
//
//GLuint VBO;
//GLuint VBO1;
//
//GLuint gTransformLocation;
////GLuint gScaleLocation;
//
//
//const int NUMVERTS = 3;
//
//// Our simple vertex container
//struct SimpleVertex
//{
//    vec3		pos;	// Position
//    vec4		colour;	// Colour
//};
//
//
//// Keyboard input processing routine.
////void keyInput(unsigned char key, int x, int y)
////{
////    switch (key)
////    {
////    case 27:
////        exit(0);
////        break;
////    case 'x':
////        Xangle += 5.0;
////        if (Xangle > 360.0) Xangle -= 360.0;
////        glutPostRedisplay();
////        break;
////    case 'X':
////        Xangle -= 5.0;
////        if (Xangle < 0.0) Xangle += 360.0;
////        glutPostRedisplay();
////        break;
////    case 'y':
////        Yangle += 5.0;
////        if (Yangle > 360.0) Yangle -= 360.0;
////        glutPostRedisplay();
////        break;
////    case 'Y':
////        Yangle -= 5.0;
////        if (Yangle < 0.0) Yangle += 360.0;
////        glutPostRedisplay();
////        break;
////    case 'z':
////        Zangle += 5.0;
////        if (Zangle > 360.0) Zangle -= 360.0;
////        glutPostRedisplay();
////        break;
////    case 'Z':
////        Zangle -= 5.0;
////        if (Zangle < 0.0) Zangle += 360.0;
////        glutPostRedisplay();
////        break;
////    default:
////        break;
////    }
////}
//
//// Callback routine for non-ASCII key entry.
////void specialKeyInput(int key, int x, int y)
////{
////    if (key == GLUT_KEY_LEFT) if (p > 3) p -= 1;
////    if (key == GLUT_KEY_RIGHT) p += 1;
////    if (key == GLUT_KEY_DOWN) if (q > 3) q -= 1;
////    if (key == GLUT_KEY_UP) q += 1;
////
////    glutPostRedisplay();
////}
////GameObject::GameObject()
////{
////
////}
////GameObject::GameObject(GLuint drawmode)
////{
////    mode = drawmode;
////}
//static void renderSceneCallBack()
//{
//    /*int  i, j;
//    vertices = new float[3 * (p + 1) * (q + 1)];*/
//    /*static float Scale = 0.0f;
//    static float Delta = 0.005f;
//
//    Scale += Delta;
//    if ((Scale >= 1.0f) || (Scale <= -1.0f))
//    {
//        Delta *= -1.0f;
//    }
//    glUniform1f(gScaleLocation, Scale);*/
//
//    //glVertexPointer(3, GL_FLOAT, 0, vertices);
//    glClear(GL_COLOR_BUFFER_BIT);
//    obj.render();
//    //glLoadIdentity();
//    //gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    //glColor3f(0.0, 0.0, 0.0);
//
//    //// Rotate scene.
//    //glRotatef(Zangle, 0.0, 0.0, 1.0);
//    //glRotatef(Yangle, 0.0, 1.0, 0.0);
//    //glRotatef(Xangle, 1.0, 0.0, 0.0);
//
//    // Update the gTransform variable in the Vertex Shade on the GPU
//    //mat4 transform = mat4(1.0f);
//    mat4 action = mat4(1.0f);
//
//    
//
//    ////// ROTATE  ///////////
//    //////////////////// ROTATION  ACTION ////////////////
//    mat4 rotate1 = mat4(1.0f);
//
//    mat4 rotate_Y_axis = mat4(1.0f);
//    mat4 rotate_X_axis = mat4(1.0f);
//    mat4 rotate_Z_axis = mat4(1.0f);
//
//    static float roty = 0.0f;
//    roty += 1.5f;  // SPEED
//    rotate_X_axis = rotate(mat4(1.0f), roty, vec3(0.9f, 0.0f, 0.0f)); // edit rotation X axis
//    rotate_Y_axis = rotate(mat4(1.0f), roty, vec3(0.0f, 1.0f, 0.0f)); // edit rotation Y axis
//    rotate_Z_axis = rotate(mat4(1.0f), roty, vec3(0.0f, 0.0f, 1.0f)); // edit rotation Z axis
//    mat4 rot = mat4(1.0f);
//
//
//
//    //////    SCALE SECTION  ///////
//    /////  TRANSLATE  /////
//    
//    mat4 translate1 = mat4(1.0f);
//    mat4 scale1 = mat4(0.5f);
//
//    static float deltax = 0.0f;
//    //mat4 sca = mat4(1.0f);
//    deltax += 0.005f;
//    scale1 = scale(mat4(1.0f), vec3(0.9f, 0.9f, 1.0f));// scaling
//    translate1 = translate(mat4(1.0f), vec3(deltax, 0.0f, 0.5f));// moving 
//
//    
//    
//
//    //////   ACTION   /////////
//    //action = scale1;
//    action = rotate_X_axis * scale1;
//    //action = rotate_Y_axis;
//    //action = translate1;
//    //action = rotate_Y_axis* translate1;
//
//
//    //transform = scale(mat4(1.0f), vec3(0.9f, 0.5f, 1.0f));
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0])
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &action[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0]);
//
//
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_X_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_Y_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_Z_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0]);
//    //rotate_X_axis = rotate_X_axis;
//    glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &action[0][0]);
//    glEnableVertexAttribArray(0);
//    glEnableVertexAttribArray(1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
//    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
//
//    glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
//
//    glDisableVertexAttribArray(0);
//    glDisableVertexAttribArray(1);
//
//    glutSwapBuffers();
//}
//
//static void initializeGlutCallbacks()
//{
//    glutDisplayFunc(renderSceneCallBack);
//    glutIdleFunc(renderSceneCallBack);
//}
//
////void GameObject::createBuffer(vec3 vertices[], int numverts)
////{
////    numOfVertices = numverts;
////    glGenBuffers(1, &vbo);
////    glBindBuffer(GL_ARRAY_BUFFER, vbo);
////    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * numOfVertices, vertices, GL_STATIC_DRAW);
//
//    // Create some vertices to put in our VBO.
//    // Create vertex buffer
//    //SimpleVertex vertices[] =
//    //{
//    //    {vec3(-0.1f, -0.1f, 0.0f), vec4(1.0f, 1.0f, 0.0f, 1.0f)},// vec 3 location 
//    //    {vec3(0.1f, -0.1f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},// vec4 colour
//    //    {vec3(0.0f, 0.1f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
//    //};
//
//    //vec2 offset(0.0f, 0.0f);
//    //glUniform2fv(gTransformLocation, 1, &offset[0]);
//    //glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
//
//    /*SimpleVertex vertices2[] =
//    {
//        {vec3(-0.5f, -0.5f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
//        {vec3(0.5f, -0.5f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
//        {vec3(0.0f, 0.5f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
//    };
//
//    glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * 3, vertices, GL_STATIC_DRAW);*/
//    /*glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * 3, vertices2, GL_STATIC_DRAW);*/
////}
////void Objects::render()
////{
////    glEnableVertexAttribArray(0);
////    glBindBuffer(GL_ARRAY_BUFFER, vbo);
////    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
////    glDrawArrays(mode, 0, numOfVertices);
////    glDisableVertexAttribArray(0);
////}
////
////static void CreateObjects()
////{
////    
////    
////    //create some vertices and put it in our VBO
////    /*obj = Objects(GL_TRIANGLES);
////    const int numVerts = 3;
////    vec3 vertices1[numVerts];
////    vertices1[0] = vec3(0.0f, 0.0f, 0.0f);
////    vertices1[1] = vec3(0.2f, 0.1f, 0.0f);
////    vertices1[2] = vec3(0.2f, 0.0f, 0.0f);
////    obj.createBuffer(vertices1, numVerts);*/
////
////    obj1 = GameObject(GL_TRIANGLES);
////    const int numVerts2 = 3;
////    vec3 vertices2[numVerts2];
////    vertices2[0] = vec3(-0.2f, -0.2f, 0.0f);
////    vertices2[1] = vec3(0.2f, -0.2f, 0.0f);
////    vertices2[2] = vec3(0.0f, -0.2f, 0.0f);
////    obj1.createVertexBuffer(vertices2, numVerts2);
////
////
////    /////  OBJECT2  ////
////    /*obj2 = Objects(GL_TRIANGLES);
////    const int numVerts3 = 3;
////    vec3 vertices3[numVerts3];
////    vertices3[0] = vec3(-0.2f, -0.2f, 0.0f);
////    vertices3[1] = vec3(0.2f, -0.2f, 0.0f);
////    vertices3[2] = vec3(0.0f, -0.2f, 0.0f);
////    obj2.createBuffer(vertices3, numVerts3);*/
////
////    
////    SimpleVertex vertices[] =
////    {
////        {vec3(-0.1f, -0.1f, 0.0f), vec4(1.0f, 1.0f, 0.0f, 1.0f)},// vec 3 location 
////        {vec3(0.1f, -0.1f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},// vec4 colour
////        {vec3(0.0f, 0.1f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
////    };
////   
////}
//static void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
//{
//    GLuint shaderObj = glCreateShader(shaderType);
//
//    if (shaderObj == 0)
//    {
//        std::stringstream ss;
//        ss << "Error creating shader type " << shaderType << endl;
//        AIT_ASSERT(0, ss.str());
//    }
//
//    const GLchar* p[1];
//    p[0] = pShaderText;
//    GLint Lengths[1];
//    Lengths[0] = strlen(pShaderText);
//    glShaderSource(shaderObj, 1, p, Lengths);
//    glCompileShader(shaderObj);
//    GLint success;
//    glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        GLchar InfoLog[1024];
//        glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
//        std::stringstream ss;
//        ss << "Error compiling shader type " << shaderType << ": " << InfoLog << endl;
//        AIT_ASSERT(0, ss.str());
//    }
//
//    glAttachShader(shaderProgram, shaderObj);
//}
//
//const string readFileToString(char* filename)
//{
//    ifstream file(filename, ios::in);
//    if (file.is_open())
//    {
//        stringstream continut;
//        continut << file.rdbuf();
//        continut << '\0';
//        return continut.str();
//    }
//    AIT_ASSERT(0, "File not found!");
//}
//
//static void buildShaders()
//{
//    GLuint shaderProgram = glCreateProgram();
//
//    if (shaderProgram == 0)
//    {
//        AIT_ASSERT(0, "Error creating shader program\n");
//    }
//
//    string VS = readFileToString("vertexShader.glsl");
//    string FS = readFileToString("fragmentShader.glsl");
//
//    addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
//    addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);
//
//    GLint success = 0;
//    GLchar errorLog[1024] = { 0 };
//
//    glLinkProgram(shaderProgram);
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (success == 0)
//    {
//        glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//        std::stringstream ss;
//        ss << "Error linking shader program: " << errorLog << endl;
//        AIT_ASSERT(0, ss.str());
//    }
//
//    glValidateProgram(shaderProgram);
//    glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
//    if (!success)
//    {
//        glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//        cerr << "Error linking shader program: " << errorLog << endl;
//        std::stringstream ss;
//        ss << "Error linking shader program: " << errorLog << endl;
//        AIT_ASSERT(0, ss.str());
//    }
//
//    glUseProgram(shaderProgram);
//
//    gTransformLocation = glGetUniformLocation(shaderProgram, "gTransform");
//    assert(gTransformLocation != 0xFFFFFFFF);
//
//    //gScaleLocation = glGetUniformLocation(shaderProgram, "gScale");
//    //assert(gScaleLocation != 0xFFFFFFFF);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(1024, 768);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Uniform Variables");
//
//    initializeGlutCallbacks();
//
//    // Must be done after glut is initialized!
//    GLenum res = glewInit();
//    if (res != GLEW_OK)
//    {
//        cerr << "Error: " << glewGetErrorString(res) << "\n";
//        return 1;
//    }
//
//    buildShaders();
//
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    
//    // Create a vertex buffer
//    createGameObjects();
//
//    glutMainLoop();
//
//    return 0;
//}