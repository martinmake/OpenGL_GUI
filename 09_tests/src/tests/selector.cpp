#include "tests/selector.h"

#include "renderer.h"

namespace Test
{
	Selector::Selector(void)
		: m_running_test(nullptr)
	{
	}

	Selector::~Selector(void)
	{
	}

	// EVENT HANDLERS
	Selector& Selector::on_render(void)
	{
		return *this;
	}
	Selector& Selector::on_imgui_render(void)
	{
		ImGui::Begin("TEST SELECTOR");
		for (const std::pair<const std::string, std::function<Test::Base*()>>& test_database_entry : m_test_database)
		{
			if (ImGui::Button(test_database_entry.first.c_str()))
			{
				m_running_test = test_database_entry.second();
				break;
			}
		}
		ImGui::End();

		return *this;
	}

	void Selector::run_test(const char* test_name)
	{
		const std::map<const std::string, std::function<Test::Base*()>>::const_iterator test_database_iterator = m_test_database.find(test_name);
		if (test_database_iterator != m_test_database.end())
			m_running_test = test_database_iterator->second();
	}

	void Selector::end_test(void)
	{
		delete m_running_test;
		m_running_test = nullptr;
	}
}
