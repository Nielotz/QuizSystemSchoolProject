#include "../src/headers/database/user.h"
#include "cassert"

void run_test_user_database()
{
    database::user::path = "../database_user.txt";

    // Test student.
    {
        UserData expected_user_data = {"student", "pass", AccountType::kStudent};
        std::optional<UserData> received_user_data = database::user::get_user("student", "pass");
        assert(received_user_data.has_value());
        assert(expected_user_data.password == received_user_data->password);
        assert(expected_user_data.username == received_user_data->username);
        assert(expected_user_data.account_type == received_user_data->account_type);
    }

    // Test teacher.
    {
        UserData expected_user_data = {"teacher", "pass", AccountType::kTeacher};
        std::optional<UserData> received_user_data = database::user::get_user("teacher", "pass");
        assert(received_user_data.has_value());
        assert(expected_user_data.password == received_user_data->password);
        assert(expected_user_data.username == received_user_data->username);
        assert(expected_user_data.account_type == received_user_data->account_type);
    }

    // Test invalid.
    {
        std::optional<UserData> received_user_data = database::user::get_user("not_existing", "pass");
        assert(!received_user_data.has_value());
    }
}
