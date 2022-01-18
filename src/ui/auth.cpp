#include <iostream>
#include <string>
#include <cstdlib>  // For system().
#include <iomanip>  // For setw and setfill.

#include "../headers/ui/auth.h"
#include "../headers/ui/ui.h"

namespace ui
{
   void Auth::ask_username(bool is_retry, const string& entered_username)
    {
       system("CLS");

       UI::UI::print_logo();

       cout <<"  ==============" << endl;
       cout <<"  + Logging in +" << endl;
       cout <<"  ==============" << endl << endl;

       if (is_retry)
       {
           cout << "Invalid auth data. Try again." << endl;
       }

       cout << "    USERNAME: " << entered_username;
    }

    void Auth::ask_password(const string& username, bool is_retry, int amount_of_entered_chars)
    {
        system("CLS");
        ask_username(is_retry, "");
        cout << "   PASSWORD: " << std::setw(amount_of_entered_chars) << std::setfill('*') << "";
    }
}



