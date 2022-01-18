#ifndef SRC_CONTROL_TEST_MENU_TEST_MENU_H
#define SRC_CONTROL_TEST_MENU_TEST_MENU_H

#include "..\test_menu\option_type.h"
#include "../../test_data/test_data.h"

namespace control::test_menu
{
    class TestMenu
    {
    public:
        virtual OptionType control_test_menu_selection(string username, test_data::TestData test_data) = 0;
    };
}

#endif //SRC_CONTROL_TEST_MENU_TEST_MENU_H

