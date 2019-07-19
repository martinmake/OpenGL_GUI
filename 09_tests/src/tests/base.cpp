#include "tests/base.h"

namespace Test
{
	Base::Base(void)
	{
	}

	Base::~Base(void)
	{
	}

	void Base::on_update(float delta_time)
	{
		(void) delta_time;
	}

	void Base::on_render(void)
	{
	}

	void Base::on_imgui_render(void)
	{
	}
}
