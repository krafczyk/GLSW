// GLSW_SHADER_SHADED
// Point light, diffuse lighting only

uniform mat4 mvpMatrix;
attribute vec4 vColor;
attribute vec4 vVertex;
varying vec4 vFragColor;
void main(void) {
	vFragColor = vColor;
	gl_Position = mvpMatrix * vVertex;
};
