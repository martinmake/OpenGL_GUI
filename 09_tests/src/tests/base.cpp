#include "tests/base.h"

#include "renderer.h"

namespace Test
{
	const char* Base::name = "BASE";

	Base::Base(void)
	{
	}

	Base::~Base(void)
	{
	}

	// EVENT HANDLERS
	Base& Base::on_update(float delta_time)
	{
		(void) delta_time;

		return *this;
	}
	Base& Base::on_render(void)
	{
		assert(false && "DO NOT USE BASE TEST, IT IS JUST AN INTERFACE!");

		return *this;
	}
	Base& Base::on_imgui_render(void)
	{
		if (ImGui::Button("RETURN"))
			m_is_done = true;

		return *this;
	}
}
