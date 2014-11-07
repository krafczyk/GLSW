// GLSW_SHADER_TEXTURE_POINT_LIGHT_DIFF
// Point light (Diffuse only), with texture (modulated)

varying vec4 vFragColor;
varying vec2 vTex;
uniform sampler2D textureUnit0;
void main(void) {
	gl_FragColor = vFragColor * texture2D(textureUnit0, vTex);
};
