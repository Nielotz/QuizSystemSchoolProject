#include <iostream>
#include <memory>
#include <Windows.h>

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
            this->test_selector_ = std::make_shared<test_selector::Student>();
            this->test_menu_ = std::make_shared<test_menu::Student>();
        }
        else
        {
            this->test_selector_ = std::make_shared<test_selector::Teacher>();
            this->test_menu_ = std::make_shared<test_menu::Teacher>();
        }
    }

    void UI::set_console_text_color(const int text_color) {
        static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, text_color);
    }

    void UI::set_console_text_background_color(const int text_color, const int background_color) {
        static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, background_color << 4 | text_color);
    }

    void UI::color_reset() {
        static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, 7); // reset color
    }

    void UI::print_logo()
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout << "       =========================================================================================================" << std::endl;
        std::cout << "       =                                            ";
        UI::set_console_text_color(3);
        std::cout << "Quiz system                                            ";
        UI::color_reset();
        std::cout << "    =" << std::endl;
        std::cout << "       =========================================================================================================" << std::endl;
    }

    std::string UI::ask_for(const std::string& what, const std::string &entered_string)
    {
        std::cout << "Please provide: " << what;
        return what;
    }
}





