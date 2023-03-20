#pragma once
#include "ShaderTechnique.h"


struct GameObjectDetails
{
	vec3 position;
	vec4 color;
	//vec3 normal;
	//c3 normal;
	// and last add shader forgot to put
	ShaderTechnique* shader;
};
class GameObject
{
public: // forgot to mention that it is public, will not work in project4.cpp
	/*GLuint VBO;
	GLuint numOfVertices;*/

	//ShaderTechnique* shader;

	GameObject();

	void createVertexBuffer(GameObjectDetails vertices[], int numverts);
	void render();
	void setShader(ShaderTechnique* s);
	void settingTranslation(float tranlateX, float translateY, float translateZ);
	void settingScaling(float scaleX, float scaleY, float scaleZ);
	void settingRotation(float rotateX, float rotateY, float roataeZ, float angle);
	void SettingTransform();
	void applyingTransform();
	
private :
	GLuint VBO;
	GLuint numOfVertices;
	GameObjectDetails objectDetails;
	mat4 scalling = mat4(1.0f);
	mat4 rotating = mat4(1.0f);
	mat4 translating = mat4(1.0f);

};