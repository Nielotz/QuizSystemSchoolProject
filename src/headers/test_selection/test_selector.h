#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "../headers/test_management/test_data.h"
#include "../headers/shared/account_type.h"
#include "../headers/test_selection/test_selector_ui.h"
#include "../headers/test_selection/test_selector_control.h"

using namespace std;

namespace TestSelection
{
	class TestSelector
	{
	private:
		TestSelectorUI test_selector_ui_;
		TestSelectorControl test_selector_control_;
	
	public:
		TestSelector(AccountType account_type_);
		TestManagement::TestData select_test();
	};
}

#endif //SRC_TEST_SELECTOR_H