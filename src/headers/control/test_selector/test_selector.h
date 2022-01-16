#ifndef SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H
#define SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

#include <string>
#include <vector>

using namespace std;

namespace Control::TestSelector
{
    class TestSelector
    {
    public:
        virtual string control_test_selection(vector<string> tests_data) = 0;
    };

    class Teacher : public TestSelector
    {
    public:
        string control_test_selection(vector<string> tests_data) override;
    };

    class Student : public TestSelector
    {
    public:
        string control_test_selection(vector<string> tests_data) override;
    };
}

#endif //SRC_CONTROL_TEST_SELECTOR_TEST_SELECTOR_H

