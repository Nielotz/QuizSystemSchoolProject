#include <iostream>

#include "../../headers/ui/test/test.h"
#include "../../headers/ui/ui.h"

using std::cout;
using std::wcout;
using std::endl;

namespace ui::test
{
    void show_edit_question(const std::string &test_name, const std::string &question,
                            const std::vector<std::string> &answers, const std::vector<std::string> &correct_answers,
                            const std::string &selected_answer, int question_number, int question_amount)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  =================" << std::endl;
        std::cout << "  + Test editing  +" << std::endl;
        std::cout << "  =================" << std::endl << std::endl;

        std::cout << "  Test: < " << test_name << " >" << std::endl << std::endl;
        std::cout << "  Reported question:" << std::endl;
        std::cout << "  Question [<" << question_number << ">/<" << question_amount << ">]:" << std::endl;
        std::cout << "      <" << question << ">" << std::endl << std::endl;
        std::cout << "  Answers:" << std::endl;

        for (const auto &answer: answers)
        {
            if (answer == selected_answer)
            {
                ui::UI::set_console_text_background_color(3, 0);
                std::cout << "  -> ";
                ui::UI::color_reset();
            }
            else
                std::cout << "     ";

            if (std::find(correct_answers.begin(), correct_answers.end(), answer) == correct_answers.end())
                std::cout << " [ ]  " << answer << std::endl;
            else
                std::cout << " [X]  " << answer << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << "controls - ↓ ↑ → ←, n - new question, a - add answer, r - delete question, d - delete answer, q - quit";
    }

    void show_review_question(const std::string &test_name, const std::string &question, const std::vector<std::string> &answers,
                              const std::vector<std::string> &correct_answers, const std::vector<std::string> &marked_answers,
                              int question_number, int question_amount)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  ==================" << std::endl;
        std::cout << "  + Test Reviewing +" << std::endl;
        std::cout << "  ==================" << std::endl << std::endl;

        std::cout << "  Test: < " << test_name << " >" << std::endl << std::endl;
        std::cout << "  Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
        std::cout << "  Correct:   Marked:  Answers:" << std::endl;

        for (const auto &answer: answers)
        {
            if (std::find(correct_answers.begin(), correct_answers.end(), answer) == correct_answers.end())
                std::cout << "  [ ]";
            else
                std::cout << "  [X]";

            if (std::find(marked_answers.begin(), marked_answers.end(), answer) == marked_answers.end())
                std::cout << "        [ ]";
            else
                std::cout << "        [X]";

            cout << "      " << answer << endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << "controls - ↓ ↑ → ←, r - report, q - quit";
    }

    void show_take_question(const std::string &test_name, const std::string &question, const std::vector<std::string> &answers,
                            const std::vector<std::string> &marked_answers, const std::string &selected_answer,
                            int question_number, int question_amount)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  ===============" << std::endl;
        std::cout << "  + Taking Test +" << std::endl;
        std::cout << "  ===============" << std::endl << std::endl;

        std::cout << "  Test: <" << test_name << ">" << std::endl << std::endl;
        std::cout << "  Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
        std::cout << "  Answers:" << std::endl;

        for (const auto &answer_: answers)
        {
            if (answer_ == selected_answer)
            {
                ui::UI::set_console_text_background_color(3, 0);
                std::cout << "  -> ";
                ui::UI::color_reset();
            }
            else
                std::cout << "     ";

            if (std::find(marked_answers.begin(), marked_answers.end(), answer_) == marked_answers.end())
                std::cout << "   [ ]" << answer_ << endl;
            else
                std::cout << "   [X]" << answer_ << endl;

        }
        std::cout << std::endl << std::endl;
        std::cout << "controls - ↓ ↑ → ←, enter - mark/unmark answer, q - quit";
    }

    /*
    void add_test(const std::string &entered_name)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  =============" << std::endl;
        std::cout << "  + Add test +" << std::endl;
        std::cout << "  =============" << std::endl << std::endl;

        std::cout << "     Name:" << entered_name;
    }
    */
}