#ifndef SRC_CONTROL_TEST_MENU_TEACHER_H
#define SRC_CONTROL_TEST_MENU_TEACHER_H

#include "../test_menu/test_menu.h"

namespace Control
{
    namespace TestMenu
    {
        class Teacher : public TestMenu
        {
        public:
            Control::TestMenu::OptionType control_test_menu_selection(TestData::TestData test_data);
        };
    }
}

#endif //SRC_CONTROL_TEST_MENU_TEACHER_H