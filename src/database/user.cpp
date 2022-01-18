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

namespace Database
{

    UserData User::get_user(const string& username, const string& password)
    {
        const string path = "../../../database/database_user.txt";
        if (path.empty())
        {
            cout << "Path to the user database need to be set!";
            return{};
        }

        ifstream input(path, ios::out);
        //If file exist?
        if (input.good() == 0)
        {
            cout << "File at the specified location does not exist!";
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
}
