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
        int current_question_idx = -1;
        if (!test_data.questions.empty())
            current_question_idx = 0;

        const test_data::Question &question = test_data.questions[current_question_idx];

        const int &amount_of_questions = int(question.question.size());

        ui::test::show_review_question(question.question, question.answers, question.correct_answers,
                                       question.students_answers.at(username),
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
                    // Report
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
            ui::test::show_review_question(question.question, question.answers, question.correct_answers,
                                           question.students_answers.at(username),
                                           current_question_idx + 1, amount_of_questions);
        }
    }

    test_data::TestData take(test_data::TestData test_data, const string &username)
    {
        return test_data;
    }
}
