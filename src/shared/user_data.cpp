#include <utility>

#include "../headers/shared/user_data.h"

using namespace std;

UserData::UserData(string username, string password, AccountType account_type)
{
	this->username = std::move(username);
	this->password = std::move(password);
	this->account_type = account_type;
}