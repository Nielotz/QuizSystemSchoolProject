//
// Created by Nielotz on 2021-12-17.
//
#include "../headers/auth/auth.h"

namespace Auth
{
        pair <string, string> Auth::ask_data()
        {
            pair<string, string> auth;
            return auth;
        }

        UserData Auth::check_data()
        {
            UserData ud("", "", AccountType::Student_);
            return ud;
        }

        Auth::Auth()
        {

        }
      
        UserData Auth::attemp_login()
        {
            UserData ud("", "", AccountType::Student_);
            return ud;
        }
}