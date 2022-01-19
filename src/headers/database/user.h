#ifndef SRC_DATABASE_USER_H
#define SRC_DATABASE_USER_H

#include <optional>

#include <unordered_map>

#include "../shared/user_data.h"

namespace database::user
{
    std::optional<UserData> get_user(const std::string &username, const std::string &password);
};


#endif //SRC_DATABASE_USER_H
