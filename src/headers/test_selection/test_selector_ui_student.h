#ifndef SRC_TEST_SELECTOR_UI_STUDENT_H
#define SRC_TEST_SELECTOR_UI_STUDENT_H

#include <vector>
#include <string>

#include "../headers/test_selection/test_selector_ui.h"

namespace TestSelection
{
	class TestSelectorUIStudent : public TestSelectorUI
	{
	public:
		void ask_select_test(std::vector <std::string> tests_);
	};
}

#endif //SRC_TEST_SELECTOR_UI_STUDENT_H
