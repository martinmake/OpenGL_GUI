#ifndef _TESTS_TEXTURE_H_
#define _TESTS_TEXTURE_H_

#include <glm/glm.hpp>
#include <array>
#include "renderer.h"

#include "tests/base.h"

#define FILEPATH_BUFFER_SIZE 256

namespace Test
{
	class Texture : virtual public Base
	{
		public:
			static const char* name;
		private:
			std::array<char, FILEPATH_BUFFER_SIZE> m_filepath;
			Render::Texture m_texture;

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
