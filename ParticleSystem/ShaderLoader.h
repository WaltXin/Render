#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <GL/glew.h>
#include <iostream>


// Assimp includes

#include <assimp/cimport.h> // C importer
#include <assimp/scene.h> // collects data
#include <assimp/postprocess.h> // various extra operations
#include <stdio.h>
#include <math.h>
#include <vector> // STL dynamic memory.
#include <string>

#include<glm-0.9.4.0\glm\glm.hpp>
#include <glm-0.9.4.0\glm\gtc\matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm-0.9.4.0\glm\gtc\type_ptr.hpp> // glm::value_ptr
#include <string>

using namespace std;

class Shaders
{
public:

	const char* vertex_shader;
	const char* fragment_shader;
	GLuint id;
	string name;

	char* readShaderSource(const char* shaderFile);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	void CompileShaders();
	void CompileShaders(string _name, const char* vertex, const char* fragment);

	Shaders();
	Shaders(string _name, const char* vertex, const char* fragment);
};