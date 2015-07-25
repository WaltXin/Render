#version 400

layout(location = 0) in vec3 vertex_position;         // the Vertex in local coordinate system
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec2 texture_coord;

uniform float roughnessValue;

uniform mat4 projection_mat, view_mat,model_mat;      // projection and view 
out vec3 position_eye, normal_eye;



void main() {
	position_eye = vec3 (view_mat * vec4 (vertex_position, 1.0));   // view * local coordinate system 
	normal_eye = vec3 (view_mat * vec4 (vertex_normal, 0.0));

	//gl_Position means new Position in NDC 
	gl_Position = projection_mat *model_mat* vec4 (position_eye, 1.0);        // projection * view * model*(position in local coordinate)  in here model is identity mat4 because have no pose in model
}
