#include <iostream>

#include "../../headers/ui/test/test.h"
#include "../../headers/ui/ui.h"

using std::cout;
using std::wcout;
using std::endl;

namespace ui::test
{
    void show_edit_question(const string &question, const vector<string> &answers, const vector<string> &correct_answers,
                            const string &selected_answer, int question_number, int question_amount)
    {
        /*
        system("CLS");

        ui::UI::print_logo();

        cout << "  =================" << endl;
        cout << "  + Test editing  +" << endl;
        cout << "  =================" << endl << endl;

        cout << "  Test: < " << test_data::TestData::name << " >" << endl << endl;
        cout << "  Reported question:" << endl;
        cout << "  Question [<" << question_number << ">/<" << question_amount << ">]:" << endl;
        cout << "      <" << question << ">" << endl << endl;
        cout << "  Answers" << endl;
        cout << "      correct     answer" << endl;
        for (auto answer_: answers)
        {
            if (answer_ == marked_answer)
            {
                cout << "      [X]    <" << answer_ << ">" << endl;
            }
            else
            {
                cout << "      [ ]    <" << answer_ << ">" << endl;
            }
        }
        cout << "e - edit, enter, q - quit, a - add answer, d - delete answer";
         */
    }

    void show_review_question(const string &question, const vector<string> &answers, const vector<string> &correct_answers,
                              const vector<string> &marked_answers, const string &selected_answer, int question_number, int question_amount)
    {
        /*
        system("CLS");

        ui::UI::print_logo();

        cout << "  ==================" << endl;
        cout << "  + Test Reviewing +" << endl;
        cout << "  ==================" << endl << endl;

        cout << "  Test: < " << test_data::TestData::name << " >" << endl << endl;
        cout << "      Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << endl;
        cout << "      Correct:    Marked:     Answers:" << endl;

        for (const auto& answer_: answers)
        {
            if (answer_ == correct_answers)
            {
                cout << "    [X]";

                if (answer_ == marked_answer)
                    cout << "         [X] <" << answer_ << ">" << endl;
                else
                    cout << "         [ ] <" << answer_ << ">" << endl;
            }
            else
            {
                cout << "    [ ] <" << answer_ << ">" << endl;

                if (answer_ == marked_answer)
                    cout << "         [X] <" << answer_ << ">" << endl;
                else
                    cout << "         [ ] <" << answer_ << ">" << endl;
            }
        }
        wcout << u"r - report, → next, ← previous, q - quit";
    */
    }

    void
    show_take_question(const string &question, const vector<string> &answers, const vector<string> &marked_answers,
                       const string &selected_answer, int question_number, int question_amount)
    {
        /*
        system("CLS");

        ui::UI::print_logo();

        cout << "  ===============" << endl;
        cout << "  + Taking Test +" << endl;
        cout << "  ===============" << endl << endl;

        cout << "  Test: <" << test_data::TestData::name << ">" << endl << endl;
        cout << "  Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << endl;
        cout << "  Answers:" << endl;

        for (const auto& answers_: answers)
        {
            if (answer_ == selected_answer)
            {
                cout << "    [X] <" << answer << ">" << endl;
            }
            else
            {
                cout << "    [ ] <" << answer << ">" << endl;
            }
        }
        cout << "enter - mark/unmark answer, q - quit";
         */
    }
}
