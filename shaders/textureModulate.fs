// GLSW_SHADER_TEXTURE_MODULATE
// Just put the texture on the polygons, but multiply by the color (as a uniform)

varying vec2 vTex;
uniform sampler2D textureUnit0;
uniform vec4 vColor;
void main(void) {
	gl_FragColor = vColor * texture2D(textureUnit0, vTex);
};
