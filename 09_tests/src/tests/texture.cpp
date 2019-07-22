#include <iostream>

#include "tests/texture.h"
#include "renderer.h"

#define TEXTURE_NOT_FOUND_TEXTURE_FILEPATH PROJECT_TEXTURE_DIRECTORY"/texture_not_found.png"

#define MODEL_WIDTH  100.0
#define MODEL_HEIGHT 100.0

namespace Test
{
	const char* Texture::name = "TEXTURE";

	Texture::Texture(void)
	{
		float positions[] =
		{
				  0,            0, 0.0, 0.0,
			MODEL_WIDTH,            0, 1.0, 0.0,
			MODEL_WIDTH, MODEL_HEIGHT, 1.0, 1.0,
				  0, MODEL_HEIGHT, 0.0, 1.0
		};
		m_vertex_buffer = Render::VertexBuffer(positions, 4 * 4 * sizeof(float));

		Render::VertexBufferLayout vertex_buffer_layout;
		vertex_buffer_layout.push<float>(2);
		vertex_buffer_layout.push<float>(2);

		m_vertex_array.add_buffer(m_vertex_buffer, vertex_buffer_layout);

		unsigned int indices[2 * 3] =
		{
			0, 1, 2,
			2, 3, 0
		};
		m_index_buffer = Render::IndexBuffer(indices, 2 * 3);

		m_shader = Render::Shader(PROJECT_SHADER_DIRECTORY"/tests/texture");
		m_shader.set_uniform_1i("u_texture", 0);

		m_texture = Render::Texture(TEXTURE_NOT_FOUND_TEXTURE_FILEPATH, 0);
	}

	Texture::~Texture(void)
	{
	}

	// EVENT HANDLERS
	Texture&  Texture::on_update(float delta_time)
	{
		(void) delta_time;

		return *this;
	}
	Texture& Texture::on_render(const Render::Renderer& renderer)
	{
		(void) renderer;

		renderer.draw(m_vertex_array, m_index_buffer, m_shader);

		return *this;
	}
	Texture& Texture::on_imgui_render(void)
	{
		ImGui::Begin(name);
		if (ImGui::InputText("FILEPATH", m_filepath.data(), FILEPATH_BUFFER_SIZE, ImGuiInputTextFlags_EnterReturnsTrue))
		{
			if(!m_texture.load(m_filepath.data()))
				m_texture.load(TEXTURE_NOT_FOUND_TEXTURE_FILEPATH);
		}

		Base::on_imgui_render();
		ImGui::End();

		return *this;
	}
}
