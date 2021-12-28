//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_USER_H
#define SRC_USER_H

#include <unordered_map>
#import user_data.h

#import test/test_data.h

using namespace std;

class User
{
private:
	unordered_map<string, UserData> users_;

public:
	UserDatabase();
	UserData set_user(string username_, string password_);
	User(unordered_map<string, UserData> users_);
};


#endif //SRC_USER_H
