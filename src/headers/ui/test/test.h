#ifndef SRC_UI_TEST_TEST_H
#define SRC_UI_TEST_TEST_H

#include <string>
#include <vector>

namespace ui::test
{
	void show_edit_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers, std::string selected_answer, int question_number, int question_amount);
	void show_review_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers, std::vector<std::string> marked_answers, std::string selected_answer, int question_number, int question_amount);
	void show_take_question(std::string question, std::vector<std::string> answers, std::vector<std::string> marked_answers, std::string selected_answer, int question_number, int question_amount);
}	void add_test(std::string entered_name);

#endif //SRC_UI_TEST_TEST_H
