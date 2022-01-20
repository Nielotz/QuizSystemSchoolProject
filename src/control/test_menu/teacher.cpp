#include "../../headers/control/test_menu/teacher.h"
#include "../../headers/ui/ui.h"

namespace control::test_menu
{
    using std::string;

    std::pair<control::test_menu::OptionType, string> Teacher::control_test_menu_selection(string username, test_data::TestData test_data)
    {
        string selected_username;
        // if (!test_data.users_points.empty())
        //     selected_username = test_data.users_points;

        // Show test menu - summary of a test.
        // Show test menu - summary of a test.
        ui::UI::get().test_menu_->show(test_data.name,
                                       username,
                                       test_data.questions.size(),
                                       test_data.users_points,
                                       selected_username);

        // TODO: Handle user option.

        return {};
    };
}