#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <inttypes.h>

#include "gldebug.h"

namespace Render
{
	class VertexBuffer
	{
		private:
			unsigned int m_renderer_id;

		public:
			VertexBuffer(void);
			VertexBuffer(const void* data, uint32_t size);
			~VertexBuffer(void);

		public:
			void bind(void)   const;
			void unbind(void) const;
	};

	inline void VertexBuffer::bind(void) const
	{
		glCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id));
	}

	inline void VertexBuffer::unbind(void) const
	{
		glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}

#endif
