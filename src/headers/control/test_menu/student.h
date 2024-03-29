#ifndef SRC_CONTROL_TEST_MENU_STUDENT_H
#define SRC_CONTROL_TEST_MENU_STUDENT_H

#include "../test_menu/test_menu.h"
#include "option_type.h"

namespace control::test_menu
{
    class Student : public TestMenu
    {
    public:
        std::pair<control::test_menu::OptionType, std::string>
        control_test_menu_selection(std::string username, test_data::TestData test_data) override;
    };
}

#endif //SRC_CONTROL_TEST_MENU_STUDENT_H
