#ifndef SRC_TEST_MENU_CONTROL_TEACHER_H
#define SRC_TEST_MENU_CONTROL_TEACHER_H

#include "../headers/test_management/test_menu_option_type.h"
#include "../headers/test_management/test_menu_control.h"

using namespace std;

namespace TestManagement
{
	class TestMenuControlTeacher : public TestMenuControl
	{
	public:
		TestMenuOptionType control_test_menu_selection();
	};
}

#endif //SRC_TEST_MENU_CONTROL_TEACHER_H
