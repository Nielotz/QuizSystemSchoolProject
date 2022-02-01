#ifndef SRC_DATABASE_USER_H
#define SRC_DATABASE_USER_H

#include <optional>

#include "../shared/user_data.h"

namespace database::user
{
    using std::string;
    const string path = "../../../database/database_user.txt";
    std::optional<UserData> get_user(const string &username, const string &password);
}


#endif //SRC_DATABASE_USER_H
