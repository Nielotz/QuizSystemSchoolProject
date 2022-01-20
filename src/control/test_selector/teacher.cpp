#include <Windows.h>
#include <cctype>
#include <iostream>

#include "../../headers/control/test_selector/teacher.h"
#include "../../headers/ui/ui.h"
#include "../../headers/database/test.h"

namespace control::test_selector
{
    std::string Teacher::control_test_selection(std::vector<std::string> tests_names)
    {
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

            const WORD &user_input = input_record_buffer.Event.KeyEvent.uChar.AsciiChar;

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
