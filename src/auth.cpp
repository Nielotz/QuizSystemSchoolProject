#include <optional>

#include "headers/auth.h"
#include "headers/control/auth.h"
#include "headers/database/user.h"

UserData Auth::login()
{
    while (true)
    {
        auto received_user_credentials = Control::Auth::get_auth_data();
        const string &username = received_user_credentials.first;
        const string &password = received_user_credentials.second;

        optional <UserData> received_user_data = Database::User::get_user(username, password);
        if (received_user_data.has_value())
            return *received_user_data;
    }
}
