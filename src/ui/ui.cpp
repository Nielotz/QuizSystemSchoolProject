#include <iostream>
#include <memory>
#include <windows.h>

#include "../headers/ui/ui.h"
#include "../headers/ui/test_selector/student.h"
#include "../headers/ui/test_selector/teacher.h"
#include "../headers/ui/test_menu/student.h"
#include "../headers/ui/test_menu/teacher.h"

namespace ui
{
    bool ui::UI::initialized = false;
    AccountType ui::UI::account_type_ = AccountType::kStudent;
    void UI::init(AccountType account_type)
    {
        UI::account_type_ = account_type;
        UI::initialized = true;
    }

    UI UI::get()
    {
        if (!initialized)
            throw std::exception("Using not initialized UI.");
        static UI ui;
        return ui;
    }

    UI::UI()
    {
        if (UI::account_type_ == AccountType::kStudent)
        {
            this->test_selector_ = make_shared<test_selector::Student>();
            this->test_menu_ = make_shared<test_menu::Student>();
        }
        else
        {
            this->test_selector_ = make_shared<test_selector::Teacher>();
            this->test_menu_ = make_shared<test_menu::Teacher>();
        }
    }

    void UI::print_logo()
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "       =========================================================================================================" << endl;
        cout << "       =                                            ";
        SetConsoleTextAttribute(handle, 3);
        cout << "Quiz system                                            ";
        SetConsoleTextAttribute(handle, 7);
        cout << "    =" << endl;
        cout << "       =========================================================================================================" << endl;
    }
}





