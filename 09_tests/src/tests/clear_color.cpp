#include "tests/clear_color.h"
#include "renderer.h"

namespace Test
{
	const char* ClearColor::name = "CLEAR COLOR";

	ClearColor::ClearColor(void)
		: m_clear_color(0.2, 0.3, 0.8, 1.0)
	{
	}

	ClearColor::~ClearColor(void)
	{
	}

	// EVENT HANDLERS
	ClearColor&  ClearColor::on_update(float delta_time)
	{
		(void) delta_time;

		return *this;
	}
	ClearColor& ClearColor::on_render(const Render::Renderer& renderer)
	{
		(void) renderer;

		glCall(glClearColor(m_clear_color.r, m_clear_color.g, m_clear_color.b, m_clear_color.a));
		glCall(glClear(GL_COLOR_BUFFER_BIT));

		return *this;
	}
	ClearColor& ClearColor::on_imgui_render(void)
	{
		ImGui::Begin(name);
		ImGui::ColorEdit4(name, &m_clear_color[0], ImGuiColorEditFlags_None);
		Base::on_imgui_render();
		ImGui::End();

		return *this;
	}
}
