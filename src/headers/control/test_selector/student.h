#ifndef SRC_CONTROL_TEST_SELECTOR_STUDENT_H
#define SRC_CONTROL_TEST_SELECTOR_STUDENT_H

#include "../test_selector/test_selector.h"

using namespace std;

namespace Control
{
    namespace TestSelector
    {
        class Student : public TestSelector
        {
        public:
            string control_test_selection(vector<string> tests_data);
        };
    }
}

#endif //SRC_CONTROL_TEST_SELECTOR_STUDENT_H