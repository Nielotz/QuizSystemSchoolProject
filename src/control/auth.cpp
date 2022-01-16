#include "../headers/control/auth.h"
#include "../headers/ui/auth.h"

namespace Control
{
    string Auth::get_username()
    {
        UI::Auth::ask_username(false, "");
        

        return "TestUsername";
    }

    string Auth::get_password()
    {
        return "TestPassword";
    }

    pair<string, string> Auth::get_auth_data()
    {
        return {Auth::get_username(), Auth::get_password()};
    }
}
