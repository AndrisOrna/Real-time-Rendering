//#include "GameObject.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <Windows.h>
//#include "aiterror.h"
//
////using namespace std;
////using namespace glm;
////
//const int windowWidth = 1024;
//const int windowHeight = 768;
////
//GLuint gModelToWorldTransformLocation;
//GLuint gWorldToViewTransformLocation;
//GLuint gProjectionTransformLocation;
//
//
//GameObject::GameObject()
//{
//	VBO = NULL;
//	numOfVertices = 0;
//
//	objectDetails.shader = NULL;
//}
//
//void GameObject::createVertexBuffer(GameObjectDetails vertices[], int numverts)
//{
//	cout << "Creating VBO..." << endl;
//
//	numOfVertices = numverts;
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(GameObjectDetails) * numOfVertices, vertices, GL_STATIC_DRAW);
//}
//void GameObject::createVertexBuffer(vec3 vertices[], int numverts)
//{
//	numOfVertices = numverts;
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * numOfVertices, vertices, GL_STATIC_DRAW);
//}
//void GameObject::setShader(ShaderTechnique* s)
//{
//	cout << "Setting Shader..." << endl;
//
//	objectDetails.shader = s;
//}
//void GameObject::render()
//{
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//	//glClear(GL_COLOR_BUFFER_BIT);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), 0);
//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), (const GLvoid*)12);
//
//	//GameObjectDetails.shader->useThisShader();
//	//cout << "Rendering Object..." << endl;
//	//glEnableVertexAttribArray(0);
//	//glEnableVertexAttribArray(1);
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GameObjectDetails), 0);
//	//objectDetails.shader->useThisShader();
//	//glDrawArrays(GL_TRIANGLES, 0, numOfVertices);
//	//glDisableVertexAttribArray(0);
//	//glDisableVertexAttribArray(1);
//	
//}
//void GameObject::settingTranslation(float translateX, float translateY, float translateZ)
//{
//	//translating = translate(mat4(1.0f), vec3(translateX, translateY, translateZ));
//}
//
