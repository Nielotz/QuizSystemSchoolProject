#ifndef SRC_TEST_DATA_TEST_DATA_H
#define SRC_TEST_DATA_TEST_DATA_H

#include <vector>
#include <utility>
#include <string>

#include "../shared/user_data.h"

using namespace std;

namespace test_data
{
    struct Answers
    {
        vector<string> answers;

        explicit Answers(vector<string> answers);
    };

    struct Question
    {
        string question;
        Answers answers;
        vector<string> correct_answers;

        Question(string question, Answers answers, vector<string> correct_answers);
    };

    struct TestData
    {
        string name;
        vector<Question> questions;
        vector<pair<string, Answers>> students_answers;
        vector<pair<string, string>> reported_issues;

        TestData(string name, vector<Question> questions);
    };
}

#endif //SRC_TEST_DATA_TEST_DATA_H

