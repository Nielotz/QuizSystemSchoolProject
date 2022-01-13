#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "../headers/ui/ui.h"
#include "../headers/control/control.h"
#include "../test_data/test_data.h"

using namespace std;

	class TestSelector
	{	
	public:
		TestSelector(UI::UI ui_, Control::Control control_);
		TestData::TestData select_test();
	};

#endif //SRC_TEST_SELECTOR_H