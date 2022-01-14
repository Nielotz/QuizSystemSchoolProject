#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "../headers/ui/ui.h"
#include "../headers/control/control.h"
#include "../test_data/test_data.h"

using namespace std;

	class TestSelector
	{	
	public:
		TestSelector(const Control::Control& control);
		TestData::TestData select_test();
	};

#endif //SRC_TEST_SELECTOR_H
