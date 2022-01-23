#include <optional>
#include <cassert>

#include "test.h"

#include "../src/headers/auth.h"
#include "../src/headers/database/user.h"

namespace test
{
    namespace log_in
    {
        void login(const std::string &username, const std::string &password)
        {
            std::optional<UserData> received_user_data = database::user::get_user(username, password);
            assert(received_user_data.has_value());
        }

    }
}
