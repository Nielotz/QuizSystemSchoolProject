#ifndef SRC_CONTROL_TEST_MENU_TEST_MENU_H
#define SRC_CONTROL_TEST_MENU_TEST_MENU_H

#include "../../test_data/test_data.h"
#include "option_type.h"

namespace control::test_menu
{
    class TestMenu
    {
    public:
        virtual std::pair<control::test_menu::OptionType, std::string>
        control_test_menu_selection(std::string username, test_data::TestData test_data) = 0;
    };
}

#endif //SRC_CONTROL_TEST_MENU_TEST_MENU_H

