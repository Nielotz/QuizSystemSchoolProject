#ifndef SRC_TEST_MENU_H
#define SRC_TEST_MENU_H

#include "../headers/test_management/test_menu_ui.h"
#include "../headers/test_management/test_menu_control.h"
#include "../headers/test_management/test_menu_option_type.h"

namespace TestManagement
{
	class TestMenu
	{
	private:
		TestMenuUI ui_;
		TestMenuControl control_;

	public:
		TestMenu();
		TestMenuOptionType handle();
	};
}

#endif //SRC_TEST_MENU_H
