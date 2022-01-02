#ifndef SRC_TEST_SELECTOR_CONTROL_STUDENT_H
#define SRC_TEST_SELECTOR_CONTROL_STUDENT_H

#include "../headers/test_selection/test_selector_control.h"

using namespace std;

namespace TestSelection
{
	class TestSelectorControlStudent : public TestSelectorControl
	{
	public:
		string control_test_selection();
	};
}

#endif //SRC_TEST_SELECTOR_CONTROL_STUDENT_H
