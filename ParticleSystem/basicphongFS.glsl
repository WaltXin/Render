#version 400


in vec3 Eye, Normal;
uniform mat4 view_mat;


// fixed point light properties
vec3 light_position_world  = vec3 (-1.5, 0.0, 10.0);
vec3 Ls = vec3 (1.0, 1.0, 1.0); // white specular colour
vec3 Ld = vec3 (0.7, 0.7, 0.7); // dull white diffuse light colour
vec3 La = vec3 (0.6, 0.6, 0.6); // grey ambient colour
  
// surface reflectance
vec3 Ks = vec3 (1.0, 1.0, 1.0); // fully reflect specular light
vec3 Kd = vec3 (1.0, 0.5, 0.0); // orange diffuse surface reflectance
vec3 Ka = vec3 (1.0, 1.0, 1.0); // fully reflect ambient light
float specular_exponent = 1000.0; // specular 'power'

out vec4 fragment_colour; // final colour of surface


void main() {
     //ambient intensity
	 vec3 Ia = La * Ka;

	//diffuse intensity
	// light_position_eye is light in camera view coordinate
	//vec3 light_position_eye = vec3 (view_mat * vec4 (light_position_world, 1.0));
	//vec3 distance_to_light_eye = light_position_eye - Eye;
	//vec3 Light = normalize (distance_to_light_eye);

	// Light
	vec3 Light = normalize(light_position_world);
	float dot_prod = dot (Light, Normal);
	dot_prod = max (dot_prod, 0.0);
	vec3 Id = Ld * Kd * dot_prod; // final diffuse intensity
	
	// specular intensity
	vec3 View = normalize (-Eye);
	
	vec3 Reflection = reflect (-Light, Normal);
    float dot_prod_specular = dot (Reflection, View);
    dot_prod_specular = max (dot_prod_specular, 0.0);
	float specular_factor = pow (dot_prod_specular, specular_exponent);
	
	vec3 Is = Ls * Ks * specular_factor; // final specular intensity
	
	// final colour
	fragment_colour = vec4 (Is + Id + Ia, 1.0);


}
