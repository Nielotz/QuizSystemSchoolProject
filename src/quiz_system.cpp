#include "headers/control/control.h"
#include "headers/quiz_system.h"
#include "headers/auth.h"
#include "headers/test_selector.h"
#include "headers/test_menu.h"
#include "headers/test.h"

QuizSystem::QuizSystem()
{
    // Ask user for auth data, and return matching data from database.
    UserData user_data = auth::login();

    // Init global variable in namespace - global_ui.
    ui::UI::init(user_data.account_type);

    control::Control control(user_data.account_type);

    test_data::TestData selected_test = test_selector::select_test(control);

    control::test_menu::OptionType option = test_menu::handle(user_data.username, control, selected_test);

    if (option == control::test_menu::OptionType::kQuit)
        // TODO: "Are you sure?" dialogue.
        return;

    control::test_menu::OptionType &test_open_type = option;
    Test test(selected_test, test_open_type);
}

void QuizSystem::create_new_test()
{

}

void QuizSystem::exit()
{

}