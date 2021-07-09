#include <iostream>
#include "Shader.h"

unsigned int CompileShader(unsigned int type, const char *source)
{
	unsigned int ID = glCreateShader(type);
	glShaderSource(ID, 1, &source, NULL);
	glCompileShader(ID);

	int result;
	char infoLog[512];
	glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		std::cout << "SHADER::FRAGMENT::COMPILATION::FAILED" << infoLog << std::endl;

		return 0;
	}

	return ID;
}

unsigned int CreateShader(const char *vSS, const char *fSS)
{
	unsigned int shader = glCreateProgram();
	unsigned int vS = CompileShader(GL_VERTEX_SHADER, vSS);
	unsigned int fS = CompileShader(GL_FRAGMENT_SHADER, fSS);
	glAttachShader(shader, vS);
	glAttachShader(shader, fS);
	glLinkProgram(shader);

	int result;
	char infoLog[512];
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, 512, NULL, infoLog);
		std::cout << "SHADER::PROGRAM::LINKING::FAILED" << infoLog << std::endl;

		return 0;
	}
	glDeleteShader(vS);
	glDeleteShader(fS);

	return shader;
}

Shader::Shader()
{
	const char *dVSS =
			"#version 330 core\n"
			"\n"
			"layout (location = 0) in vec3 aPos;\n"
			"\n"
			"uniform mat4 proj;\n"
			"uniform mat4 view;\n"
			"uniform mat4 model;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	gl_Position = proj * view * model * vec4(aPos, 1.0);\n"
			"};\n\0";

	const char *dFSS =
			"#version 330 core\n"
			"\n"
			"layout (location = 0) out vec4 color;\n"
			"\n"
			"uniform vec4 uColor;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	color = uColor;\n"
			"};\n\0";

	ID = CreateShader(dVSS, dFSS);
	this->Use();
}

Shader::Shader(const char *vSS, const char *fSS)
{
	ID = CreateShader(vSS, fSS);
	this->Use();
}

void Shader::Use() const
{
	glUseProgram(ID);
}

void Shader::Disuse() const
{
	glUseProgram(0);
}

void Shader::setMat4(glm::mat4 mat, const std::string &matName)
{
	this->Use();
	unsigned int location = glGetUniformLocation(ID, matName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setVec4(float v1, float v2, float v3, float v4, const std::string &locName)
{
	this->Use();
	int location = glGetUniformLocation(ID, locName.c_str());
	if (location == -1)
	{
		std::cout << "Warning: uniform " << locName << " doesn't exist!" << std::endl;
	}
	glUniform4f(location, v1, v2, v3, v4);
}

Shader::~Shader()
{
	delete &ID;
}
