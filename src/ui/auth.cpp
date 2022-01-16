#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

#include "../headers/ui/auth.h"

namespace UI
{
   void Auth::ask_username(bool is_retry, string entered_username)
    {
       system("CLS");


       cout << "==============" << endl;
       cout << "+ Logging in +" << endl;
       cout << "==============" << endl << endl;
       cout << "username: ";
    }

    void Auth::ask_password(string username, bool is_retry, int ammount_of_entered_chars)
    {
        system("CLS");
        cout << "Quiz system" << endl;
        cout << "Logging in" << endl;
        cout << "username: " << username << endl;
        cout << "password: ";

        system("CLS");

        cout << "Quiz system" << endl;
        cout << "Logging in" << endl << endl;
        cout << "Invalid auth data." << endl << endl;
        cout << "press any key to try again" << endl;

        system("CLS");

    }
}



