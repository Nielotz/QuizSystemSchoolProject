//
// Created by Nielotz on 2021-12-17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../headers/database/user.h"

using namespace std;

namespace database
{

    optional<UserData> user::get_user(const string& username, const string& password)
    {
        return {{"TestUsername", "TestPassword", AccountType::kStudent}};

        /*
        string path = "database/database_user.txt";
        if (path.empty())
            throw runtime_error("Path to the user database need to be set!");

        //If file exist?
        ifstream file_save(path.c_str());
        if (file_save.good() == 0)
        {
            cout << "AAAAA File doesn't exist!!! What I should to do?\n";
        }
        file_save.close();

        ifstream input(path, ios::out);
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

            users_.emplace(r_username, UserData{r_username, r_password, AccountType(stoi(userdata_element))});
        }*/
    }
}
