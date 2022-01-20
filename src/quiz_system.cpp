#include "headers/control/control.h"
#include "headers/quiz_system.h"
#include "headers/auth.h"
#include "headers/test_selector.h"
#include "headers/test_menu.h"
#include "headers/test.h"

QuizSystem::QuizSystem()
{
    // Ask user for auth data, and return matching data from database.
    // UserData user_data = {"TestStudent", "TestStudent", AccountType::kStudent};  // auth::login();
    UserData user_data = auth::login();

    // Init global variable in namespace - global_ui.
    ui::UI::init(user_data.account_type);

    control::Control control(user_data.account_type);

    // test_data::TestData selected_test = database::test::get_test_data("TestTestStudent");  // test_selector::select_test(control);
    test_data::TestData selected_test = test_selector::select_test(control);

    auto test_menu_option = test_menu::handle(user_data.username, control, selected_test);

    control::test_menu::OptionType& action_type = test_menu_option.first;

    if (action_type == control::test_menu::OptionType::kQuit)
        // TODO: "Are you sure?" dialogue.
        return;

    const std::string& choose_username = test_menu_option.second;

    test::handle(selected_test, action_type, choose_username);
}