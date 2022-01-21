#include "../headers/control/control.h"
#include "../headers/control/test_selector/student.h"
#include "../headers/control/test_selector/teacher.h"
#include "../headers/control/test_menu/student.h"
#include "../headers/control/test_menu/teacher.h"
#include "../headers/ui/ui.h"

namespace control
{
    Control::Control(AccountType account_type)
    {
        if (account_type == AccountType::kStudent)
        {
            test_selector_ = std::make_shared<test_selector::Student>();
            test_menu_ = std::make_shared<test_menu::Student>();
        }
        else
        {
            test_selector_ = std::make_shared<test_selector::Teacher>();
            test_menu_ = std::make_shared<test_menu::Teacher>();
        }
    }

    std::string get_safe_string_from_user(const std::string &string_description)
    {
        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        std::string entered_answer;
        ui::UI::ask_for(string_description, entered_answer);

        while (true)
        {
            INPUT_RECORD input_record_buffer;
            DWORD events;

            PeekConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (events > 0)
            {
                ReadConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
                if (!input_record_buffer.Event.KeyEvent.bKeyDown)
                    continue;
                const WORD &user_input = input_record_buffer.Event.KeyEvent.uChar.AsciiChar;

                switch (user_input)
                {
                    case 13:  // RETURN
                        return entered_answer;
                    case 8:  // BACKSPACE
                        if (!entered_answer.empty())
                        {
                            entered_answer.pop_back();
                            ui::UI::ask_for(string_description, entered_answer);
                        }
                        break;
                    default:
                        if (isprint(user_input) && user_input < 256)
                        {
                            entered_answer.push_back(char(user_input));
                            ui::UI::ask_for(string_description, entered_answer);
                        }
                }
            }
        }
    }

    bool get_yes_no_answer(const std::string &question)
    {
        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        bool marked_answer = false;
        ui::UI::confirmation(question, marked_answer);

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
                    return marked_answer;
                case 38:
                    marked_answer = false;
                    break;
                case 40:
                    marked_answer = true;
                    break;
                default:;
            }
        }
    }


}


