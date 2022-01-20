#include "headers/test.h"

#include "headers/database/test.h"

#include "headers/control/control.h"
#include "headers/control/test/test.h"


void test::handle(const test_data::TestData &test_data, control::test_menu::OptionType open_type, const std::string& username)
{
    switch (open_type)
    {
        case control::test_menu::OptionType::kEdit:
            database::test::set_test(control::test::edit(test_data, username));
            break;
        case control::test_menu::OptionType::kReview:
            control::test::review(test_data, username);
            break;
        case control::test_menu::OptionType::kTake:
            database::test::set_test(control::test::take(test_data, username));
            break;
        default:;
    }
}