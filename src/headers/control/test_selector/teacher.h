#ifndef SRC_CONTROL_TEST_SELECTOR_TEACHER_H
#define SRC_CONTROL_TEST_SELECTOR_TEACHER_H

#include "../test_selector/test_selector.h"

using namespace std;

namespace control::test_selector
{
    class Teacher : public TestSelector
    {
    public:
        string control_test_selection(vector<string> tests_names) override;
    };
}

#endif //SRC_CONTROL_TEST_SELECTOR_TEACHER_H