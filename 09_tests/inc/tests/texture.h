#ifndef _TESTS_TEXTURE_H_
#define _TESTS_TEXTURE_H_

#include <glm/glm.hpp>

#include "tests/base.h"

namespace Test
{
	class Texture : virtual public Base
	{
		public:
			static const char* name;
		private:
			char* m_filepath;

		public:
			Texture(void);
			~Texture(void) override;

		// EVENT HANDLERS
		public:
			Texture& on_update(float delta_time) override;
			Texture& on_render(void)             override;
			Texture& on_imgui_render(void)       override;
	};
}

#endif
