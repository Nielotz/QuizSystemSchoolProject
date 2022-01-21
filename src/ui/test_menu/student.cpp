#include <iostream>

#include "../../headers/ui/test_menu/student.h"
#include "../../headers/ui/ui.h"

void ui::test_menu::Student::show(std::string test_name, std::string username, size_t amount_of_questions,
                                  std::map<std::string, int> users_points, std::vector<std::pair<std::string, std::string>> reported_issues,
                                  std::string selected_answer)
{
    system("CLS");

    ui::UI::print_logo();

    std::cout << "  =============" << std::endl;
    std::cout << "  + Test Menu +" << std::endl;
    std::cout << "  =============" << std::endl << std::endl;

    std::cout << "  Test: <" << test_name << ">" << std::endl;
    std::cout << "      Number of questions: " << amount_of_questions << std::endl << std::endl;

    std::cout << "  Completed test:" << std::endl;
    for (auto&[username_, points]: users_points)
    {
        if (username_ == username)
        {
            ui::UI::set_console_text_background_color(0, 3);
            std::cout << "      " << username_ << " <" << points << ">/<" << amount_of_questions << ">" << std::endl;
            ui::UI::color_reset();
            break;
        }
    }

    std::cout << "  <test reports>:" << std::endl;
    for (auto&[username_, issue]: reported_issues)
    {
        if (username_ == username)
            std::cout << "      " << username_ << issue << std::endl;
    }

    std::cout << std::endl;
    std::cout << "enter - take / review, q - quit";
}
