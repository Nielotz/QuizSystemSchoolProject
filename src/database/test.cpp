#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/database/test.h"

namespace database
{
    void test::check_file(string path)
    {
        if (path.empty())
            throw exception("<test database>Path to the test database need to be set!");

        ifstream file(path, ios::out);;

        if (file.good() == 0)
        {
            file.close();
            throw exception("<test database>Path to the test database need to be set!");
        }
        file.close();
    }

    vector<string> test::get_test_names()
    {
        test::check_file(test::test_path);
        ifstream input(test::test_path, ios::out);

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

    void test::set_test(test_data::TestData test)
    {

    }

    test_data::TestData test::get_test_data(const string &name)
    {
        test::check_file(test::test_path);
        test::check_file(test::answers_path);

        ifstream input(test::test_path, ios::out);
        ifstream input_2(test::answers_path, ios::out);

        vector<string> answers_file;
        string ans_data_read_line;
        while (getline(input_2, ans_data_read_line))
            answers_file.push_back(ans_data_read_line);
        input_2.close();

            

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
                vector<test_data::Question> questions;

                // question 1/^My answer1/^My answer2/^My answ3/;correct_answer/;correct2
                string test_data_read_question;
                while (getline(testdata_stream, test_data_read_question, '|'))
                {
                    vector<string> answers;
                    vector<string> correct_answers;
                    istringstream test_data_stream(test_data_read_question);

                    // question 1
                    string read_question;
                    getline(test_data_stream, read_question, '/');
                    //cout << "rquestion: " << read_test_name<<", "<< read_question << endl<<endl<<endl;

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
                            answers.push_back(read_part);
                        }
                        else if (!read_part.find(';'))
                        {
                            read_part = read_part.replace(0, 1, "");
                            correct_answers.push_back(read_part);
                        }
                        else
                            throw exception("<test database>Bad mark in file!");
                    }

                    // get students answers

                    //cout<<"current question: " << read_test_name << ", " << read_question << endl<<endl;
                    unordered_map<string, vector<string>> students_and_answers;
                    vector<string> students_answers;
                    int student_points = 0;
                    for (int i = 0; i != answers_file.size(); i++)
                    {
                        
                        // get student username
                        size_t prev_section_pos = 0;
                        size_t section_pos = answers_file[i].find('|');
                        string ans_cut = answers_file[i].substr(prev_section_pos, section_pos);
                        string username = ans_cut;

                        // get testname
                        prev_section_pos = section_pos + 1;
                        section_pos = answers_file[i].find('|', prev_section_pos);
                        ans_cut = answers_file[i].substr(prev_section_pos, (section_pos - prev_section_pos));

                        if (ans_cut != read_test_name)
                            continue;

                        size_t question_end_pos = 0;
                        prev_section_pos = section_pos + 1;
                        do
                        {
                            // get line with question and answers
                            question_end_pos = answers_file[i].find('|', prev_section_pos);
                            ans_cut = answers_file[i].substr(prev_section_pos, (question_end_pos - prev_section_pos));
                            
                            //get question
                            section_pos = answers_file[i].find('/', prev_section_pos);
                            ans_cut = answers_file[i].substr(prev_section_pos, (section_pos - prev_section_pos));
                            if (ans_cut != read_question)
                            {
                                question_end_pos = answers_file[i].find('|', prev_section_pos);
                                prev_section_pos = question_end_pos + 1;
                                continue;
                            }  

                            while (section_pos < question_end_pos && section_pos >-1)
                            {
                                // student answers
                                prev_section_pos = section_pos + 1;
                                section_pos = answers_file[i].find('/', prev_section_pos);
                                if (section_pos > question_end_pos)
                                    section_pos = question_end_pos;
                                ans_cut = answers_file[i].substr(prev_section_pos, (section_pos - prev_section_pos));
                                if (ans_cut.find('|') != string::npos)
                                    ans_cut = ans_cut.substr(0, ans_cut.length() - 2);
                                answers.push_back(ans_cut);
                            }

                            question_end_pos = answers_file[i].find('|', prev_section_pos);
                            prev_section_pos = question_end_pos + 1;
                        } while (question_end_pos < answers_file[i].length() - 1);
                        students_and_answers[username] = students_answers;
                    }
                    questions.push_back(test_data::Question{ read_question, answers, correct_answers,students_and_answers });
                }
                input.close();
                return { read_test_name, questions };
            }
        }
        input.close();
        throw exception("<test database>Test not found!");
    } 
}