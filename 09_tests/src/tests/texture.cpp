#include "tests/texture.h"
#include "renderer.h"

#define FILEPATH_BUFFER_SIZE 256

int load_texture(ImGuiInputTextCallbackData* userdata)
{


	return 0;
}

namespace Test
{
	const char* Texture::name = "CLEAR COLOR";

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
		ImGui::InputText("TEXTURE FILEPATH", m_filepath, FILEPATH_BUFFER_SIZE, ImGuiInputTextFlags_None, load_texture, m_filepath);
		Base::on_imgui_render();
		ImGui::End();

		return *this;
	}
}
