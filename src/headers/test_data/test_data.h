#ifndef SRC_TEST_DATA_TEST_DATA_H
#define SRC_TEST_DATA_TEST_DATA_H

#include <vector>
#include <utility>
#include <string>
#include <unordered_map>

#include "../shared/user_data.h"

using namespace std;

namespace test_data
{
    struct Question
    {
        string question;
        vector<string> answers;
        vector<string> correct_answers;

        // Map username to answers.
        unordered_map<string, vector<string>> students_answers;
    };

    struct TestData
    {
        string name;
        vector<Question> questions;
        // Map username to points.
        unordered_map<string, int> users_points;
        // Vector of maps: username, report.
        vector<pair<string, string>> reported_issues;
    };
}

#endif //SRC_TEST_DATA_TEST_DATA_H

