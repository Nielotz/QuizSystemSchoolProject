#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/database/user.h"

namespace database
{
    std::optional<UserData> user::get_user(const string& username, const string& password)
    {
        if (database::user::path.empty())
            throw std::exception("<user database> Path to the user database need to be set!");

        std::ifstream input(path, std::ios::out);

        // If file exist?
        if (input.good() == 0)
            throw std::exception("<user database> File at the specified location does not exist!");

        string userdata_line;

        while (getline(input, userdata_line))
        {
            std::istringstream userdata_stream(userdata_line);
            string userdata_element;

            string r_username;
            string r_password;
            getline(userdata_stream, r_username, '|');
            getline(userdata_stream, r_password, '|');
            getline(userdata_stream, userdata_element, '|');

            if (username == r_username && password == r_password)
            {
                input.close();
                return {{r_username, r_password, AccountType(stoi(userdata_element))}};
            }
        }
        input.close();
        throw std::exception("<user database> Error reading file.");
    }
}
