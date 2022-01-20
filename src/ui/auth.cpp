#pragma once

#include <iostream>
#include <string>
#include <cstdlib>  // For system().
#include <iomanip>  // For setw and setfill.

#include "../headers/ui/auth.h"
#include "../headers/ui/ui.h"

namespace ui::auth
{
   void ask_username(bool is_retry, const std::string& entered_username)
    {
       system("CLS");

       UI::UI::print_logo();

       std::cout <<"  ==============" << std::endl;
       std::cout <<"  + Logging in +" << std::endl;
       std::cout <<"  ==============" << std::endl << std::endl;

       if (is_retry)
       {
           std::cout << "Invalid auth data. Try again." << std::endl;
       }

       std::cout << "    USERNAME: " << entered_username;
    }

    void ask_password(const std::string& username, bool is_retry, size_t amount_of_entered_chars)
    {
        system("CLS");
        ask_username(is_retry, username);
        std::cout << std::endl;
        std::cout << "    PASSWORD: " << std::setw(amount_of_entered_chars) << std::setfill('*') << "";
    }
}



