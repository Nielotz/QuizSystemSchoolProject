
#ifndef SRC_UI_TEST_TEST_H
#define SRC_UI_TEST_TEST_H

#include <string>
#include <vector>

namespace ui::test
{
    void show_edit_question(const std::string &test_name, const std::string &question, const std::vector<std::string> &answers,
                            const std::vector<std::string> &correct_answers, const std::string &selected_answer, int question_number,
                            int question_amount);

    void show_review_question(const std::string &test_name, const std::string &question, const std::vector<std::string> &answers,
                              const std::vector<std::string> &correct_answers, const std::vector<std::string> &marked_answers,
                              int question_number, int question_amount);

    void show_take_question(const std::string &test_name, const std::string &question, const std::vector<std::string> &answers,
                            const std::vector<std::string> &marked_answers, int question_number, int question_amount);
}
#endif //SRC_UI_TEST_TEST_H