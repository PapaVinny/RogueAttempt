#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
public:
	unsigned int ID;
	Shader(const char* vPath, const char* fPath);
	~Shader();
	void checkCompileErrors(unsigned int shader, std::string type);
	void Use();

private:
	std::string vertCode, fragCode;
	std::ifstream vShaderFile, fShaderFile;
};

