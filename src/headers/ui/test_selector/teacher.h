#ifndef SRC_UI_TEST_SELECTOR_TEACHER_H
#define SRC_UI_TEST_SELECTOR_TEACHER_H

#include "../test_selector/test_selector.h"

namespace ui::test_selector
{
    class Teacher : public TestSelector
    {
    public:
        void ask_select_test(vector<string> tests, string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_SELECTOR_TEACHER_H