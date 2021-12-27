#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_USER_MANAGER_H
#define SRC_USER_MANAGER_H

#import user_data.h;

class UserManager
{
private:
	UserData user_data;
public:
	UserManager(UserData user_data);
	bool attempt_user_login();
};

#endif //SRC_USER_MANAGER_H
