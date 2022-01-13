#ifndef SRC_UI_H
#define SRC_UI_H

#include "../shared/account_type.h"
#include "../ui/test_menu/test_menu.h"
#include "../ui/test_selector/test_selector.h"
#include "../../headers/ui/test.h"

namespace UI
{
    class UI
    {
    public:
        TestSelector::TestSelector test_selector_;
        TestMenu::TestMenu test_menu_;
        Test::Test test_;
        UI(AccountType account_type_);
    };
}
#endif //SRC_UI_H

