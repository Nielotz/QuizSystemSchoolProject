#ifndef SRC_DATABASE_USER_H
#define SRC_DATABASE_USER_H

#include <optional>

#include <unordered_map>

#include "../shared/user_data.h"

using namespace std;

namespace database::user
{
    optional<UserData> get_user(const string &username, const string &password);
};


#endif //SRC_DATABASE_USER_H
