#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <inttypes.h>

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

#include "gldebug.h"

class VertexArray
{
	private:
		unsigned int m_renderer_id;

	public:
		VertexArray(void);
		~VertexArray(void);

	public:
		void add_buffer(const VertexBuffer& vertex_buffer, const VertexBufferLayout& layout);

		void bind(void)   const;
		void unbind(void) const;
};

inline void VertexArray::bind(void) const
{
	glCall(glBindVertexArray(m_renderer_id));
}

inline void VertexArray::unbind(void) const
{
	glCall(glBindVertexArray(0));
}

#endif
