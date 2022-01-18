#ifndef SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H
#define SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

#include <string>
#include <vector>

using namespace std;

namespace control::test_selector
{
    class TestSelector
    {
    public:
        virtual string control_test_selection(vector<string> tests_names) = 0;
    };
}

#endif //SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

