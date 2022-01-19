#ifndef SRC_UI_TEST_MENU_STUDENT_H
#define SRC_UI_TEST_MENU_STUDENT_H

#include "../test_menu/test_menu.h"

namespace ui::test_menu
{
    class Student : public TestMenu
    {
    public:
        void show(string test_name, string username, size_t amount_of_questions, unordered_map<string, int> users_points,
                  string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_MENU_STUDENT_H
