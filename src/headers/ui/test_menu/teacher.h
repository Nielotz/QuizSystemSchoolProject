#ifndef SRC_UI_TEST_MENU_TEACHER_H
#define SRC_UI_TEST_MENU_TEACHER_H

#include "../test_menu/test_menu.h"

namespace UI
{
    namespace TestMenu
    {
        class TestMenuTeacher : public TestMenu
        {
        public:
            void show(string username, TestData::TestData test_data);
        };
    }
}
#endif //SRC_UI_TEST_MENU_TEACHER_H