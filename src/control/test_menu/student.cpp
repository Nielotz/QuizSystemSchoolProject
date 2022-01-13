#ifndef SRC_CONTROL_H
#define SRC_CONTROL_H

#include "../headers/control/test_selector/test_selector.h"
#include "../headers/control/test_selector/test_menu.h"
#include "../headers/shared/account_type.h"

namespace Control
{
    class Control
    {
    public:
        Control::TestSelector::TestSelector test_selector_;
        Control::TestMenu::TestMenu tets_menu_;
        Control(AccountType account_type_);
    };
}

#endif //SRC_CONTROL_H

