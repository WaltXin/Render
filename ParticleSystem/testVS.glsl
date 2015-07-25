#version 400

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec2 texture_coord;

uniform mat4 projection_mat, view_mat, model_mat;

out vec3 direction_to_light_eye;
out vec4 position_eye;

//uniform mat4 g_world;


void main() {
    	mat4 ModelViewMatrix = view_mat;
		mat3 NormalMatrix =  mat3(ModelViewMatrix);

		// Convert normal and position to eye coords
	// Normal in view space
	direction_to_light_eye = normalize( NormalMatrix * vertex_normal);
	// Position in view space
	position_eye = ModelViewMatrix * vec4(vertex_position,1.0);


    //mat4 ModelViewMatrix = view_mat * model_mat;
	//position_eye = vec3 (view_mat * vec4 (vertex_position, 1.0));
	//normal_eye = vec3 (view_mat * vec4 (vertex_normal, 0.0));
	 gl_Position = projection_mat * view_mat* model_mat*vec4(vertex_position,1.0);
}
