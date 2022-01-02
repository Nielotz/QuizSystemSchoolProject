//
// Created by Nielotz on 2021-12-17.
//
#include "../headers/database/user.h"

using namespace std;

namespace Database
{
	void User::UserDatabase()
	{

	}

	UserData User::set_user(string username_, string password_)
	{
		UserData ud("", "", AccountType::Teacher_);
		return ud;
	}

	User::User(unordered_map<string, UserData> users_)
	{
		this->users_ = users_;
	}
}