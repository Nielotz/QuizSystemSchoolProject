#include <iostream>

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
        cout << "    " << test << endl;
    }

    cout << "o-open, q-quit";
}