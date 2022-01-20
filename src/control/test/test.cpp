#include <Windows.h>

#include "../../headers/test_data/test_data.h"
#include "../../headers/control/test/test.h"
#include "../../headers/ui/test/test.h"

namespace control::test
{
    using std::string;
    using std::vector;

    test_data::TestData edit(test_data::TestData test_data, const string &username)
    {
        return test_data;
    }

    void review(const test_data::TestData &test_data, const string &username)
    {
        const int &amount_of_questions = int(test_data.questions.size());

        if (amount_of_questions == 0)
            return;

        int current_question_idx = 0;
        const test_data::Question &first_question = test_data.questions[0];

        ui::test::show_review_question(first_question.question, first_question.answers,
                                       first_question.correct_answers, first_question.students_answers.at(username),
                                       current_question_idx + 1, amount_of_questions);

        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        while (true)
        {
            INPUT_RECORD input_record_buffer;
            DWORD events;
            PeekConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (events <= 0)
                continue;

            ReadConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (!input_record_buffer.Event.KeyEvent.bKeyDown)
                continue;

            const WORD &user_input = input_record_buffer.Event.KeyEvent.wVirtualKeyCode;

            switch (user_input)
            {
                case 'q':
                case 'Q':
                    return;
                case 'r':
                case 'R':
                    // Report.
                    return;
                case 39:  // Left.
                    if (current_question_idx > 0)
                        --current_question_idx;
                    break;
                case 41:  // Right.
                    if (current_question_idx < amount_of_questions - 1)
                        ++current_question_idx;
                    break;
                default:;
            }
            const test_data::Question &question = test_data.questions[current_question_idx];
            ui::test::show_review_question(question.question, question.answers,
                                           question.correct_answers, question.students_answers.at(username),
                                           current_question_idx + 1, amount_of_questions);
        }
    }

    test_data::TestData take(test_data::TestData test_data, const string &username)
    {
        const int &amount_of_questions = int(test_data.questions.size());

        if (amount_of_questions == 0)
            return test_data;

        int current_question_idx = 0;
        const test_data::Question &first_question = test_data.questions[0];

        string selected_answer;
        int selected_answer_idx = -1;
        if (!first_question.answers.empty())
        {
            selected_answer_idx = 0;
            selected_answer = first_question.answers[selected_answer_idx];
        }

        ui::test::show_take_question(first_question.question, first_question.answers, first_question.students_answers.at(username),
                                     selected_answer, current_question_idx + 1, amount_of_questions);

        // Get the standard input handle.
        HANDLE handle_stdin = GetStdHandle(STD_INPUT_HANDLE);

        while (true)
        {
            INPUT_RECORD input_record_buffer;
            DWORD events;
            PeekConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (events <= 0)
                continue;

            ReadConsoleInput(handle_stdin, &input_record_buffer, 1, &events);
            if (!input_record_buffer.Event.KeyEvent.bKeyDown)
                continue;

            const WORD &user_input = input_record_buffer.Event.KeyEvent.wVirtualKeyCode;

            switch (user_input)
            {
                case 13:  // RETURN.
                {
                    bool found = false;
                    const vector<string> &marked_ = test_data.questions[current_question_idx].students_answers.at(username);
                    for (int i = 0; i < marked_.size(); i++)
                        if (marked_[i] == selected_answer)
                        {
                            test_data.questions[current_question_idx].students_answers.at(username).erase(marked_.begin() + i);
                            found = true;
                            break;
                        }
                    if (!found)
                        test_data.questions[current_question_idx].students_answers.at(username).emplace_back(selected_answer);
                    break;
                }
                case 'q':
                case 'Q':
                    return test_data;
                case 39:  // Left.
                    if (current_question_idx > 0)
                        --current_question_idx;
                    break;
                case 41:  // Right.
                    if (current_question_idx < amount_of_questions - 1)
                        ++current_question_idx;
                    break;
                case 38:  // Up.
                    if (selected_answer_idx > 0)
                        selected_answer = test_data.questions[current_question_idx].answers.at(--selected_answer_idx);
                    break;
                case 40:  // Down.
                    if (selected_answer_idx < test_data.questions[current_question_idx].answers.size() - 1)
                        selected_answer = test_data.questions[current_question_idx].answers.at(++selected_answer_idx);
                    break;
                default:;
            }
            const test_data::Question &question = test_data.questions[current_question_idx];
            ui::test::show_take_question(question.question, question.answers,
                                         question.students_answers.at(username),
                                         selected_answer, current_question_idx + 1, amount_of_questions);
        }
    }
}
