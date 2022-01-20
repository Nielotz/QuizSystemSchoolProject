//
// Created by Nielotz on 2021-12-17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../headers/database/user.h"

namespace database
{

    std::optional<UserData> user::get_user(const std::string& username, const std::string& password)
    {
        if (path.empty())
        {
            cout << "<user database>Path to the user database need to be set!";
            return{};
        }

        ifstream input(path, ios::out);
        //If file exist?
        if (input.good() == 0)
        {
            cout << "<user database>File at the specified location does not exist!";
            return{};
        }
        
        string userdata_line;

        while (getline(input, userdata_line))
        {
            istringstream userdata_stream(userdata_line);
            string userdata_element;
            //cout << "\nlinia: " << csvLine << endl;

            string r_username;
            string r_password;
            getline(userdata_stream, r_username, '|');
            getline(userdata_stream, r_password, '|');
            getline(userdata_stream, userdata_element, '|');

            if (username == r_username && password == r_password)
            {
                input.close();
                return{ r_username, r_password, AccountType(stoi(userdata_element)) };
            }
        }
        input.close();
        return{};

    }

    /*UserData User::insert_user(const string& username, const string& password, const AccountType type)
    {

    }*/
}
