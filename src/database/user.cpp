//
// Created by Nielotz on 2021-12-17.
//

#include "../headers/database/user.h"

using namespace std;

namespace Database
{
	UserData User::set_user(string username, string password)
	{
		UserData ud("", "", AccountType::kTeacher);
		return ud;
	}

	User::User(unordered_map<string, UserData> users)
	{
		this->users = users;
	}
}