#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

#include "../headers/ui/auth.h"

namespace UI
{
   static void Auth::ask_username(bool is_retry)
    {
       char c;
       string input;
       const char ENTER = 13;

       cout << "Quiz system" << endl;
       cout << "Logging in" << endl;
       cout << "username: ";

       do
       {
           c = _getch();

           if (isprint(c))
           {
               input += c;
               cout << c;
           }

           else if (c == 8 && !input.empty())
           {
               input.pop_back();
               cout << "\b \b";
           }
       } 
       while (c != ENTER);
       system("CLS");

       UI::Auth::ask_password(input, is_retry);
    }

    static void Auth::ask_password(string username, bool is_retry)
    {
        char c;
        string input;
        const char ENTER = 13;

        cout << "Quiz system" << endl;
        cout << "Logging in" << endl;
        cout << "username: " << username << endl;
        cout << "password: ";

        do
        {
            c = _getch();
            if (isprint(c))
            {
                input += c;
                cout << "*";
            }

            else if (c == 8 && !input.empty())
            {
                input.pop_back();
                cout << "\b \b";
            }
        } while (c != ENTER);

       // if (username == username_ && input == password_)
       // {
       //     is_retry = true;
       // }

        system("CLS");

        if (is_retry == false)
        {
            cout << "Quiz system" << endl;
            cout << "Logging in" << endl << endl;
            cout << "Invalid auth data." << endl << endl;
            cout << "press any key to try again" << endl;
            char c;
            c = _getch();

            system("CLS");
            UI::Auth::ask_username(false);
        }
    }
}



