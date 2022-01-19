#include "../headers/database/test.h"

namespace database
{
    /* test_data test::get_test_data(string name)
    {
        return;
    } */

    std::vector<std::string> test::get_test_names()
    {
        // TODO: Return tests names from the database.

        return {"TestTestStudent", "TestTestTeacher"};
    }

    void test::set_test(test_data::TestData test)
    {

    }

    test_data::TestData test::get_test_data(const std::string &name)
    {
        // TODO: Return test data from the database.

        std::vector<test_data::Question> questions({{"TestQuestion",
                                                {"TestAnswer1", "TestAnswer2"},
                                                {"TestAnswer1",}}});

        if (name == "TestTestStudent")
            return {"TestTestStudent", questions};
        return {"TestTestTeacher", questions};
    }

    void test::delete_test(const std::string& test_name)
    {

    }
}