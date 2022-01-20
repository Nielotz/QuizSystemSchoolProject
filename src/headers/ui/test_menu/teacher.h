#ifndef SRC_UI_TEST_MENU_TEACHER_H
#define SRC_UI_TEST_MENU_TEACHER_H

#include "../test_menu/test_menu.h"

namespace ui::test_menu
{
    class Teacher : public TestMenu
    {
    public:
        void show(std::string test_name, std::string username,
            size_t amount_of_questions, std::unordered_map<std::string, int> users_points, std::vector<std::pair<std::string, std::string>> reported_issues, std::string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_MENU_TEACHER_H