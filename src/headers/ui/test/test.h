#ifndef SRC_UI_TEST_TEST_H
#define SRC_UI_TEST_TEST_H

#include <string>
#include <vector>

namespace ui::test
{
    using std::string;
    using std::vector;

    void show_edit_question(const string &question, const vector<string> &answers, const vector<string> &correct_answers,
                            const string &selected_answer, int question_number, int question_amount);

    void show_review_question(const string &question, const vector<string> &answers, const vector<string> &correct_answers,
                              const vector<string> &marked_answers, const string &selected_answer, int question_number,
                              int question_amount);

    void show_take_question(const string &question, const vector<string> &answers, const vector<string> &marked_answers,
                            const string &selected_answer, int question_number, int question_amount);
}

#endif //SRC_UI_TEST_TEST_H
