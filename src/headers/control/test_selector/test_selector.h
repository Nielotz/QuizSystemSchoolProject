#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include <string>
#include <vector>

using namespace std;

namespace Control
{
    namespace TestSelector
    {
        class TestSelector
        {
        public:
            string control_test_selection(vector<string> tests_data);
        };
    }
}

#endif //SRC_TEST_SELECTOR_H

