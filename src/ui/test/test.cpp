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

        std::cout << "  =================" << std::endl;     //NOWA WERSJA
        std::cout << "  + Test editing  +" << std::endl;
        std::cout << "  =================" << std::endl << std::endl;

        std::cout << "  Test: < " << test_name << " >" << std::endl << std::endl;
        std::cout << "  Reported question:" << std::endl;
        std::cout << "  Question [<" << question_number << ">/<" << question_amount << ">]:" << std::endl;
        std::cout << "      <" << question << ">" << std::endl << std::endl;
        std::cout << "  Answers" << std::endl;
        std::cout << "      correct    " << std::endl;
        
        bool is_marked = false;
        
        for (const auto &answer_: answers)
        {
            if (answer_ == selected_answer && is_marked == false)
            {
                std::cout << "  ";
                ui::UI::set_console_text_background_color(3, 0);
                std::cout << "-> ";
                ui::UI::color_reset();
            }

            else
                std::cout << "     ";

            for (auto &correct_answer: correct_answers)
            {
                if (answer_ == correct_answer && is_marked==false)
                {
                    std::cout << " [X]  "<< answer_ << std::endl;
                    is_marked = true;

                } 
            }

            if (!is_marked)
                std::cout << " [ ]  " << answer_ << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << "e - edit, enter, q - quit, a - add answer, d - delete answer";
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
        std::cout << "      Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
        std::cout << "      Correct:    Marked:     Answers:" << std::endl;

        for (const auto &answer: answers)
        {
            bool is_marked = false;
            for (const auto &correct_answer: correct_answers)
            {
                if (answer == correct_answer)
                {
                    std::cout << "    [X]";
                    is_marked = true;
                    break;
                }
            }
            if (!is_marked)
                std::cout << "    [ ]";

            is_marked = false;
            for (const auto &marked_answer: marked_answers)
            {
                if (answer == marked_answer)
                {
                    std::cout << "         [X] <" << answer << ">" << std::endl;
                    is_marked = true;
                    break;
                }
            }
            if (!is_marked)
                std::cout << "         [ ] <" << answer << ">" << std::endl;
        }
        std::cout << "r - report, -> next, <- previous, q - quit";
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
            bool is_marked = false;
            for (auto &marked_answer: marked_answers)
            {
                if (answer_ == marked_answer)
                {
                    std::cout << "         [X] <";
                    is_marked = true;
                    break;
                }
            }
            if (!is_marked)
                std::cout << "         [ ] <";

            if (answer_ == selected_answer)
            {
                ui::UI::set_console_text_background_color(0, 3);
                std::cout << answer_;
                ui::UI::color_reset();
                std::cout << std::endl;
            }
        }
        std::cout << "enter - mark/unmark answer, q - quit";
    }

    void add_test(const std::string &entered_name)
    {
        system("CLS");

        ui::UI::print_logo();

        std::cout << "  =============" << std::endl;
        std::cout << "  + Add test +" << std::endl;
        std::cout << "  =============" << std::endl << std::endl;

        std::cout << "     Name:" << entered_name;
    }
}