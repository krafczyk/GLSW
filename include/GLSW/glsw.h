#ifndef GLSW_HDR
#define GLSW_HDR

namespace GLSW {
	const GLint GLSW_SHADER_IDENTITY_VERTEX = 0;
	const GLint GLSW_SHADER_IDENTITY_FRAGMENT = 1;
	const GLint GLSW_SHADER_FLAT_VERTEX = 2;
	const GLint GLSW_SHADER_FLAT_FRAGMENT = 3;
	const GLint GLSW_SHADER_SHADED_VERTEX = 4;
	const GLint GLSW_SHADER_SHADED_FRAGMENT = 5;
	const GLint GLSW_SHADER_DEFAULT_LIGHT_VERTEX = 6;
	const GLint GLSW_SHADER_DEFAULT_LIGHT_FRAGMENT = 7;
	const GLint GLSW_SHADER_POINT_LIGHT_DIFFUSE_VERTEX = 8;
	const GLint GLSW_SHADER_POINT_LIGHT_DIFFUSE_FRAGMENT = 9;
	const GLint GLSW_SHADER_TEXTURE_REPLACE_VERTEX = 10;
	const GLint GLSW_SHADER_TEXTURE_REPLACE_FRAGMENT = 11;
	const GLint GLSW_SHADER_TEXTURE_RECT_REPLACE_VERTEX = 12;
	const GLint GLSW_SHADER_TEXTURE_RECT_REPLACE_FRAGMENT = 13;
	const GLint GLSW_SHADER_TEXTURE_MODULATE_VERTEX = 14;
	const GLint GLSW_SHADER_TEXTURE_MODULATE_FRAGMENT = 15;
	const GLint GLSW_SHADER_TEXTURE_POINT_LIGHT_DIFFUSE_VERTEX = 16;
	const GLint GLSW_SHADER_TEXTURE_POINT_LIGHT_DIFFUSE_FRAGMENT = 17;

	GLint GLSW_NUM_SHADERS = 18;

	const char* glswGetError();

	const char* glswGetStockShaderFilePath(GLuint shader);
	GLint glswLoadStockShader(GLint shader_id, GLuint shader) __attribute__((warn_unused_result));
	GLint glswLoadShaderSrc(const char *szShaderSrc, GLuint shader) __attribute__((warn_unused_result));
	GLint glswLoadShaderFile(const char *szFile, GLuint shader) __attribute__((warn_unused_result));
}

#endif
