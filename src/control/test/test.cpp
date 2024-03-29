#include <Windows.h>

#include "../../headers/test_data/test_data.h"
#include "../../headers/control/test/test.h"
#include "../../headers/ui/test/test.h"
#include "../../headers/control/control.h"

namespace control::test
{
    using std::string;
    using std::vector;


    test_data::TestData edit(test_data::TestData test_data, const string &username)
    {
        int amount_of_questions = int(test_data.questions.size());

        int current_question_idx = -1;
        int selected_answer_idx = -1;

        string selected_answer;

        if (amount_of_questions != 0)
        {
            current_question_idx = 0;
            const test_data::Question &first_question = test_data.questions[0];
            if (!first_question.answers.empty())
            {
                selected_answer_idx = 0;
                selected_answer = first_question.answers[selected_answer_idx];
            }
            ui::test::show_edit_question(test_data.name, first_question.question, first_question.answers,
                                         first_question.correct_answers, selected_answer,
                                         current_question_idx + 1, amount_of_questions);
        }
        else
            ui::test::show_edit_question(test_data.name, "", {}, {}, selected_answer,
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
                case 13:  // RETURN.
                {
                    if (test_data.questions.empty())
                        break;
                    bool found = false;
                    vector<string> &correct = test_data.questions[current_question_idx].correct_answers;

                    for (int i = 0; i < correct.size(); i++)
                        if (correct[i] == selected_answer)
                        {
                            correct.erase(correct.begin() + i);
                            found = true;
                            break;
                        }
                    if (!found)
                        correct.emplace_back(selected_answer);
                    break;
                }

                case 'q':
                case 'Q':
                    return test_data;
                case 'd':
                case 'D':
                    if (selected_answer.empty())
                        break;
                    test_data.questions[current_question_idx].answers.erase(
                            test_data.questions[current_question_idx].answers.begin() + selected_answer_idx);
                    selected_answer_idx--;
                    if (selected_answer_idx > -1)
                        selected_answer = test_data.questions[current_question_idx].answers[selected_answer_idx];
                    else
                    {
                        if (!test_data.questions[current_question_idx].answers.empty())
                        {
                            selected_answer = test_data.questions[current_question_idx].answers[0];
                            selected_answer_idx = 0;
                        }
                        else
                        {
                            selected_answer = "";
                            selected_answer_idx = -1;
                        }
                    }
                    break;
                case 'r':
                case 'R':
                    if (current_question_idx == -1)
                        break;
                    test_data.questions.erase(test_data.questions.begin() + current_question_idx);
                    current_question_idx--;
                    amount_of_questions--;
                    if (current_question_idx == -1 && !test_data.questions.empty())
                        current_question_idx = 0;

                    if (current_question_idx != -1 && !test_data.questions[current_question_idx].answers.empty())
                    {
                        selected_answer_idx = 0;
                        selected_answer = test_data.questions[current_question_idx].answers[0];
                    }
                    else
                    {
                        selected_answer = "";
                        selected_answer_idx = -1;
                    }

                    break;
                case 'a':
                case 'A':
                    if (current_question_idx >= 0)
                    {
                        test_data::Question &question = test_data.questions[current_question_idx];
                        vector<string> &answers = question.answers;

                        const auto &new_answer = get_new_answer();

                        if (std::find(answers.begin(), answers.end(), new_answer) == answers.end())
                        {
                            question.answers.emplace_back(new_answer);
                            if (selected_answer_idx == -1)
                            {
                                selected_answer_idx = 0;
                                selected_answer = new_answer;
                            }
                        }
                    }
                    break;
                case 'n':
                case 'N':
                {
                    const string &new_question = get_new_question();

                    bool exists = false;
                    for (auto &question: test_data.questions)
                        if (question.question == new_question)
                        {
                            exists = true;
                            break;
                        }
                    if (!exists)
                    {
                        test_data.questions.emplace_back(test_data::Question{new_question});

                        amount_of_questions++;
                        current_question_idx = amount_of_questions - 1;
                    }
                }
                    break;
                case 37:  // Left.
                    if (current_question_idx > 0)
                        --current_question_idx;
                    break;
                case 39:  // Right.
                    if (current_question_idx < amount_of_questions - 1)
                        ++current_question_idx;
                    break;
                case 38:  // Up.
                    if (current_question_idx != -1 && selected_answer_idx > 0)
                        selected_answer = test_data.questions[current_question_idx].answers.at(--selected_answer_idx);
                    break;
                case 40:  // Down.
                    if (current_question_idx != -1 && selected_answer_idx + 1 < test_data.questions[current_question_idx].answers.size())
                        selected_answer = test_data.questions[current_question_idx].answers.at(++selected_answer_idx);
                    break;
                default:;
            }
            if (current_question_idx >= 0)
            {
                const test_data::Question &question = test_data.questions[current_question_idx];
                ui::test::show_edit_question(test_data.name, question.question, question.answers,
                                             question.correct_answers, selected_answer,
                                             current_question_idx + 1, amount_of_questions);
            }
            else
                ui::test::show_edit_question(test_data.name, "", {}, {}, selected_answer,
                                             current_question_idx + 1, amount_of_questions);
        }
    }

    test_data::TestData review(test_data::TestData test_data, const string &username)
    {
        const int &amount_of_questions = int(test_data.questions.size());

        if (amount_of_questions == 0)
            return test_data;

        int current_question_idx = 0;
        const test_data::Question &first_question = test_data.questions[0];

        std::vector<std::string> student_answers = test_data.questions[0].students_answers[username];

        ui::test::show_review_question(test_data.name, first_question.question, first_question.answers,
                                       first_question.correct_answers, student_answers,
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

            test_data.questions[current_question_idx].students_answers[username] = student_answers;

            switch (user_input)
            {
                case 'q':
                case 'Q':
                    return test_data;
                case 'r':
                case 'R':
                    test_data.reported_issues.emplace_back(std::pair<string, string>{username, get_new_report()});
                    break;
                case 37:  // Left.
                    if (current_question_idx > 0)
                        --current_question_idx;
                    break;
                case 39:  // Right.
                    if (current_question_idx < amount_of_questions - 1)
                        ++current_question_idx;
                    break;
                default:;
            }
            const test_data::Question &question = test_data.questions[current_question_idx];
            ui::test::show_review_question(test_data.name, question.question, question.answers,
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

        for (auto &question: test_data.questions)
            question.students_answers[username] = {};

        ui::test::show_take_question(test_data.name, first_question.question, first_question.answers,
                                     first_question.students_answers.at(username),
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
                case 37:  // Left.
                    if (current_question_idx > 0)
                        --current_question_idx;
                    break;
                case 39:  // Right.
                    if (current_question_idx < amount_of_questions - 1)
                        ++current_question_idx;
                    break;
                case 38:  // Up.
                    if (selected_answer_idx > 0)
                        selected_answer = test_data.questions[current_question_idx].answers.at(--selected_answer_idx);
                    break;
                case 40:  // Down.
                    if (selected_answer_idx + 1 < test_data.questions[current_question_idx].answers.size())
                        selected_answer = test_data.questions[current_question_idx].answers.at(++selected_answer_idx);
                    break;
                default:;
            }
            const test_data::Question &question = test_data.questions[current_question_idx];
            ui::test::show_take_question(test_data.name, question.question, question.answers,
                                         question.students_answers.at(username),
                                         selected_answer, current_question_idx + 1, amount_of_questions);
        }
    }

    std::string get_new_answer()
    {
        return get_safe_string_from_user("answer");
    }

    std::string get_new_question()
    {
        return get_safe_string_from_user("question");
    }

    std::string get_new_report()
    {
        return get_safe_string_from_user("report");
    }
}
