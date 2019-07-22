#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vendor/imgui/imgui.h>

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"

namespace Render
{
	class Renderer
	{
		private:
			GLFWwindow* m_window;

		public:
			Renderer(int width, int height, const std::string& title);
			~Renderer(void);

		public:
			void draw(const VertexArray& vertex_array, const IndexBuffer& index_buffer, const Shader& shader) const;
			void start_frame() const;
			void end_frame() const;

		// GETTERS
		public:
			GLFWwindow* window(void);
	};

	inline GLFWwindow* Renderer::window(void)
	{
		return m_window;
	}
}

#endif
