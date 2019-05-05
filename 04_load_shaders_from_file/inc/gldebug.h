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
		fprintf(stderr, "[GL_ERROR]: %#0x\n", error);
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
