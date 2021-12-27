#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_USER_DATA_CPP
#define SRC_USER_DATA_CPP

#include user_data.h

UserData::UserData(string username, string password, AccountType account_type)
{
	this->username = username;
	this->password = password;
	this->account_type = account_type;
}

#endif //SRC_USER_DATA_CPP