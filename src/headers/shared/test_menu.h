#ifndef SRC_TEST_MENU_H
#define SRC_TEST_MENU_H

#include "../headers/control/control.h"
#include "../headers/ui/ui.h"
#include "../headers/control/test_menu/option_type.h"
#include "../headers/shared/test_data.h"

	class TestMenu
	{
	public:
		TestMenu(UI ui_, Control control_);
		Control::TestMenu::OptionType handle();
		void load_test_menu(TestData test_data_);
	};

#endif //SRC_TEST_MENU_H
