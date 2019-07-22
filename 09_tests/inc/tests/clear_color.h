#ifndef _TESTS_CLEAR_COLOR_H_
#define _TESTS_CLEAR_COLOR_H_

#include <glm/glm.hpp>

#include "tests/base.h"

namespace Test
{
	class ClearColor : virtual public Base
	{
		public:
			static const char* name;
		private:
			glm::vec4 m_clear_color;

		public:
			ClearColor(void);
			~ClearColor(void) override;

		// EVENT HANDLERS
		public:
			ClearColor& on_update(float delta_time)                 override;
			ClearColor& on_render(const Render::Renderer& renderer) override;
			ClearColor& on_imgui_render(void)                       override;
	};
}

#endif
