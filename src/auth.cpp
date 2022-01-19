#include <optional>

#include "headers/auth.h"
#include "headers/control/auth.h"
#include "headers/database/user.h"

UserData auth::login()
{
    bool is_retry = false;
    while (true)
    {
        pair<string, string> received_user_credentials = control::auth::get_auth_data(is_retry);
        const string &username = received_user_credentials.first;
        const string &password = received_user_credentials.second;

        optional<UserData> received_user_data = database::user::get_user(username, password);
        if (received_user_data.has_value())
            return *received_user_data;

        is_retry = true;
    }
}
