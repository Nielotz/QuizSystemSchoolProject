#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "../headers/ui/ui.h"
#include "../headers/control/control.h"
#include "../shared/test_data.h"

using namespace std;

	class TestSelector
	{	
	public:
		TestSelector(UI::UI ui_, Control::Control control_);
		TestData select_test();
	};

#endif //SRC_TEST_SELECTOR_H