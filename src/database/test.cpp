//
// Created by Nielotz on 2021-12-17.
//

#include "../headers/database/test.h"

namespace database
{
    /* test_data test::get_test_data(string name)
    {
        return;
    } */

    vector<string> test::get_test_names()
    {
        // TODO: Return tests names from the database.

        return {"TestTestStudent", "TestTestTeacher"};
    }

    void test::set_test(test_data::TestData test)
    {

    }

    test_data::TestData test::get_test_data(const string &name)
    {
        // TODO: Return test data from the database.

        test_data::Answers answers({"TestAnswer1", "TestAnswer2"});

        vector<test_data::Question> questions({{"TestQuestion",
                                                answers,
                                                {"TestAnswer1",}}});

        if (name == "TestTestStudent")
            return {"TestTestStudent", questions};
        return {"TestTestTeacher", questions};
    }
}