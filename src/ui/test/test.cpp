#include <iostream>

#include "../../headers/ui/test.h"
#include "../../headers/ui/ui.h"

using std::cout;
using std::wcout;
using std::endl;

namespace ui::test
{
    void show_edit_question(const std::string& test_name, const std::string& question,
        const std::vector<std::string>& answers, const std::vector<std::string>& correct_answers,
        const std::string& selected_answer, int question_number, int question_amount)
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
        std::cout << "  Answers" << std::endl;
        std::cout << "      correct     answer" << std::endl;
        for (auto answer_ : answers)
        {

            if (answer_ == selected_answer)
                std::cout << "      [X]    <" << answer_ << ">" << std::endl;

            else
                std::cout << "      [ ]    <" << answer_ << ">" << std::endl;
        }
        std::cout << "e - edit, enter, q - quit, a - add answer, d - delete answer";
    }

    void show_review_question(const std::string& test_name, const std::string& question, const std::vector<std::string>& answers, const std::vector<std::string>& correct_answers, const std::vector<std::string>& marked_answers, int question_number, int question_amount)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  ==================" << std::endl;
        std::cout << "  + Test Reviewing +" << std::endl;
        std::cout << "  ==================" << std::endl << std::endl;

        std::cout << "  Test: < " << test_name << " >" << std::endl << std::endl;
        std::cout << "      Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
        std::cout << "      Correct:    Marked:     Answers:" << std::endl;

        for (auto answer : answers)
        {
            for (auto correct_answer : correct_answers)
            {
                if (answer == correct_answer)
                    std::cout << "    [X]";

                else
                    std::cout << "    [ ]";
            }

            for (auto marked_answer : marked_answers)
            {
                if (answer == marked_answer)
                    std::cout << "         [X] <" << answer << ">" << std::endl;

                else
                    std::cout << "         [ ] <" << answer << ">" << std::endl;
            }
        }
        std::cout << "r - report, → next, ← previous, q - quit";
    }

    void show_take_question(const std::string& test_name, const std::string& question, const std::vector<std::string>& answers, const std::vector<std::string>& marked_answers, int question_number, int question_amount)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  ===============" << std::endl;
        std::cout << "  + Taking Test +" << std::endl;
        std::cout << "  ===============" << std::endl << std::endl;

        std::cout << "  Test: <" << test_name << ">" << std::endl << std::endl;
        std::cout << "  Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
        std::cout << "  Answers:" << std::endl;

        for (auto answer_ : answers)
        {
            for (auto marked_answer : marked_answers)
            {
                if (answer_ == marked_answer)
                    std::cout << "    [X] <" << answer_ << ">" << std::endl;
                
                else
                    std::cout << "    [ ] <" << answer_ << ">" << std::endl;

            }
        }
        std::cout << "enter - mark/unmark answer, q - quit";
    }

    void add_test(std::string entered_name)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  =============" << std::endl;
        std::cout << "  + Add test +" << std::endl;
        std::cout << "  =============" << std::endl << std::endl;

        std::cout << "     Name:" << entered_name;

    }
}