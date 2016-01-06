


#version 130

in vec3 position;
in vec3 colour;

out vec3 frag_colour;


uniform mat4 translateMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

mat4 projection(
    float angle_of_view_y,
    float aspect_ratio,
    float z_near,
    float z_far
    ) {
    // from https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
    return mat4(
             vec4(1.0/(tan(angle_of_view_y)*aspect_ratio), 0.0, 0.0, 0.0),
             vec4(0.0, angle_of_view_y, 0.0, 0.0),
             vec4(0.0, 0.0, (z_far+z_near)/(z_far-z_near), -1.0),
             vec4(0.0, 0.0, (2.0*z_far*z_near)/(z_near-z_far), 0.0)
           );
}


void main() {
      gl_Position = projectionMatrix
		     * viewMatrix
                     * translateMatrix
                     * vec4(position, 1.0);
 			frag_colour = colour;
}


