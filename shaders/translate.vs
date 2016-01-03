#version 130

in vec3 position;
in vec3 color;

out vec3 frag_color;

mat4 projection(float angle_of_view_y, float aspect_ratio, float z_near, float z_far)
{
	// from https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
	return mat4(
		vec4(1.0/(tan(angle_of_view_y)*aspect_ratio), 0.0, 0.0, 0.0),
		vec4(0.0, angle_of_view_y, 0.0, 0.0),
		vec4(0.0, 0.0, (z_far+z_near)/(z_far-z_near), -1.0),
		vec4(0.0, 0.0, (2.0*z_far*z_near)/(z_near-z_far), 0.0)
	);
}

mat4 translate(float x, float y, float z)
{
	return mat4(
		vec4(1.0, 0.0, 0.0, 0.0),
		vec4(0.0, 1.0, 0.0, 0.0),
		vec4(0.0, 0.0, 1.0, 0.0),
		vec4(x, y, z, 1.0)
	);
}

uniform mat4 cam_proj;
uniform mat4 cam_view;
uniform mat4 cam_mod;

void main()
{
	gl_Position = (cam_proj * cam_view * cam_mod) * vec4(position, 1);
	frag_color = color;
}
