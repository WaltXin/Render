#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <GL/glew.h>
#include <iostream>


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
#include <glm-0.9.4.0\glm\gtx\orthonormalize.hpp>
#include <glm-0.9.4.0\glm\gtc\constants.hpp>

#include "Mesh.h"


//#include "AntTweakBar.h"

class RigidBody
{
public:

	glm::vec3 position;
	glm::vec3 orientation;

	glm::vec3 velocity;
	glm::vec3 ang_velocity;


	glm::mat4 translation_mat;
	glm::mat3 rotation_mat;

	glm::mat4 model_mat;



	Mesh mesh;

	RigidBody();
	RigidBody(Mesh _mesh);

	void load_mesh();
	void draw(GLuint spID);

	//void addTBar(TwBar *bar);

	void update(float dt);

	void updateTranslation(float dt);
	void updateRotation(float dt);


	glm::vec3 getOrientationFromRotMat(glm::mat3 mat);

	
	
	glm::mat3 makeAngVelMat(glm::vec3 av_vec);


	void transformVertices();


	void reset();
};


