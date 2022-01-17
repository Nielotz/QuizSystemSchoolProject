#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "ui/ui.h"
#include "control/control.h"
#include "test_data/test_data.h"

using namespace std;

	class TestSelector
	{
		shared_ptr<Control::Control> control_;
	public:
		explicit TestSelector(shared_ptr<Control::Control> control);
		TestData::TestData select_test();
	};

#endif //SRC_TEST_SELECTOR_H
