#include "ShaderTechnique.h"
//GLuint gTransformLocation;
GLuint gTransformLocation;
GLuint gWorldToViewTransformLocation;
GLuint gProjectionTransformLocation;

ShaderTechnique::ShaderTechnique()
{

}

string ShaderTechnique::readShaderFile(string fileName)
{
	ifstream file(fileName, ios::in);
	if (file.is_open())
	{
		stringstream continut;
		continut << file.rdbuf();
		continut << '\0';
		return continut.str();
	}
	return "";
}

void ShaderTechnique::addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
{
	GLuint shaderObj = glCreateShader(shaderType);

	if (shaderObj == 0)
	{
		std::stringstream ss;
		ss << "Error creating shader type " << shaderType << endl;
		AIT_ASSERT(0, ss.str());
	}

	const GLchar* p[1];
	p[0] = pShaderText;
	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);
	glShaderSource(shaderObj, 1, p, Lengths);
	glCompileShader(shaderObj);
	GLint success;
	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
		std::stringstream ss;
		ss << "Error compiling shader type " << shaderType << ": " << InfoLog << endl;
		AIT_ASSERT(0, ss.str());
	}

	glAttachShader(shaderProgram, shaderObj);

}

void ShaderTechnique::buildShader(string vertexShaderPath, string fragmentShaderPath)
{
	shaderProgram = glCreateProgram();

	if (shaderProgram == 0)
	{
		AIT_ASSERT(0, "Error creating shader program\n");
	}

	string VS = readShaderFile(vertexShaderPath);
	string FS = readShaderFile(fragmentShaderPath);

	addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
	addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);

	GLint success = 0;
	GLchar errorLog[1024] = { 0 };

	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (success == 0)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
		std::stringstream ss;
		ss << "Error linking shader program: " << errorLog << endl;
		AIT_ASSERT(0, ss.str());
	}

	glValidateProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
		cerr << "Error linking shader program: " << errorLog << endl;
		std::stringstream ss;
		ss << "Error linking shader program: " << errorLog << endl;
		AIT_ASSERT(0, ss.str());
	}
	cout << "building shader...." << endl;
}

void ShaderTechnique::useShader()
{
	cout << "using shader...." << endl;
	glUseProgram(shaderProgram);

	gTransformLocation = glGetUniformLocation(shaderProgram, "gModelToWorldTransform");
	assert(gTransformLocation != 0xFFFFFFFF);
	gWorldToViewTransformLocation = glGetUniformLocation(shaderProgram, "gWorldToViewTransform");
	assert(gWorldToViewTransformLocation != 0xFFFFFFFF);
	gProjectionTransformLocation = glGetUniformLocation(shaderProgram, "gProjectionTransform");
	assert(gProjectionTransformLocation != 0xFFFFFFFF);
}

void ShaderTechnique::updateShader(mat4 worldToViewTransform, mat4 projectionTransform)
{
	// Update the transforms in the shader program on the GPU
	glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
	glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);
}

GLuint ShaderTechnique::getShaderProgram()
{
	return shaderProgram;
}
//void ShaderTechnique::rotate() {
	// Create a new model to world transform
	//mat4 scalem = mat4(1.0f);
	//scalem = scale(scalem, vec3(0.5f, 0.5f, 0.5f));
	// Update the transforms in the shader program on the GPU
	// Create our world space to view space transformation matrix


	//glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
	//glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);

	//static float angle = 0.2f;
	//angle += 1.0f;
	//mat4 rot = mat4(1.0f);
	//rot = rotate(rot, angle, vec3(0.0f, 1.0f, 0.0f));


	/*static float y = 0.0f;
	y += 0.01f;
	mat4 trans = mat4(1.0f);
	trans = translate(trans, vec3(0.0f, y, 0.0f));*/

	//mat4 modelToWorldTransform = trans * rot * scalem;
	//mat4 modelToWorldTransform = rot;

	//glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);
//}