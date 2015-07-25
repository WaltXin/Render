#version 400

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec2 vertex_texture;


uniform mat4 view;
uniform mat4 proj;
uniform mat4 model;

out vec3 direction_to_light_eye;
out vec4 position_eye;




void main() {
	Eye = vec3 (view_mat * vec4 (vertex_position, 1.0));   // view * local coordinate system 
	Normal = vec3 (view_mat * vec4 (vertex_normal, 0.0));

	//gl_Position means new Position in NDC 
	 gl_Position = projection_mat * view_mat* model_mat*vec4(vertex_position,1.0);
}
