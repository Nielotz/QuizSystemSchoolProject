#include <utility>

#include "../headers/test_data/test_data.h"

using namespace std;


test_data::Answers::Answers(vector<string> answers)
        : answers(std::move(answers))
{}

test_data::Question::Question(string question, Answers answers, vector<string> correct_answers)
        : question(std::move(question)), answers(std::move(answers)), correct_answers(std::move(correct_answers))
{}

test_data::TestData::TestData(std::string name, vector<Question> questions)
        : name(std::move(name)), questions(std::move(questions))
{}

