//
// Created by Nielotz on 2021-12-17.
//

#include "../headers/database/test.h"

namespace Database
{
    /* TestData Test::get_test_data(string name)
    {
        return;
    } */

    vector<string> Test::get_test_names()
    {
        return {"TestTestStudent", "TestTestTeacher"};
    }

    void Test::set_test(TestData::TestData test)
    {

    }

    TestData::TestData Test::get_test_data(const string &name)
    {
        TestData::Answers answers({"TestAnswer1", "TestAnswer2"});

        vector<TestData::Question> questions({{"TestQuestion",
                                               answers,
                                               {"TestAnswer1",}}});

        if (name == "TestTestStudent")
            return {"TestTestStudent", questions};
        return {"TestTestTeacher", questions};
    }
}