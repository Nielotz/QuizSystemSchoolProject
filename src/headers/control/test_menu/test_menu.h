#ifndef SRC_CONTROL_TEST_MENU_TEST_MENU_H
#define SRC_CONTROL_TEST_MENU_TEST_MENU_H

#include "..\test_menu\option_type.h"
#include "../../test_data/test_data.h"

namespace Control::TestMenu
{
    class TestMenu
    {
    public:
        virtual OptionType control_test_menu_selection(TestData::TestData test_data) = 0;
    };

    class Teacher : public TestMenu
    {
    public:
        OptionType control_test_menu_selection(TestData::TestData test_data) override;
    };

    class Student : public TestMenu
    {
    public:
        OptionType control_test_menu_selection(TestData::TestData test_data) override;
    };

}

#endif //SRC_CONTROL_TEST_MENU_TEST_MENU_H

