#ifndef _TESTS_TEXTURE_H_
#define _TESTS_TEXTURE_H_

#include <glm/glm.hpp>
#include <array>
#include "renderer.h"

#include "tests/base.h"

#define FILEPATH_BUFFER_SIZE 256

namespace Test
{
	class Texture : virtual public Base
	{
		public:
			static const char* name;
		private:
			std::array<char, FILEPATH_BUFFER_SIZE> m_filepath;
		private:
			Render::VertexArray  m_vertex_array;
			Render::VertexBuffer m_vertex_buffer;
			Render::IndexBuffer  m_index_buffer;
			Render::Shader       m_shader;
			Render::Texture      m_texture;

		public:
			Texture(void);
			~Texture(void) override;

		// EVENT HANDLERS
		public:
			Texture& on_update(float delta_time) override;
			Texture& on_render(const Render::Renderer& renderer);
			Texture& on_imgui_render(void)       override;
	};
}

#endif
