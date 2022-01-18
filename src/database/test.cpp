//
// Created by Nielotz on 2021-12-17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../headers/database/test.h"

using namespace std;

namespace Database
{
    /* TestData Test::get_test_data(string name)
    {
        return;
    } */

    vector<string> Test::get_test_names()
    {
        vector<string> test_names;

        const string path = "../../../database/database_test.txt";
        if (path.empty())
        {
            cout << "<test database>Path to the test database need to be set!";
            return{};
        }

        ifstream input(path, ios::out);

        if (input.good() == 0)
        {
            cout << "<test database>File at the specified location does not exist!";
            return{};
        }

        string testdata_line;

        while (getline(input, testdata_line))
        {
            istringstream testdata_stream(testdata_line);
            string testdata_element;
            string r_name;
            getline(testdata_stream, r_name, '|');
            test_names.push_back(r_name);
        }
        input.close();
        return test_names;
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