#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "tusrenderobj.h"

using namespace std;
using namespace glm;

tusRenderObj obja;
tusRenderObj objb;
tusRenderObj objTriangle;

const int NUMVERTS1 = 3;
GLuint VBO1;



static void renderSceneCallBack()
{
    glClear(GL_COLOR_BUFFER_BIT);
    obja.render();
    objb.render();
    objTriangle.render();
    glutSwapBuffers();
}

static void initializeGlutCallbacks()
{
    glutDisplayFunc(renderSceneCallBack);
}

static void createTusRenderObjs()
{
	// Create some vertices to put in our VBO.
    const int nv1 = 2;
	vec3 vertices[nv1];
    vertices[0] = vec3(-0.5f, -0.5f, 0.0f);
    vertices[1] = vec3(-0.5f, 0.5f, 0.0f);
    obja.createBuffer(vertices, nv1);

    // Create some vertices to put in our VBO.
    const int nv2 = 2;
    vec3 vertices2[nv2];
    vertices2[0] = vec3(0.5f, -0.5f, 0.0f);
    vertices2[1] = vec3(0.5f, 0.5f, 0.0f);
    objb.createBuffer(vertices2, nv2);

    // Create triangle
    /*const int nv3 = 3;
    vec3 vertices3[nv3];
    vertices3[0] = vec3(0.5f, -0.5f, 0.0f);
    vertices3[1] = vec3(0.5f, 0.5f, 0.0f);
    vertices3[3] = vec3(-0.5f, 0.5f, -0.5f);
    objTriangle.createBuffer(vertices2, nv2);*/


}


//static void createTriangle()
//{
//
//    vec3 vertices[NUMVERTS1];
//    vertices[0] = vec3(-0.2f, -0.2f, 0.0f); // vertex 1 (point)
//    vertices[1] = vec3(-0.2f, 0.2f, 0.0f); // vertex 2 (point)
//    vertices[2] = vec3(0.2f, 0.2f, 0.0f); // vertex 3 (point)
//    glGenBuffers(1, &VBO1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO1);//The target GL_ARRAY_BUFFER means that the buffer will contain an array of vertices.
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * NUMVERTS1, vertices, GL_STATIC_DRAW);
//
//}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Project");

    initializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) 
    {
		cerr<<"Error: "<<glewGetErrorString(res)<<"\n";
		return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

	// Create a vertex buffer
	createTusRenderObjs();
    //createTriangle();
    glutMainLoop();
    
    return 0;
}