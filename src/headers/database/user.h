//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_DATABASE_USER_H
#define SRC_DATABASE_USER_H

#include <unordered_map>

#include "../shared/user_data.h"

using namespace std;

namespace Database
{
    class User
    {
    private:
        unordered_map<string, UserData> users_;

    public:
        User();
        UserData get_user(const string& username, const string& password);
    };
}

#endif //SRC_DATABASE_USER_H
