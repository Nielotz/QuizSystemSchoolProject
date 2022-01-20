#include <iostream>

#include "../headers/ui/test.h"
#include "../../headers/ui/ui.h"

void ui::test::show_edit_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers, std::string selected_answer, int question_number, int question_amount)
{
    system("CLS");

    ui::UI::print_logo();

    std::cout << "  =================" << std::endl;
    std::cout << "  + Test editing  +" << std::endl;
    std::cout << "  =================" << std::endl << std::endl;

    std::cout << "  Test: < " << test_data::TestData::name << " >" << std::endl << std::endl;
    std::cout << "  Reported question:" << endl;
    std::cout << "  Question [<" << question_number << ">/<" << question_amount << ">]:" << std::endl;
    std::cout << "      <" << question << ">" << std::endl << std::endl;
    std::cout << "  Answers" << std::endl;
    std::cout << "      correct     answer" << endl;
    for (auto answer_ : answers)
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
    std::cout << "e - edit, enter, q - quit, a - add answer, d - delete answer";
}

void ui::test::show_review_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers, std::vector<std::string> marked_answers, std::string selected_answer, int question_number, int question_amount)
{
    system("CLS");

    ui::UI::print_logo();

    std::cout << "  ==================" << std::endl;
    std::cout << "  + Test Reviewing +" << std::endl;
    std::cout << "  ==================" << std::endl << std::endl;

    std::cout << "  Test: < " << test_data::TestData::name << " >" << std::endl << std::endl;
    std::cout << "      Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
    std::cout << "      Correct:    Marked:     Answers:" << std::endl;

    for (auto answer_ : answers)
    {
        if (answer_ == correct_answers)
        {
            cout << "    [X]";

            if (answer_ == marked_answer)
                cout << "         [X] <" << answer_ << ">"<<std::endl;
            else
                cout << "         [ ] <" << answer_ << ">" << std::endl;
        }
        else
        {
            cout << "    [ ] <" << answer_ << ">" << endl;

            if (answer_ == marked_answer)
                cout << "         [X] <" << answer_ << ">" << std::endl;
            else
                cout << "         [ ] <" << answer_ << ">" << std::endl;
        }
    }
    std::wcout << u"r - report, → next, ← previous, q - quit";
}

void ui::test::show_take_question(std::string question, std::vector<std::string> answers, std::vector<std::string> marked_answers, std::string selected_answer, int question_number, int question_amount)
{
    system("CLS");

    ui::UI::print_logo();

    std::cout << "  ===============" << std::endl;
    std::cout << "  + Taking Test +" << std::endl;
    std::cout << "  ===============" << std::endl << std::endl;

    std::cout << "  Test: <" << test_data::TestData::name << ">" << std::endl << std::endl;
    std::cout << "  Question: [<" << question_number << "> / <" << question_amount << ">]: " << question << std::endl;
    std::cout << "  Answers:" << std::endl;

    for (auto answers_ : answers)
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
    std::cout << "enter - mark/unmark answer, q - quit";
}
