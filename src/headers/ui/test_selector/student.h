#ifndef SRC_UI_TEST_SELECTOR_STUDENT_H
#define SRC_UI_TEST_SELECTOR_STUDENT_H

#include "../test_selector/test_selector.h"

namespace UI
{
    namespace TestSelector
    {
        class TestSelectorStudent : public TestSelector
        {
        public:
            void ask_select_test(vector<string> tests);
        };
    }
}
#endif //SRC_UI_TEST_SELECTOR_STUDENT_H

