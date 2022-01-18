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
        
        User() = default;
    public:
        //static unordered_map<string, UserData> users_;
        static UserData get_user(const string &username, const string &password);
        //static UserData insert_user(const string &username, const string &password, const AccountType type);
        User(User const &) = delete;
        void operator=(User const &) = delete;
    };
}

#endif //SRC_DATABASE_USER_H
