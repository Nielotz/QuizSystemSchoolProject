#include "headers/test_menu.h"
#include "headers/control/test_menu/test_menu.h"

control::test_menu::OptionType
test_menu::handle(const string &username, const control::Control &control, const test_data::TestData &test_data)
{
    control::test_menu::OptionType option = control.test_menu_->control_test_menu_selection(username, test_data);

    return option;
}


