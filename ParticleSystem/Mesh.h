#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <GL/glew.h>
#include <iostream>
#include <assimp/cimport.h> 
#include <assimp/scene.h>
#include <assimp/postprocess.h> 
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <string>
#include<glm-0.9.4.0\glm\glm.hpp>
#include <glm-0.9.4.0\glm\gtc\matrix_transform.hpp> 
#include <glm-0.9.4.0\glm\gtc\type_ptr.hpp> 


using namespace std;

class Mesh
{
public:
	const char* filename;
	GLuint vao;
	int point_count;
	
	Mesh();
	Mesh(const char* _filename);

	bool load_mesh(std::vector<glm::vec3> &v);
	bool load_mesh();
	void assign_vao(const aiScene* scene);
	void draw(GLuint spID, glm::mat4 model_mat);

	std::vector<glm::vec3> getVertices();

	struct Material
	{
		glm::vec3 ambient, diffuse, specular;
		float shininess;
		glm::vec3 cool, warm;

		Material(){ambient = diffuse = specular = cool = warm = glm::vec3(0.0f); shininess = 0.0f;}
	};

	Material material;


};


