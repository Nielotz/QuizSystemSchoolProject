#ifndef SRC_TEST_MENU_H
#define SRC_TEST_MENU_H

#include "..\test_menu\option_type.h"
#include "..\headers\test_data\test_data.h"

namespace Control
{
    namespace TestMenu
    {
        class TestMenu
        {
        public:
            Control::TestMenu::OptionType control_test_menu_selection(TestData::TestData test_data);
        };
    }
}

#endif //SRC_TEST_MENU_H

