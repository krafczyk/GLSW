// Identity Shader (GLSW_SHADER_IDENTITY)
// This shader does no transformations at all, and uses the current
// glColor value for fragments.
// It will shade between verticies.

attribute vec4 vVertex;
void main(void) { 
	gl_Position = vVertex;
};
