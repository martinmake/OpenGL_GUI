#include "tests/clear_color.h"
#include "renderer.h"

namespace Test
{
	ClearColor::ClearColor(void)
		: m_clear_color(0.2, 0.3, 0.8, 1.0)
	{
	}

	ClearColor::~ClearColor(void)
	{
	}

	void ClearColor::on_update(float delta_time)
	{
		(void) delta_time;
	}

	void ClearColor::on_render(void)
	{
		glCall(glClearColor(m_clear_color.r, m_clear_color.g, m_clear_color.b, m_clear_color.a));
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void ClearColor::on_imgui_render(void)
	{
		ImGui::ColorEdit4("CLEAR COLOR", &m_clear_color[0], ImGuiColorEditFlags_None);
	}
}
