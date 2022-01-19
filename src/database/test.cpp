//
// Created by Nielotz on 2021-12-17.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../headers/database/test.h"

using namespace std;

const string Database::Test::path = "../../../database/database_test.txt";;

namespace Database
{
    void Test::check_file()
    {
        if (Test::path.empty())
            throw exception("<test database>Path to the test database need to be set!");

        ifstream file(Test::path, ios::out);;
        
        if (file.good() == 0)
        {
            file.close();
            throw exception("<test database>Path to the test database need to be set!");
        }
        file.close();
    }

    vector<string> Test::get_test_names()
    {
        Test::check_file();
        ifstream input(Test::path, ios::out);

        vector<string> test_names;
        string testdata_line;
        while (getline(input, testdata_line))
        {
            istringstream testdata_stream(testdata_line);
            string read_name;
            getline(testdata_stream, read_name, '|');
            test_names.push_back(read_name);
        }
        input.close();
        return test_names;
    }

    void Test::set_test(TestData::TestData test)
    {
        
    }

    TestData::TestData Test::get_test_data(const string &name)
    {
        Test::check_file();

        ifstream input(Test::path, ios::out);
        
        // testname1|question 1/^My answer1/^My answer2/^My answ3/;correct_answer/;correct2|question 2/^My answer12/^My answer22/^My answ32/;my correct ans12/;correct22|        
        string test_data_read_line;
        while (getline(input, test_data_read_line))
        {
            istringstream testdata_stream(test_data_read_line);

            // testname1
            string read_test_name;
            getline(testdata_stream, read_test_name, '|');
            if (read_test_name == name)
            {
                vector<TestData::Question> questions;

                // question 1/^My answer1/^My answer2/^My answ3/;correct_answer/;correct2
                string test_data_read_question;
                while (getline(testdata_stream, test_data_read_question, '|'))
                {
                    TestData::Answers answers;
                    vector<string> correct_answers;
                    istringstream test_data_stream(test_data_read_question);

                    // question 1
                    string read_question; 
                    getline(test_data_stream, read_question, '/');

                    // ^My answer1/^My answer2/^My answ3/;correct_answer/;correct2
                    string test_data_read_section;
                    while (getline(test_data_stream, test_data_read_section, '/'))
                    {
                        istringstream test_data_stream(test_data_read_section);

                        // ^answer OR ;correct_answer
                        string read_part;
                        getline(test_data_stream, read_part, '/');
                        if (!read_part.find('^'))
                        {
                            read_part = read_part.replace(0, 1, "");
                            answers.answers_.push_back(read_part);
                        }
                        else if (!read_part.find(';'))
                        {
                            read_part = read_part.replace(0, 1, "");
                            correct_answers.push_back(read_part);
                        }
                        else
                            throw exception("<test database>Bad mark in file!");
                    }
                    questions.push_back(TestData::Question{ read_question, answers, correct_answers });
                }
                input.close();
                return { read_test_name, questions };
            }
        }
        input.close();
        throw exception("<test database>Test not found!");
    }
}