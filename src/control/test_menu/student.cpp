#include "../../headers/control/test_menu/student.h"
#include "../../headers/ui/ui.h"

namespace control::test_menu
{
    control::test_menu::OptionType Student::control_test_menu_selection(std::string username, test_data::TestData test_data)
    {
        std::string selected_username;

        // If user took the test, set selected_username to be username.
        if (test_data.users_points.contains(username))
            selected_username = username;

        // Show test menu - summary of a test.
        ui::UI::get().test_menu_->show(test_data.name, username, test_data.questions.size(),
                                       test_data.users_points, selected_username);

        // TODO: Handle user option.

        return OptionType::kTake;

        std::string selected_test;
        int selected_test_idx = -1;

        if (!tests_names.empty())
        {
            selected_test = tests_names[0];
            selected_test_idx = 0;
        }

        ui::UI::get().test_selector_->ask_select_test(tests_names, selected_test);

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
                    if (!selected_test.empty())
                        return selected_test;
                case 'q':
                case 'Q':
                    return "";
                case 'n':
                case 'N':
                    return "[Create]";
                case 'd':
                case 'D':
                    if (selected_test.empty())
                        break;
                    database::test::delete_test(selected_test);
                    tests_names.erase(tests_names.begin() + selected_test_idx);
                    selected_test_idx--;
                    if (selected_test_idx > -1)
                        selected_test = tests_names[selected_test_idx];
                    else
                    {
                        if (!tests_names.empty())
                        {
                            selected_test = tests_names[0];
                            selected_test_idx = 0;
                        }
                        else
                            selected_test = "";
                    }
                case 38:
                    if (selected_test_idx > 0)
                        selected_test = tests_names[--selected_test_idx];
                    break;
                case 40:
                    if (selected_test_idx < tests_names.size() - 1)
                        selected_test = tests_names[++selected_test_idx];
                    break;
                default:;
            }
            ui::UI::get().test_selector_->ask_select_test(tests_names, selected_test);
        }
    }
}

