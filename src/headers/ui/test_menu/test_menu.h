#ifndef SRC_UI_TEST_MENU_H
#define SRC_UI_TEST_MENU_H

#include "../../test_data/test_data.h"

namespace ui::test_menu
{
    class TestMenu
    {
    public:
        virtual void
        show(std::string test_name, std::string username, size_t amount_of_questions,
 std::map<std::string, int> users_points, std::vector<std::pair<std::string, std::string>> reported_issues, std::string selected_answer) = 0;

    };
}
#endif //SRC_UI_TEST_MENU_H

