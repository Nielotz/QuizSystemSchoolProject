#include "headers/test_menu.h"
#include "headers/control/test_menu/test_menu.h"

std::pair<control::test_menu::OptionType, std::string>
test_menu::handle(const std::string &username, const control::Control &control, const test_data::TestData &test_data)
{
    auto test_menu_option = control.test_menu_->control_test_menu_selection(username, test_data);

    return test_menu_option;
}


