#include <string>
#include <vector>
#include <iostream>

#include "../../headers/ui/test_selector/test_selector.h"
#include "../../headers/ui/ui.h"
#include "../../headers/database/test.h"

using namespace std;

namespace UI::TestSelector
{
    void TestSelector::ask_select_test(vector<string> tests, string selected_answer)
    {
        system("CLS");

        UI::UI::print_logo();

        cout << "  =====================" << endl;
        cout << "  + Selection of test +" << endl;
        cout << "  =====================" << endl << endl;

        cout << "  Avilable tests:" << endl;

        for (auto &test: tests)
        {
            cout << "    " << test << endl;
        }

        cout << "o-open, q-quit";
    }
}
