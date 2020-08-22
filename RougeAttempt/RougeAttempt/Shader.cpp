#include "Shader.h"

Shader::Shader(const char* vPath, const char* fPath)
{
	std::stringstream vStream, fStream;

	vShaderFile.open(vPath);
	fShaderFile.open(fPath);

	vStream << vShaderFile.rdbuf();
	fStream << fShaderFile.rdbuf();

	vShaderFile.close();
	fShaderFile.close();

	vertCode = vStream.str();
	fragCode = fStream.str();

	unsigned int vertex, fragment;
	const char* vShaderCode = vertCode.c_str();
	const char* fShaderCode = fragCode.c_str();

	std::cout << vShaderCode << std::endl;
	std::cout << "\n" << fShaderCode << std::endl;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(vertex, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(vertex, "PROGRAM");
	
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
}

void Shader::checkCompileErrors(unsigned int shader, std::string type) //Copied from learnopengl.
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

void Shader::Use()
{
	glUseProgram(ID);
}
