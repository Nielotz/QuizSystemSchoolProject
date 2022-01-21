#include "headers/test_selector.h"
#include "headers/database/test.h"

#include <vector>

test_data::TestData test_selector::select_test(const control::Control &control)
{
    while (true)
    {
        std::vector<std::string> tests_names = database::test::get_test_names();

        const auto &selected = control.test_selector_->control_test_selection(tests_names);

        const auto &selected_option = selected.first;
        const auto &selected_test_name = selected.second;

        switch (selected_option)
        {
            case control::test_selector::OptionType::kDelete:
                database::test::delete_test(selected_test_name);
                break;

            case control::test_selector::OptionType::kQuit:
                exit(0);

            case control::test_selector::OptionType::kOpen:
                return database::test::get_test_data(selected_test_name);

            case control::test_selector::OptionType::kNew:
                while (true)
                {
                    const string &new_test_name = control::get_safe_string_from_user("test name");
                    bool already_exists = false;
                    for (const auto &test_name: database::test::get_test_names())
                        if (test_name == new_test_name)
                        {
                            already_exists = true;
                            break;
                        }
                    if (already_exists && !control::get_yes_no_answer("Test already exists! Overwrite?"))
                        break;
                    database::test::set_test(test_data::TestData{new_test_name});
                    break;
                }
                break;
        }
    }
}
