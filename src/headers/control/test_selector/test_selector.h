#ifndef SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H
#define SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

#include <string>
#include <vector>

namespace control::test_selector
{
    class TestSelector
    {
    public:
        virtual std::string control_test_selection(std::vector<std::string> tests_names) = 0;
    };
}

#endif //SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

