#include "../headers/control/auth.h"
#include "../headers/ui/auth.h"

namespace Control
{
    string Auth::get_username()
    {
        return "TestUsername";
    }

    string Auth::get_password()
    {
        return "TestPassword";
    }

    pair<string, string> Auth::get_auth_data(bool is_retry)
    {
        UI::Auth::ask_username(is_retry, "");
        string username = Auth::get_username();
        UI::Auth::ask_password(username, is_retry, 0);
        return {username, Auth::get_password()};
    }
}
