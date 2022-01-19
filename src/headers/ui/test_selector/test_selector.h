#ifndef SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H
#define SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H

#include <vector>
#include <string>

namespace ui::test_selector
{
    class TestSelector
    {
    public:
        virtual void ask_select_test(std::vector<std::string> tests, std::string selected_answer) = 0;
    };
}
#endif //SRC_UI_TEST_SELECTOR_TEST_SELECTOR_H

