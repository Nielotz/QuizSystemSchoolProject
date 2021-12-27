#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_USER_MANAGER_CPP
#define SRC_USER_MANAGER_CPP

#include user_manager.h

UserManager::UserManager(UserData user_data)
{
	this->user_data = user_data;
}

bool UserManager::attempt_user_login()
{
	return false;
}

#endif //SRC_USER_MANAGER_CPP