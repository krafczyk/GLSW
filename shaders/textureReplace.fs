// GLSW_SHADER_TEXTURE_REPLACE
// Just put the texture on the polygons

varying vec2 vTex;
uniform sampler2D textureUnit0;
void main(void) {
	gl_FragColor = texture2D(textureUnit0, vTex); 
};
