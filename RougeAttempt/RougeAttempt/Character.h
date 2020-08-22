#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "Shader.h"

class Character
{
public:
	~Character();
	Character(const char* texturePath, const char* vertShaderPath, const char* fragShaderPath);
	void draw();

private:
	unsigned int VAO, texture;
	Shader* shader;
};

