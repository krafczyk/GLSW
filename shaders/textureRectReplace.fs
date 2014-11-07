// GLSW_SHADER_TEXTURE_RECT_REPLACE
// Just put the texture on the polygons

varying vec2 vTex;
uniform sampler2DRect textureUnit0;
void main(void) {
	gl_FragColor = texture2DRect(textureUnit0, vTex);
};
