#ifndef SRC_CONTROL_TEST_MENU_TEST_MENU_H
#define SRC_CONTROL_TEST_MENU_TEST_MENU_H

#include "..\test_menu\option_type.h"
#include "../../test_data/test_data.h"

namespace Control
{
    namespace TestMenu
    {
        class TestMenu
        {
        public:
            OptionType control_test_menu_selection(TestData::TestData test_data);
        };
    }
}

#endif //SRC_CONTROL_TEST_MENU_TEST_MENU_H

