#ifndef SRC_UI_TEST_MENU_H
#define SRC_UI_TEST_MENU_H

#include "../../test_data/test_data.h"

namespace ui::test_menu
{
    class TestMenu
    {
    public:
        virtual void
        show(string test_name, string username, int amount_of_questions, unordered_map<string, int> users_points, string selected_answer) = 0;

    };
}
#endif //SRC_UI_TEST_MENU_H

