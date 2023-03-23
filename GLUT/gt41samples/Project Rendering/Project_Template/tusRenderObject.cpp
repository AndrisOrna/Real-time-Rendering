#include "tusRenderObject.h"

tusRenderObject::tusRenderObject()
{
	vbo = NULL;
	numOfVertices = 0;
	shader = NULL;
}

void tusRenderObject::createBuffer(VertexData vertices[], int numverts)
{
	cout << "Creating buffer...." << endl;
	numOfVertices = numverts;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * numOfVertices, vertices, GL_STATIC_DRAW);
}

void tusRenderObject::render()
{
	cout << "rendering...." << endl;
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 40, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 40, (const GLvoid*)12);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 40, (const GLvoid*)28);
	
	shader->useShader();

	glDrawArrays(GL_TRIANGLES, 0, numOfVertices);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void tusRenderObject::setShader(ShaderTechnique* s)
{
	shader = s;
}
