#ifndef SRC_TEST_SELECTOR_CONTROL_TEACHER_H
#define SRC_TEST_SELECTOR_CONTROL_TEACHER_H

#include "../headers/test_selection/test_selector_control.h"

using namespace std;

namespace TestSelection
{
	class TestSelectorControlTeacher : public TestSelectorControl
	{
	public:
		string control_test_selection();
	};
}

#endif //SRC_TEST_SELECTOR_CONTROL_TEACHER_H
