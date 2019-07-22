#include <iostream>

#include "tests/texture.h"
#include "renderer.h"

#define TEXTURE_NOT_FOUND_TEXTURE_FILEPATH PROJECT_TEXTURE_DIRECTORY"/texture_not_found.png"

namespace Test
{
	const char* Texture::name = "TEXTURE";

	Texture::Texture(void)
	{
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
	Texture& Texture::on_render(void)
	{
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
