#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include <vector>
#include <string>

using namespace std;

namespace UI
{
    namespace TestSelector
    {
        class TestSelector
        {
        public:
            void ask_select_test(vector<string> tests);
        };
    }
}
#endif //SRC_TEST_SELECTOR_H

