#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

// Vertex Buffers
GLuint VBO;
GLuint VBO1;
GLuint VBO3;


// need to change if array increases
const int NUMVERTS = 3;  
const int NUMVERTS1 = 3;  


static void renderSceneCallBack()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Draw VBO
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glDrawArrays(GL_POINTS, 0, NUMVERTS);
    glDrawArrays(GL_TRIANGLES, 0, NUMVERTS1);
    glDisableVertexAttribArray(0); 
    
    // Draw VBO1
    //glEnableVertexAttribArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    ////glDrawArrays(GL_POINTS, 0, NUMVERTS1);  // drawing points
    //glDisableVertexAttribArray(0);
    glutSwapBuffers();
}

static void initializeGlutCallbacks()
{
    glutDisplayFunc(renderSceneCallBack);
}

static void createVertexBuffers()
{
    vec3 vertices[NUMVERTS];
    vertices[0] = vec3(-0.5f, -0.5f, 0.0f); // vertex 1 (point)
    vertices[1] = vec3(-0.5f, 0.5f, 0.0f); // vertex 2 (point)
    vertices[2] = vec3(0.5f, 0.5f, 0.0f); // vertex 3 (point)
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//The target GL_ARRAY_BUFFER means that the buffer will contain an array of vertices.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * NUMVERTS, vertices, GL_STATIC_DRAW);//After binding our object we fill it with data. 
}

static void createTriangle()
{

    vec3 vertices[NUMVERTS1];
    vertices[0] = vec3(-0.3f, -0.3f, 0.0f); // vertex 1 (point)
    vertices[1] = vec3(-0.3f, 0.3f, 0.0f); // vertex 2 (point)
    vertices[2] = vec3(0.3f, 0.3f, 0.0f); // vertex 3 (point)
    glGenBuffers(1, &VBO1);
    
    
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);//The target GL_ARRAY_BUFFER means that the buffer will contain an array of vertices.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * NUMVERTS1, vertices, GL_STATIC_DRAW);

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("First triangle");

    initializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) 
    {
		cerr<<"Error: "<<glewGetErrorString(res)<<"\n";
		return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

	/////////////    Create a vertex buffer
	createVertexBuffers();
   
    ///////////   draw line  ///////////
    createTriangle();

    glutMainLoop();
    
    return 0;
}