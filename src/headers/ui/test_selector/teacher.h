#ifndef SRC_TEACHER_H
#define SRC_TEACHER_H

#include "../test_selector/test_selector.h"

namespace UI
{
    namespace TestSelector
    {
        class TestSelectorTeacher : public TestSelector
        {
        public:
            void ask_select_test(vector<string> tests);
        };
    }
}
#endif //SRC_TEACHER_H