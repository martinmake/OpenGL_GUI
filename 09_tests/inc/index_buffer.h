#ifndef _INDEX_BUFFER_H_
#define _INDEX_BUFFER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <inttypes.h>

#include "gldebug.h"

namespace Render
{
	class IndexBuffer
	{
		private:
			unsigned int m_renderer_id;
			uint32_t m_count;

		public:
			IndexBuffer(void);
			IndexBuffer(const unsigned int* data, uint32_t count);
			~IndexBuffer(void);

		public:
			void bind(void)   const;
			void unbind(void) const;

		// GETTERS
		public:
			uint32_t count(void) const;
	};

	inline void IndexBuffer::bind(void) const
	{
		glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
	}

	inline void IndexBuffer::unbind(void) const
	{
		glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	// GETTERS
	inline uint32_t IndexBuffer::count(void) const
	{
		return m_count;
	}

}

#endif
