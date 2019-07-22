#ifndef _TESTS_BASE_H_
#define _TESTS_BASE_H_

#include <string>

#include "renderer.h"

namespace Test
{
	class Base
	{
		public:
			static const char* name;
		protected:
			bool m_is_done = false;

		public:
			Base(void);
			virtual ~Base(void);

		// EVENT HANDLERS
		public:
			virtual Base& on_update(float delta_time);
			virtual Base& on_render(const Render::Renderer& renderer);
			virtual Base& on_imgui_render(void);

		// GETTERS
		public:
			bool is_done(void) const;
	};

	inline bool Base::is_done(void) const { return m_is_done; }
}

#endif
