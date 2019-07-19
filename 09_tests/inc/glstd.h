#ifndef _GLSTD_H_
#define _GLSTD_H_

#include <GL/glew.h>

#include <inttypes.h>
#include <assert.h>

inline uint8_t glSizeOf(unsigned int type)
{
	switch (type)
	{
		case GL_FLOAT:         return 4;
		case GL_UNSIGNED_INT:  return 4;
		case GL_UNSIGNED_BYTE: return 1;
		default:               assert(false);
	}

	return 0;
}

#endif
