#ifndef SRC_UI_TEST_SELECTOR_STUDENT_H
#define SRC_UI_TEST_SELECTOR_STUDENT_H

#include "../test_selector/test_selector.h"

namespace ui::test_selector
{
    class Student : public TestSelector
    {
    public:
        void ask_select_test(std::vector<std::string> tests, std::string selected_answer) override;
    };
}
#endif //SRC_UI_TEST_SELECTOR_STUDENT_H

