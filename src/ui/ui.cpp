#include <iostream>
//#include <stdlib.h>
#include <windows.h>

#include "..\headers\ui\ui.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void UI::UI::print_logo()
{
    cout << "       =========================================================================================================" << endl;
    cout << "       =                                            ";
    SetConsoleTextAttribute(h, 3);
    cout << "Quiz system                                            ";
    SetConsoleTextAttribute(h, 7);
    cout << "    ="<<endl;
    cout<<"       =========================================================================================================" << endl;
}
