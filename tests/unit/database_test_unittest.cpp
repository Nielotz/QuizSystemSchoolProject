#pragma once

#include "cassert"

#include "database_test_unittest.h"

bool compare_question(const test_data::Question &question1, const test_data::Question &question2)
{
    if (question1.question != question2.question)
        return false;

    if (question1.answers != question2.answers)
        return false;

    if (question1.correct_answers != question2.correct_answers)
        return false;

    if (question1.students_answers != question2.students_answers)
        return false;

    return true;
}

bool compare_test_date(const test_data::TestData &test_data1, const test_data::TestData &test_data2)
{
    if (test_data1.name != test_data2.name)
        return false;

    // Questions.
    if (test_data1.questions.size() != test_data2.questions.size())
        return false;
    for (size_t i = 0; i < test_data1.questions.size(); i++)
        if (!compare_question(test_data1.questions[i], test_data2.questions[i]))
            return false;

    if (test_data1.reported_issues != test_data2.reported_issues)
        return false;

    if (test_data1.users_points != test_data2.users_points)
        return false;

    return true;
}

void run_test_test_database()
{
    database::test::test_path = "../resources/database_test.txt";
    database::test::answers_path = "../resources/database_test.txt";

    // Check db files.
    {
        const vector<string> &read_tests_names = database::test::get_test_names();
        const vector<string> &expected_tests_names = {"EmptyTest", "EmptyQuestions", "NormalTest"};
        assert(read_tests_names == expected_tests_names);
    }

    // Test empty test.
    {
        const test_data::TestData &expected_test_data = {"EmptyTest"};
        const test_data::TestData &received_test_data = database::test::get_test_data("EmptyTest");

        assert(compare_test_date(expected_test_data, received_test_data));
    }

    // Test empty questions.
    {
        test_data::TestData expected_test_data = {"EmptyQuestions", {{"EmptyQuestion1"}, {"EmptyQuestion2"}}};
        const test_data::TestData received_test_data = database::test::get_test_data("EmptyQuestions");

        assert(compare_test_date(expected_test_data, received_test_data));
    }

    // Test normal test.
    {
        // NormalTest|Question1/^Answer1/^Answer2/^Answer3|Question2/^Answer1/^Answer2/^Answer3/;Answer1/;Answer2/;Answer3|

        test_data::TestData expected_test_data = {"NormalTest",
                                                  {
                                                          {"Question1", {"Answer1", "Answer2", "Answer3"}},
                                                          {"Question2", {"Answer1", "Answer2", "Answer3"},
                                                           {"Answer1", "Answer2", "Answer3"}}
                                                  }
        };
        const test_data::TestData received_test_data = database::test::get_test_data("NormalTest");

        assert(compare_test_date(expected_test_data, received_test_data));
    }
}
