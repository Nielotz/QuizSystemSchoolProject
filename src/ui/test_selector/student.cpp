#include <iostream>
#include <windows.h>

#include "../../headers/ui/test_selector/student.h"
#include "../../headers/ui/ui.h"
#include "../../headers/database/test.h"

using namespace std;

void ui::test_selector::Student::ask_select_test(vector<string> tests, string selected_answer)
{
    system("CLS");

    ui::UI::print_logo();

    cout << "  =====================" << endl;
    cout << "  + Selection of test +" << endl;
    cout << "  =====================" << endl << endl;

    cout << "  Avilable tests:" << endl;

    for (auto& test : tests)
    {
        if (test == selected_answer)
        {
            cout << "    ";
            ui::UI::text_background_color(0, 3); 
            cout << selected_answer << endl;
            ui::UI::color_reset();
        }

        else
        {
            cout << "    " << test << endl;
        }
    }

    cout << endl;
    cout << "o-open, q-quit";
}