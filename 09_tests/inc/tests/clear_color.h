#ifndef _TESTS_CLEAR_COLOR_H_
#define _TESTS_CLEAR_COLOR_H_

#include <glm/glm.hpp>

#include "tests/base.h"

namespace Test
{
	class ClearColor : public Base
	{
		private:
			glm::vec4 m_clear_color;

		public:
			ClearColor(void);
			~ClearColor(void);

		public:
			void on_update(float delta_time);
			void on_render(void);
			void on_imgui_render(void);
	};
}

#endif
