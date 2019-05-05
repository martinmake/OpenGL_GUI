#ifndef _GLDEBUG_H_
#define _GLDEBUG_H_

#include <assert.h>

inline void glClearError()
{
	while (glGetError() != GL_NO_ERROR)
		;
}

inline bool glLogCall()
{
	bool found_error = false;

	while (GLenum error = glGetError()) {
		fprintf(stderr, "[GL_ERROR]: ");
		switch (error) {
			case GL_INVALID_ENUM:
				fprintf(stderr, "GL_INVALID_ENUM");
				break;
			case GL_INVALID_VALUE:
				fprintf(stderr, "GL_INVALID_VALUE");
				break;
			case GL_INVALID_OPERATION:
				fprintf(stderr, "GL_INVALID_OPERATION");
				break;
			case GL_STACK_OVERFLOW:
				fprintf(stderr, "GL_STACK_OVERFLOW");
				break;
			case GL_STACK_UNDERFLOW:
				fprintf(stderr, "GL_STACK_UNDERFLOW");
				break;
			case GL_OUT_OF_MEMORY:
				fprintf(stderr, "GL_OUT_OF_MEMORY");
				break;
		}
		found_error = true;
	}

	if (found_error)
		return false;

	return true;
}

#define glCall(x)                  \
	glClearError();            \
	x;                         \
	assert(glLogCall() && #x); \

#endif
