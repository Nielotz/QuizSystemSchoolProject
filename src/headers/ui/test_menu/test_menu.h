#ifndef SRC_UI_TEST_MENU_H
#define SRC_UI_TEST_MENU_H

#include "../../test_data/test_data.h"

namespace ui::test_menu
{
    class TestMenu
    {
    public:
        virtual void show(string username, test_data::TestData test_data, string selected_answer) = 0;
    };
}
#endif //SRC_UI_TEST_MENU_H

