#include "../../headers/control/test_menu/student.h"
#include "../../headers/ui/ui.h"

namespace control::test_menu
{
    control::test_menu::OptionType Student::control_test_menu_selection(string username, test_data::TestData test_data)
    {
        string selected_username;

        // If user took the test, set selected_username to be username.
        if (test_data.users_points.contains(username))
            selected_username = username;

        // Show test menu - summary of a test.
        ui::UI::get().test_menu_->show(username, test_data, selected_username);

        // TODO: Handle user option.

        return OptionType::kTake;
    };
}

