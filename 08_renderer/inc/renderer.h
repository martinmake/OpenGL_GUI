#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glew.h>

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "index_buffer.h"
#include "shader.h"

class Renderer
{
	public:
		Renderer(void);
		~Renderer(void);

	public:
		void draw(const VertexArray& vertex_array, const IndexBuffer& index_buffer, const Shader& shader) const;
};

#endif
