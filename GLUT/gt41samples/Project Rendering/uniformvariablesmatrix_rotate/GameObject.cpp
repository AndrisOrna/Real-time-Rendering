#include "GameObject.h"
GameObject::GameObject()
{
	VBO = NULL;
	numOfVertices = 0;

	objectDetails.shader = NULL;
}

void GameObject::createVertexBuffer(GameObjectDetails vertices[], int numverts)
{
	cout << "Creating VBO..." << endl;

	numOfVertices = numverts;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * numOfVertices, vertices, GL_STATIC_DRAW);
}

void GameObject::render()
{
	cout << "Rendering Object..." << endl;
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, numOfVertices);
	glDisableVertexAttribArray(0);
	
}

void GameObject::setShader(ShaderTechnique* s)
{
	cout << "Setting Shader..." << endl;

	objectDetails.shader = s;
}