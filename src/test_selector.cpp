#include "headers/test_selector.h"
#include "headers/database/test.h"
#include "headers/control/test_selector/test_selector.h"

#include <vector>

test_data::TestData test_selector::select_test(const control::Control &control)
{
    std::vector<std::string> tests_names = database::test::get_test_names();

    std::string selected_test_name = control.test_selector_->control_test_selection(tests_names);

    test_data::TestData test_data = database::test::get_test_data(selected_test_name);

    return test_data;
}




