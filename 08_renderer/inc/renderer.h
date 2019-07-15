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
	private:
		GLFWwindow* m_window;

	public:
		Renderer(int width, int height, const std::string& title);
		~Renderer(void);

	public:
		void draw(const VertexArray& vertex_array, const IndexBuffer& index_buffer, const Shader& shader) const;

	// GETTERS
	public:
		GLFWwindow* window(void);
};

inline GLFWwindow* Renderer::window(void)
{
	return m_window;
}

#endif
