#define _HAS_STD_BYTE 0

#include <windows.h>
#include <cctype>

#include "../headers/control/auth.h"
#include "../headers/control/control.h"
#include "../ui/auth.cpp"  // When import ../headers/ui/auth.h C++ goes brrr.

namespace control
{
    std::string auth::get_username(bool is_retry)
    {
        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        std::string entered_username;
        ui::auth::ask_username(is_retry, "");

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
                const WORD& user_input = input_record_buffer.Event.KeyEvent.wVirtualKeyCode;

                switch (user_input)
                {
                    case 13:  // RETURN
                        return entered_username;
                    case 8:  // BACKSPACE
                        if (!entered_username.empty())
                        {
                            entered_username.pop_back();
                            ui::auth::ask_username(is_retry, entered_username);
                        }
                        break;
                    default:
                        if (isprint(user_input) && user_input < 256)
                        {
                            entered_username.push_back(char(user_input));
                            ui::auth::ask_username(is_retry, entered_username);
                        }
                }
            }
        }
    }

    std::string auth::get_password(const std::string& username, bool is_retry)
    {
        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        std::string entered_password;
        ui::auth::ask_password(username, is_retry, entered_password.size());

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
                const WORD& user_input = input_record_buffer.Event.KeyEvent.wVirtualKeyCode;

                switch (user_input)
                {
                    case 13:  // RETURN
                        return entered_password;
                    case 8:  // BACKSPACE
                        if (!entered_password.empty())
                        {
                            entered_password.pop_back();
                            ui::auth::ask_password(username, is_retry, entered_password.size());
                        }
                        break;
                    default:
                        if (isprint(user_input) && user_input < 256)
                        {
                            entered_password.push_back(char(user_input));
                            ui::auth::ask_password(username, is_retry, entered_password.size());
                        }
                }
            }
        }
    }

    std::pair<std::string, std::string> auth::get_auth_data(bool is_retry)
    {
        const std::string& username = auth::get_username(is_retry);

        return std::pair<std::string, std::string>{username, auth::get_password(username, is_retry)};
    }
}
