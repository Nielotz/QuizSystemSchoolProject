#ifndef SRC_TEST_DATA_TEST_DATA_H
#define SRC_TEST_DATA_TEST_DATA_H

#include <vector>
#include <utility>
#include <string>

#include "../shared/user_data.h"

using namespace std;

namespace TestData
{
    struct Answers
    {
    public:
        vector<string> answers_;

        explicit Answers(vector<string> answers);
        Answers() = default;
    };

    struct Question
    {
    public:
        string question_;
        Answers answers_;
        vector<string> correct_answers_;

        Question(string question, Answers answers, vector<string> correct_answers);
    };

    struct TestData
    {
    public:
        std::string name;
        vector<Question> questions;
        vector<pair<string, Answers>> students_answers;
        vector<pair<string, string>> reported_issues;

        TestData(std::string name, vector<Question> questions);
        TestData() = default;
    };
}

#endif //SRC_TEST_DATA_TEST_DATA_H

