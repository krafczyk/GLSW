#include <sstream>
#include <string>
#include <cstdio>
#include <cstdarg>

#include "GL/glew.h"
#include "GL/glu.h"
#include "GLSW/glsw.h"

namespace GLSW {
	std::string currentError = "";

	const char* glswGetError() {
		return currentError.c_str();
	}

	int _vscprintf (const char * format, va_list pargs) { 
		int retval; 
		va_list argcopy; 
		va_copy(argcopy, pargs); 
		retval = vsnprintf(NULL, 0, format, argcopy); 
		va_end(argcopy); 
		return retval; 
	}

	void glswSetError(const char* error_format, ...) {
		va_list args;
		va_start(args, error_format);
		int the_length = _vscprintf(error_format, args)+1;
		char buffer[the_length];
		vsprintf(buffer, error_format, args);
		currentError = buffer;
		va_end(args);
	}

	const char* glswGetStockShaderFilePath(GLuint shader) {
		std::stringstream ss;
		switch (shader) {
			case GLSW_SHADER_IDENTITY_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/indentity.vs";
				break;
			}
			case GLSW_SHADER_IDENTITY_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/indentity.fs";
				break;
			}
			case GLSW_SHADER_FLAT_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/flat.vs";
				break;
			}
			case GLSW_SHADER_FLAT_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/flat.fs";
				break;
			}
			case GLSW_SHADER_SHADED_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/shaded.vs";
				break;
			}
			case GLSW_SHADER_SHADED_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/shaded.fs";
				break;
			}
			case GLSW_SHADER_DEFAULT_LIGHT_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/defaultLight.vs";
				break;
			}
			case GLSW_SHADER_DEFAULT_LIGHT_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/defaultLight.fs";
				break;
			}
			case GLSW_SHADER_POINT_LIGHT_DIFFUSE_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/pointLightDiffuse.vs";
				break;
			}
			case GLSW_SHADER_POINT_LIGHT_DIFFUSE_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/pointLightDiffuse.fs";
				break;
			}
			case GLSW_SHADER_TEXTURE_REPLACE_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureReplace.vs";
				break;
			}
			case GLSW_SHADER_TEXTURE_REPLACE_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureReplace.fs";
				break;
			}
			case GLSW_SHADER_TEXTURE_RECT_REPLACE_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureRectReplace.vs";
				break;
			}
			case GLSW_SHADER_TEXTURE_RECT_REPLACE_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureRectReplace.fs";
				break;
			}
			case GLSW_SHADER_TEXTURE_MODULATE_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureModulate.vs";
				break;
			}
			case GLSW_SHADER_TEXTURE_MODULATE_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/textureModulate.fs";
				break;
			}
			case GLSW_SHADER_TEXTURE_POINT_LIGHT_DIFFUSE_VERTEX: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/texturePointLightDiffuse.vs";
				break;
			}
			case GLSW_SHADER_TEXTURE_POINT_LIGHT_DIFFUSE_FRAGMENT: {
				ss << CMAKE_INSTALL_PREFIX "/share/glsw/texturePointLightDiffuse.fs";
				break;
			}
		}
		return ss.str().c_str();
	}

	GLint glswLoadStockShader(GLint shader_id, GLuint shader) {
		return glswLoadShaderFile(glswGetStockShaderFilePath(shader_id), shader);
	}

	//////////////////////////////////////////////////////////////////////////
	// Load the shader from the source text
	GLint glswLoadShaderSrc(const char *szShaderSrc, GLuint shader) {
		GLchar *fsStringPtr[1];
	
		fsStringPtr[0] = (GLchar *)szShaderSrc;
		glShaderSource(shader, 1, (const GLchar **)fsStringPtr, NULL);

		glCompileShader(shader);

		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if(status == GL_FALSE) {
			char infoLog[1024];
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			glswSetError("Couldn't compile the shader!\n%s\n", infoLog);
			return -1;
		}
		return 0;
	}

	////////////////////////////////////////////////////////////////
	// Load the shader from the specified file. Returns < 0 if the
	// shader could not be loaded
	GLint glswLoadShaderFile(const char *szFile, GLuint shader) {
		GLint shaderLength = 0;
		char* shaderText = 0;
		FILE *fp;
		
		// Open the shader file
		fp = fopen(szFile, "r");
		if(fp != NULL) {
			// See how long the file is
			while (fgetc(fp) != EOF) {
				shaderLength++;
			}

			shaderText = new char[shaderLength+1];
	
			// Go back to beginning of file
			rewind(fp);
			
			// Read the whole file in
			fread(shaderText, 1, shaderLength, fp);
			
			// Make sure it is null terminated and close the file
			shaderText[shaderLength] = '\0';
			fclose(fp);
		} else {
			glswSetError("Couldn't open shader file (%s)!", szFile);
			return -1;
		}
		// Load the string
		if(glswLoadShaderSrc((const char *)shaderText, shader) < 0) {
			return -1;
		}
	   
		return 0;
	}

	GLint glswLinkProgram(GLuint program) {
		glLinkProgram(program);

		GLint testVal;
		glGetProgramiv(program, GL_LINK_STATUS, &testVal);
		if(testVal == GL_FALSE) {
			char infoLog[1024];
			glGetProgramInfoLog(program, 1024, NULL, infoLog);
			glswSetError("The program failed to link with the following errors:\n%s\n", infoLog);
			return -1;
		}
		return 0;
	}
}
