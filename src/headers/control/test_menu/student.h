#ifndef SRC_CONTROL_TEST_MENU_STUDENT_H
#define SRC_CONTROL_TEST_MENU_STUDENT_H

#include "../test_menu/test_menu.h"

namespace control::test_menu
{
    class Student : public TestMenu
    {
    public:
        OptionType control_test_menu_selection(string username, test_data::TestData test_data) override;
    };
}

#endif //SRC_CONTROL_TEST_MENU_STUDENT_H
