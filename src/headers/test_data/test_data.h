#ifndef SRC_TEST_DATA_TEST_DATA_H
#define SRC_TEST_DATA_TEST_DATA_H

#include <vector>
#include <utility>
#include <string>
#include <unordered_map>

#include "../shared/user_data.h"

namespace test_data
{
    struct Question
    {
        std::string question;
        std::vector<std::string> answers;
        std::vector<std::string> correct_answers;

        // Map username to answers.
        std::unordered_map<std::string, std::vector<std::string>> students_answers;
    };

    struct TestData
    {
        std::string name;
        std::vector<Question> questions;
        // Map username to points.
        std::unordered_map<std::string, int> users_points;
        // Vector of maps: username, report.
        std::vector<std::pair<std::string, std::string>> reported_issues;
    };
}

#endif //SRC_TEST_DATA_TEST_DATA_H

