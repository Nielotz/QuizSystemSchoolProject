#ifndef SRC_CONTROL_CONTROL_H
#define SRC_CONTROL_CONTROL_H

#include "../../headers/control/test_selector/test_selector.h"
#include "../../headers/control/test_menu/test_menu.h"
#include "../../headers/shared/account_type.h"

#include "memory"

namespace Control
{
    class Control
    {
    public:
        shared_ptr<TestSelector::TestSelector> test_selector_;
        explicit Control(AccountType account_type);
    };
}

#endif //SRC_CONTROL_CONTROL_H

