#include "../headers/control/auth.h"
#include "../ui/auth.cpp"  // When import ../headers/ui/auth.h C++ goes brrr .

namespace control
{
    string auth::get_username()
    {
        // TODO: control getting username.
        return "TestUsername";
    }

    string auth::get_password()
    {
        // TODO: control getting password.
        return "TestPassword";
    }

    pair<string, string> auth::get_auth_data(bool is_retry)
    {
        ui::auth::ask_username(is_retry, "");

        string username = auth::get_username();

        constexpr int amount_of_entered_chars = 0;
        ui::auth::ask_password(username, is_retry, amount_of_entered_chars);

        return pair<string, string>{username, auth::get_password()};
    }
}
