#include "../headers/test_data/test_data.h"

#include <utility>

using namespace std;


TestData::Answers::Answers(vector<string> answers) : answers_(std::move(answers))
{}

TestData::Question::Question(string question, Answers answers, vector<string> correct_answers)
        : question_(std::move(question)), answers_(std::move(answers)), correct_answers_(std::move(correct_answers))
{}

TestData::TestData::TestData(std::string name, vector<Question> questions) : name(std::move(name)), questions(std::move(questions))
{}

