#include "../headers/control/control.h"

namespace Control
{
    Control::Control(AccountType account_type)
    {
        if (account_type == AccountType::kStudent){
            test_selector_ = make_unique<TestSelector::Student>();
        }
        else{
            test_selector_ = make_unique<TestSelector::Teacher>();
        }
    }
}


