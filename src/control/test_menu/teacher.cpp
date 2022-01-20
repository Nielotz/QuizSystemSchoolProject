#include <Windows.h>
#include <iostream>

#include "../../headers/control/test_menu/teacher.h"
#include "../../headers/ui/ui.h"

namespace control::test_menu
{
    using std::string;

    std::pair <control::test_menu::OptionType, string> Teacher::control_test_menu_selection(string username, test_data::TestData test_data)
    {
        // Extract usernames from map.
        std::vector <string> usernames;  // Declare vector of keys - usernames.
        usernames.reserve(test_data.users_points.size());  // Reserve space, to avoid copying data.
        for (auto &kv: test_data.users_points)
            usernames.push_back(kv.first);

        // Set current select.
        string selected_username;
        int selected_username_idx = -1;

        if (!usernames.empty())
        {
            selected_username_idx = 0;
            selected_username = usernames[0];
        }

        // Show test menu - summary of a test.
        ui::UI::get().test_menu_->show(test_data.name, username, test_data.questions.size(),
                                       test_data.users_points, test_data.reported_issues, selected_username);

        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        while (true)
        {
            INPUT_RECORD input_record_buffer;
            DWORD events;
            PeekConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (events <= 0)
                continue;

            ReadConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (!input_record_buffer.Event.KeyEvent.bKeyDown)
                continue;

            const WORD &user_input = input_record_buffer.Event.KeyEvent.wVirtualKeyCode;

            switch (user_input)
            {
                case 13:  // RETURN
                    if (!selected_username.empty())
                        return {control::test_menu::OptionType::kReview, selected_username};
                    return {control::test_menu::OptionType::kTake, username};
                case 'q':
                case 'Q':
                    return {control::test_menu::OptionType::kQuit, ""};
                case 'e':
                case 'E':
                    return {control::test_menu::OptionType::kEdit, ""};
                case 38:  // Up.
                    if (selected_username_idx > 0)
                        selected_username = usernames[--selected_username_idx];
                    break;
                case 40:  // Down.
                    if (selected_username_idx < usernames.size() - 1)
                        selected_username = usernames[++selected_username_idx];
                    break;
                default:
                    ;

            }
            // Update test menu UI.
            ui::UI::get().test_menu_->show(test_data.name, username, test_data.questions.size(),
                                           test_data.users_points, test_data.reported_issues, selected_username);
        }
    }
}

