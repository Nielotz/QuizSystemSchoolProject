#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

#include "../headers/ui/auth.h"
#include "../headers/ui/ui.h"

namespace UI
{
   void Auth::ask_username(bool is_retry, string entered_username)
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

    void Auth::ask_password(string username, bool is_retry, int ammount_of_entered_chars)
    {
        system("CLS");
        ask_username(is_retry, "");
        cout << "   PASSWORD: " << std::setw(ammount_of_entered_chars) << std::setfill('*') << "";
    }
}



