#ifndef _TESTS_SELECTOR_H_
#define _TESTS_SELECTOR_H_

#include <map>
#include <functional>

#include "tests/all.h"

namespace Test
{
	class Selector
	{
		private:
			Test::Base* m_running_test;
			const std::map<const std::string, std::function<Test::Base*()>> m_test_database =
			{
				 {       Base::name, [](){ return new       Base(); } },
				 { ClearColor::name, [](){ return new ClearColor(); } }
			};

		public:
			Selector(void);
			~Selector(void);

		public:
			void run_test(const char* test_name);
			void end_test(void);

		// GETTERS
		public:
			bool is_test_running(void) const;
			Base& running_test(void);

		// EVENT HANDLERS
		public:
			Selector& on_render(void);
			Selector& on_imgui_render(void);
	};

	// GETTERS
	inline bool Selector::is_test_running(void) const
	{
		return m_running_test ? true : false;
	}
	inline Base& Selector::running_test(void)
	{
		return *m_running_test;
	}
}

#endif
