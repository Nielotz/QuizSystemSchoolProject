#ifndef SRC_UI_TEST_MENU_STUDENT_H
#define SRC_UI_TEST_MENU_STUDENT_H

#include "../test_menu/test_menu.h"

namespace ui::test_menu
{
    class Student : public TestMenu
    {
    public:
        void show(string username, test_data::TestData test_data, string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_MENU_STUDENT_H
