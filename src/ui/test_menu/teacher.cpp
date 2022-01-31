#include <iostream>

#include "../../headers/ui/test_menu/teacher.h"
#include "../../headers/ui/ui.h"
#include "../../headers/test_data/test_data.h"

void ui::test_menu::Teacher::show(std::string test_name, std::string username,
	size_t amount_of_questions,
	std::map<std::string, int> users_points, std::vector<std::pair<std::string, std::string>> reported_issues, std::string selected_answer)
{
	system("CLS");

	ui::UI::print_logo();

	std::cout << "  =============" << std::endl;
	std::cout << "  + Test Menu +" << std::endl;
	std::cout << "  =============" << std::endl << std::endl;

	std::cout << "  Test: <" << test_name << ">" << std::endl;
	std::cout << "      Number of questions: " << amount_of_questions << std::endl << std::endl;

	std::cout << "  Completed tests:" << std::endl;
	for (auto& [username_, points] : users_points)
	{
		if (selected_answer == username_)
		{
			std::cout << "       ";
			ui::UI::set_console_text_background_color(0, 3);
			std::cout << username_;
			ui::UI::color_reset();
			std::cout << " <" << points << "> / <" << amount_of_questions << ">" << std::endl;
		}
		else
			std::cout << "      " << username_ << " <" << points << "> / <" << amount_of_questions << ">" << std::endl;
	}

	std::cout << "  <test reports>:" << std::endl;
	for (auto& [username_, content] : reported_issues)
	{
		if (username_ == selected_answer)
		{
			ui::UI::set_console_text_background_color(0, 3);
			std::cout << username_;
			ui::UI::color_reset();
		}
		else
			std::cout << username_;

		std::cout << ": " << content << std::endl;
	}
	std::cout << "q - quit, e - edit, enter - show student answers";
}
