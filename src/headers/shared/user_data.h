//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_USER_DATA_H
#define SRC_USER_DATA_H

#import account_type.h

class UserData
{
public:
	string username;
	string password;
	AccountType account_type;
	UserData(string username, string password, AccountType account_type);
};


#endif //SRC_USER_DATA_H
