// Flat Shader (GLSW_SHADER_FLAT)
// This shader applies the given model view matrix to the verticies, 
// and uses a uniform color value.

uniform vec4 vColor;
void main(void) {
	gl_FragColor = vColor;
};
