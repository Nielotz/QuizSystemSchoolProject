#ifndef SRC_TEST_SELECTOR_CONTROL_H
#define SRC_TEST_SELECTOR_CONTROL_H

#include <string>
#include <vector>

namespace TestSelection
{
	class TestSelectorControl
	{
	public:
		std::string control_test_selection(std::vector<std::string> tests_);
	};
}

#endif //SRC_TEST_SELECTOR_CONTROL_H