#ifndef SRC_TEST_MENU_TEST_MENU_H
#define SRC_TEST_MENU_TEST_MENU_H

#include "control/control.h"
#include "control/test_menu/option_type.h"
#include "test_data/test_data.h"

namespace test_menu
{
    std::pair<control::test_menu::OptionType, std::string>
    handle(const std::string &username, const control::Control &control, const test_data::TestData &test_data);
};

#endif //SRC_TEST_MENU_TEST_MENU_H
