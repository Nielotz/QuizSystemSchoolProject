#include "../headers/control/control.h"
#include "../headers/control/test_selector/student.h"
#include "../headers/control/test_selector/teacher.h"
#include "../headers/control/test_menu/student.h"
#include "../headers/control/test_menu/teacher.h"

namespace control
{
    Control::Control(AccountType account_type)
    {
        if (account_type == AccountType::kStudent)
        {
            test_selector_ = make_shared<test_selector::Student>();
            test_menu_ = make_shared<test_menu::Student>();
        }
        else
        {
            test_selector_ = make_shared<test_selector::Teacher>();
            test_menu_ = make_shared<test_menu::Teacher>();
        }
    }
}


