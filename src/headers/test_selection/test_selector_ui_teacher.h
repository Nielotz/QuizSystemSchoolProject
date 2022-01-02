#ifndef SRC_TEST_SELECTOR_UI_TEACHER_H
#define SRC_TEST_SELECTOR_UI_TEACHER_H

#include <vector>
#include <string>

#include "../headers/test_selection/test_selector_ui.h"

using namespace std;

namespace TestSelection
{
	class TestSelectorUITeacher : public TestSelectorUI
	{
	public:
		void ask_select_test(std::vector <std::string> tests_);
	};
}

#endif //SRC_TEST_SELECTOR_UI_TEACHER_H

