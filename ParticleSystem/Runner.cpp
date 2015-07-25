#include <GL/glew.h>
#include<GL/freeglut.h>
#include <assimp/cimport.h> 
#include <assimp/scene.h>
#include <assimp/postprocess.h> 
#include "assert.h"
#include "Mesh.h"
#include<Physics.h>
#include<ShaderLoader.h>
#include<ShaderLoaderManager.h>


int width = 800;
int height = 800;

#define PHONG_VS "phongVertexShader.glsl"
#define PHONG_FS "phongFragmentShader.glsl"
#define TOON_VS "toonVS.glsl"
#define TOON_FS "toonFS.glsl"

#define MESH_MONKEY "../Meshes/suzanne.dae"
#define MESH_SPHERE "../Meshes/sphere.dae"


int passTime = 0;


glm::vec4 light_pos(-5.0f, 0.0f, 5.0f, 1.0f); 
glm::vec3 la(0.5f, 0.5f, 0.5f); 
glm::vec3 ld(1.0f, 1.0f, 1.0f); 
glm::vec3 ls(1.0f, 1.0f, 1.0f); 

Mesh monkey_mesh(MESH_MONKEY);
RigidBody monkey(monkey_mesh);

Mesh sphere_mesh(MESH_SPHERE);
RigidBody sphere(sphere_mesh);


glm::mat4 proj_mat, view_mat;

glm::vec3 monkey_turn_speed (0.0f, 2.0f, 0.0f);
glm::vec3 sphere_turn_speed (0.0f, 2.0f, 0.0f);
glm::vec3 torus_turn_speed (1.0f, 1.0f, 1.0f);

ShaderManager shaders;
Shaders *current_shader;

void addShaders()
{
	shaders.addShader("Phong", PHONG_VS, PHONG_FS);
	shaders.addShader("Toon", TOON_VS, TOON_FS);
	
}



void init()
{
	addShaders();
	shaders.compileShaders();
	

	current_shader = &shaders.current_shader;

	monkey.load_mesh();
	monkey.ang_velocity = monkey_turn_speed;

	sphere.load_mesh();
	sphere.ang_velocity = sphere_turn_speed;
	sphere.position = glm::vec3(-3.0f, 0.0f, 0.0f);


}

void display()
{

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LESS); 
	glClearColor (0.5f, 0.5f, 0.5f, 1.0f);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	glUseProgram(current_shader->id);

	int light_pos_location = glGetUniformLocation (current_shader->id, "LightPosition");
	glUniform4fv(light_pos_location, 1, glm::value_ptr(light_pos));

	int la_location = glGetUniformLocation (current_shader->id, "La");
	int ld_location = glGetUniformLocation (current_shader->id, "Ld");
	int ls_location = glGetUniformLocation (current_shader->id, "Ls");

	glUniform3fv(la_location, 1, glm::value_ptr(la));
	glUniform3fv(ld_location, 1, glm::value_ptr(ld));
	glUniform3fv(ls_location, 1, glm::value_ptr(ls));

	int model_mat_location = glGetUniformLocation (current_shader->id, "model");
	int view_mat_location = glGetUniformLocation (current_shader->id, "view");
	int proj_mat_location = glGetUniformLocation (current_shader->id, "proj");

	proj_mat = glm::perspective(45.0f, (float)width/(float)height, 0.1f, 200.0f);
	glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, glm::value_ptr(proj_mat));


	glm::vec3 position,focus;
	position = glm::vec3(0.0f,0.0f,10.0f);
	glm::mat4 ret = glm::lookAt(position, focus, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv (view_mat_location, 1, GL_FALSE, glm::value_ptr(ret));

	

	monkey.draw(current_shader->id);
	//sphere.draw(current_shader->id);


	glutSwapBuffers();
}

void updateScene()
{
	int time = glutGet(GLUT_ELAPSED_TIME);
	int delta_time = time-passTime;
	passTime = time;

	double elapsed_seconds = (double)delta_time/1000;

	monkey.ang_velocity = monkey_turn_speed;
	monkey.update(elapsed_seconds);

	sphere.ang_velocity = sphere_turn_speed;
	sphere.update(elapsed_seconds);

	glutPostRedisplay();
}





int main(int argc, char** argv)
{

	// Set up the window
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("RTRendering");

	// Tell glut where the display function is
	glutDisplayFunc(display);
	glutIdleFunc(updateScene);

    GLenum res = glewInit();
	// Check for any errors
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      return 1;
    }
	// Set up your objects and shaders
	init();
	// Begin infinite event loop
	glutMainLoop();
    return 0;
}