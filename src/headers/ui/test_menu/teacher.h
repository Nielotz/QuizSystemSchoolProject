#ifndef SRC_UI_TEST_MENU_TEACHER_H
#define SRC_UI_TEST_MENU_TEACHER_H

#include "../test_menu/test_menu.h"

namespace ui::test_menu
{
    class Teacher : public TestMenu
    {
    public:
        void show(string test_name, string username, int amount_of_questions, unordered_map<string, int> users_points,
                  string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_MENU_TEACHER_H