#ifndef SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H
#define SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H

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
            void ask_select_test(vector<string> tests, string selected_answer);
        };
    }
}
#endif //SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H

