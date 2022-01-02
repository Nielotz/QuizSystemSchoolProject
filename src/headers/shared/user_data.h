//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_USER_DATA_H
#define SRC_USER_DATA_H

#include <string>

#include "../headers/shared/account_type.h"

struct UserData
{
	std::string username;
	std::string password;
	AccountType account_type;
	UserData(std::string username, std::string password, AccountType account_type);
};

#endif //SRC_USER_DATA_H
