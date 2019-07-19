#ifndef _TESTS_BASE_H_
#define _TESTS_BASE_H_

namespace Test
{
	class Base
	{
		public:
			Base(void);
			~Base(void);

		public:
			void on_update(float delta_time);
			void on_render(void);
			void on_imgui_render(void);
	};
}

#endif
