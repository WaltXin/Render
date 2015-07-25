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
#include <glm-0.9.4.0\glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm-0.9.4.0\glm/gtc/type_ptr.hpp> // glm::value_ptr
#include<ShaderLoader.h>

class ShaderManager
{
public:

	std::vector<Shaders> shaders;
	int num_shaders;
	int current_shader_num;
	Shaders current_shader;

	void addShader(Shaders shader);
	void addShader(string name, const char* vertex, const char* fragment);
	void compileShaders();

	ShaderManager();
	ShaderManager(std::vector<Shaders> shader_array);


	void nextShader();

};
