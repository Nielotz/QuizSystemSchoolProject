#ifndef SRC_CONTROL_CONTROL_H
#define SRC_CONTROL_CONTROL_H

#include <memory>
#include <Windows.h>
#include <string>

#include "../../headers/control/test_selector/test_selector.h"
#include "../../headers/control/test_menu/test_menu.h"
#include "../../headers/shared/account_type.h"

namespace control
{
    class Control
    {
    public:
        std::shared_ptr<test_selector::TestSelector> test_selector_;
        std::shared_ptr<test_menu::TestMenu> test_menu_;
        explicit Control(AccountType account_type);
    };

    std::string get_safe_string_from_user(const std::string& string_description);

    bool get_yes_no_answer(const std::string& question);
}

#endif //SRC_CONTROL_CONTROL_H

