#include <iostream>

#include "../../headers/ui/test_menu/student.h"
#include "../../headers/ui/ui.h"
#include "../../headers/test_data/test_data.h"

void ui::test_menu::Student::show(std::string test_name, std::string username, size_t amount_of_questions, std::unordered_map<std::string, int> users_points,
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
	for (auto& [username_, points] : users_points)
	{
		if(username_== username)
		std::cout << "      " << username_ << " <" << points << "> / < " << amount_of_questions << std::endl;
	}

	std::cout << std::endl;
	std::cout << "s - show, q - quit";
}
