#include "ClassA.h"

ClassA::ClassA()
{
	VBO = NULL;
	numOfVertices = 0;
	shader = NULL;
}

void ClassA::createVertexBuffer(vec3 vertices[], int numverts)
{
	numOfVertices = numverts;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * numOfVertices, vertices, GL_STATIC_DRAW);
}

void ClassA::render()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, numOfVertices);
	glDisableVertexAttribArray(0);
}
