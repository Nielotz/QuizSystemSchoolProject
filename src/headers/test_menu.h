#ifndef SRC_TEST_MENU_TEST_MENU_H
#define SRC_TEST_MENU_TEST_MENU_H

#include "control/control.h"
#include "control/test_menu/option_type.h"
#include "test_data/test_data.h"

class TestMenu
{
public:
	TestMenu(const Control::Control& control);
	Control::TestMenu::OptionType handle();
	void load_test_menu(TestData::TestData test_data);
};

#endif //SRC_TEST_MENU_TEST_MENU_H