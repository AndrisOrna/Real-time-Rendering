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
//
//static int p = 6; // Number of grid columns.
//static int q = 4; // Number of grid rows
//static float* vertices = NULL;
//static float Xangle = 150.0, Yangle = 60.0, Zangle = 0.0; // Angles to rotate
//using namespace std;
//using namespace glm;
//
//GLuint VBO;
////GLuint VBO1;
//
//GLuint gTransformLocation;
//
//const int NUMVERTS = 3;
//
//// Our simple vertex container
//struct SimpleVertex
//{
//    vec3		pos;	// Position
//	vec4		colour;	// Colour
//};
//
//
//// Keyboard input processing routine.
//void keyInput(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 27:
//        exit(0);
//        break;
//    case 'x':
//        Xangle += 5.0;
//        if (Xangle > 360.0) Xangle -= 360.0;
//        glutPostRedisplay();
//        break;
//    case 'X':
//        Xangle -= 5.0;
//        if (Xangle < 0.0) Xangle += 360.0;
//        glutPostRedisplay();
//        break;
//    case 'y':
//        Yangle += 5.0;
//        if (Yangle > 360.0) Yangle -= 360.0;
//        glutPostRedisplay();
//        break;
//    case 'Y':
//        Yangle -= 5.0;
//        if (Yangle < 0.0) Yangle += 360.0;
//        glutPostRedisplay();
//        break;
//    case 'z':
//        Zangle += 5.0;
//        if (Zangle > 360.0) Zangle -= 360.0;
//        glutPostRedisplay();
//        break;
//    case 'Z':
//        Zangle -= 5.0;
//        if (Zangle < 0.0) Zangle += 360.0;
//        glutPostRedisplay();
//        break;
//    default:
//        break;
//    }
//}
//
//// Callback routine for non-ASCII key entry.
//void specialKeyInput(int key, int x, int y)
//{
//    if (key == GLUT_KEY_LEFT) if (p > 3) p -= 1;
//    if (key == GLUT_KEY_RIGHT) p += 1;
//    if (key == GLUT_KEY_DOWN) if (q > 3) q -= 1;
//    if (key == GLUT_KEY_UP) q += 1;
//
//    glutPostRedisplay();
//}
//static void renderSceneCallBack()
//{
//    int  i, j;
//    vertices = new float[3 * (p + 1) * (q + 1)];
//
//    glVertexPointer(3, GL_FLOAT, 0, vertices);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    glColor3f(0.0, 0.0, 0.0);
//
//    // Rotate scene.
//    glRotatef(Zangle, 0.0, 0.0, 1.0);
//    glRotatef(Yangle, 0.0, 1.0, 0.0);
//    glRotatef(Xangle, 1.0, 0.0, 0.0);
//
//    // Update the gTransform variable in the Vertex Shade on the GPU
//    mat4 action = mat4(1.0f);
//    mat4 transform = mat4(1.0f);
//    mat4 rotate_Y_axis = mat4(1.0f);
//    mat4 rotate_X_axis = mat4(1.0f);
//    mat4 rotate_Z_axis = mat4(1.0f);
//    mat4 rot = mat4(1.0f);
//    //mat4 scale = mat4(0.5f);
//    mat4 sca = mat4(1.0f);
//    
//    static float deltax = 0.0f;
//    deltax += 0.005f;
//    transform = translate(mat4(1.0f), vec3(deltax, 0.0f, 0.0f));
//    sca = scale(mat4(1.0f), vec3(0.5f, 0.5f, 1.0f));
//    //transform = sca;
//    //transform = sca * rot * trans;
//    //transform = rot * sca * trans;
//    //transform = rot * sca;
//    //action = rot;   // only rotating
//
//    //transform = scale(mat4(1.0f), vec3(0.9f, 0.5f, 1.0f));
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0])
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &action[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0]);
//    
//    //////////////////// ROTATION  ACTION ////////////////
//    static float roty = 0.0f;
//    roty += 1.0f;  // SPEED
//    rotate_X_axis = rotate(mat4(1.0f), roty, vec3(0.9f, 0.0f, 0.0f)); // edit rotation X axis
//    rotate_Y_axis = rotate(mat4(1.0f), roty, vec3(0.0f, 1.0f, 0.0f)); // edit rotation Y axis
//    rotate_Z_axis = rotate(mat4(1.0f), roty, vec3(0.0f, 0.0f, 1.0f)); // edit rotation Z axis
//
//    glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_X_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_Y_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &rotate_Z_axis[0][0]);
//    //glUniformMatrix4fv(gTransformLocation, 1, GL_FALSE, &trans[0][0]);
//
//    glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (const GLvoid*)12);
//
//    glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
//
//    glDisableVertexAttribArray(0);
//	glDisableVertexAttribArray(1);
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
//static void createVertexBuffer()
//{
//	// Create some vertices to put in our VBO.
//	// Create vertex buffer
//	SimpleVertex vertices[] =
//	{
//		{vec3(-0.1f, -0.1f, 0.0f), vec4(1.0f, 1.0f, 0.0f, 1.0f)},// vec 3 location 
//		{vec3(0.1f, -0.1f, 0.0f),  vec4(1.0f, 1.0f, 0.0f, 1.0f)},// vec4 colour
//		{vec3( 0.0f, 0.1f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
//	};
//
//    /*SimpleVertex vertices2[] =
//    {
//        {vec3(-0.9f, -0.5f, 0.0f), vec4(1.0f, 0.0f, 0.0f, 1.0f)},
//        {vec3(0.5f, -0.5f, 0.0f),  vec4(0.0f, 1.0f, 0.0f, 1.0f)},
//        {vec3(0.0f, 0.5f, 0.0f),  vec4(0.0f, 0.0f, 1.0f, 1.0f)}
//    };*/
//    
// 	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * 3, vertices, GL_STATIC_DRAW);
//
//    /*glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(SimpleVertex) * 3, vertices2, GL_STATIC_DRAW);*/
//}
//
//static void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
//{
//    GLuint shaderObj = glCreateShader(shaderType);
//
//	if (shaderObj == 0) 
//	{
//		std::stringstream ss;
//		ss<<"Error creating shader type "<<shaderType<<endl;
//		AIT_ASSERT(0, ss.str());
//    }
//
//    const GLchar* p[1];
//    p[0] = pShaderText;
//    GLint Lengths[1];
//    Lengths[0]= strlen(pShaderText);
//    glShaderSource(shaderObj, 1, p, Lengths);
//    glCompileShader(shaderObj);
//    GLint success;
//    glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
//    if (!success) 
//	{
//        GLchar InfoLog[1024];
//        glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
//		std::stringstream ss;
//		ss <<"Error compiling shader type "<<shaderType<<": "<<InfoLog<<endl;
//		AIT_ASSERT(0, ss.str());
//    }
//
//    glAttachShader(shaderProgram, shaderObj);
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
//	AIT_ASSERT(0, "File not found!");
//}
//
//static void buildShaders()
//{
//    GLuint shaderProgram = glCreateProgram();
//
//    if (shaderProgram == 0) 
//	{
//		AIT_ASSERT(0, "Error creating shader program\n");
//    }
//
//	string VS = readFileToString("vertexShader.glsl");
//	string FS = readFileToString("fragmentShader.glsl");
//
//    addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
//    addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);
//
//    GLint success = 0;
//    GLchar errorLog[1024] = { 0 };
//
//    glLinkProgram(shaderProgram);
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
// 	if (success == 0) 
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		std::stringstream ss;
//		ss<<"Error linking shader program: "<<errorLog<<endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//    glValidateProgram(shaderProgram);
//    glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
//    if (!success) 
//	{
//        glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//        cerr<<"Error linking shader program: "<<errorLog<<endl;
//        std::stringstream ss;
//		ss<<"Error linking shader program: "<<errorLog<<endl;
//		AIT_ASSERT(0, ss.str());
//    }
//
//    glUseProgram(shaderProgram);
//
//    gTransformLocation = glGetUniformLocation(shaderProgram, "gTransform");
//    assert(gTransformLocation != 0xFFFFFFFF);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
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
//		cerr<<"Error: "<<glewGetErrorString(res)<<"\n";
//		return 1;
//    }
//
//	buildShaders();
//
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
//
//	// Create a vertex buffer
//	createVertexBuffer();
//
//    glutMainLoop();
//    
//    return 0;
//}