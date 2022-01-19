#ifndef SRC_CONTROL_TEST_SELECTOR_TEACHER_H
#define SRC_CONTROL_TEST_SELECTOR_TEACHER_H

#include "../test_selector/test_selector.h"

namespace control::test_selector
{
    class Teacher : public TestSelector
    {
    public:
        std::string control_test_selection(std::vector<std::string> tests_names) override;
    };
}

#endif //SRC_CONTROL_TEST_SELECTOR_TEACHER_H