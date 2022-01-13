#ifndef SRC_STUDENT_H
#define SRC_STUDENT_H

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
#endif //SRC_STUDENT_H

