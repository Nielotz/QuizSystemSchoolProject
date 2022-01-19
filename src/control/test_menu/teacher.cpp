#include "../../headers/control/test_menu/teacher.h"
#include "../../headers/ui/ui.h"

namespace control::test_menu
{
    control::test_menu::OptionType Teacher::control_test_menu_selection(string username, test_data::TestData test_data)
    {
        string selected_username;
        // if (!test_data.users_points.empty())
        //     selected_username = test_data.users_points;

        // Show test menu - summary of a test.
        ui::UI::get().test_menu_->show(username, test_data, selected_username);

        // TODO: Handle user option.

        return OptionType::kReview;
    };
}