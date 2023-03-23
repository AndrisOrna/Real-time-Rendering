//#//pragma once
//#include "ShaderTechnique.h"
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
//GLuint VBO;
//const int NUMVERTS = 3;
//
//struct GameObjectDetails
//{
//	vec3 position;
//	vec4 color;
//	vec3 normal;
//	//c3 normal;
//	// and last add shader forgot to put
//	ShaderTechnique* shader;
//};
//class GameObject
//{
//private:
//	//GLuint VBO;
//	GLuint numOfVertices;
//	//ShaderTechnique* shader;
//
//	GameObjectDetails objectDetails;
//	mat4 scalling = mat4(1.0f);
//	mat4 rotating = mat4(1.0f);
//	mat4 translating = mat4(1.0f);
//
//public: // forgot to mention that it is public, will not work in project4.cpp
//	/*GLuint VBO;
//	GLuint numOfVertices;*/
//
//	//ShaderTechnique* shader;
//	GLuint gModelToWorldTransformLocation;
//
//	GameObject();
//
//	void createVertexBuffer(GameObjectDetails vertices[], int numverts);
//	void createVertexBuffer(vec3 vertices[], int numverts);
//	void setShader(ShaderTechnique* s);
//	void settingTranslation(float tranlateX, float translateY, float translateZ);
//	void settingScaling(float scaleX, float scaleY, float scaleZ);
//	//void settingRotation(float rotateX, float rotateY, float roataeZ, float angle);
//	
//	void settingRotation() {
//		static float angle = 0.0f;
//		angle += 1.0f;
//		mat4 rot = mat4(1.0f);
//		rot = rotate(rot, angle, vec3(0.0f, 1.0f, 0.0f));
//		mat4 modelToWorldTransform = rot;
//
//		glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);
//		//glDrawArrays(GL_TRIANGLES, 0, numverts);
//		//glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
//
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//
//		glutSwapBuffers();
//	}
//	void SettingTransform();
//	void applyingTransform();
//	void render();
//
//
//};
//
////static void renderSceneCallBack()
////{
////	glClear(GL_COLOR_BUFFER_BIT);
////
////	glEnableVertexAttribArray(0);
////	glEnableVertexAttribArray(1);
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 28, 0);
////	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 28, (const GLvoid*)12);
////
////	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
////
////	glDisableVertexAttribArray(0);
////	glDisableVertexAttribArray(1);
////
////	glutSwapBuffers();
////}
//
////static void initializeGlutCallbacks()
////{
////	glutDisplayFunc(renderSceneCallBack);
////}
//
////static void createVertexBuffer()
////{
////	// Create some vertices to put in our VBO.
////	// Create vertex buffer
////	GameObjectDetails vertices[] =
////	{
////		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)},
////		{glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)},
////		{glm::vec3(0.0f, 0.5f, 0.0f),  glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)}
////	};
////
////	glGenBuffers(1, &VBO);
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(GameObjectDetails) * 3, vertices, GL_STATIC_DRAW);
////}