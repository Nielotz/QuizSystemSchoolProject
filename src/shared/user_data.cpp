//
// Created by Ula on 2021-12-27.
//
#include "../headers/shared/user_data.h"

using namespace std;

UserData::UserData(string username, string password, AccountType account_type)
{
	this->username = username;
	this->password = password;
	this->account_type = account_type;
}