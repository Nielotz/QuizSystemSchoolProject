#include <iostream>

#include "../../headers/ui/test_selector/teacher.h"
#include "../../headers/ui/ui.h"
#include "../../headers/database/test.h"

void ui::test_selector::Teacher::ask_select_test(std::vector<std::string> tests, std::string selected_answer)
{
    system("CLS");

    ui::UI::print_logo();

    std::cout << "  =====================" << std::endl;
    std::cout << "  + Selection of test +" << std::endl;
    std::cout << "  =====================" << std::endl << std::endl;

    std::cout << "  Available tests:" << std::endl;

    for (auto& test : tests)
    {
        if (test == selected_answer)
        {
            std::cout << "    ";
            ui::UI::set_console_text_background_color(0, 3);
            std::cout << selected_answer << std::endl;
            ui::UI::color_reset();
        }

        else
        {
            std::cout << "    " << test << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "controls - ↓ ↑, enter - open, d - delete, n - new, , q - quit";
}
    