#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../headers/database/test.h"


string database::test::test_path = "../../../database/database_test.txt";
string database::test::answers_path = "../../../database/database_student_answers.txt";

namespace database
{
    void test::check_file(const string &path)
    {
        if (path.empty())
            throw exception("<test database> Path to the test database need to be set!");

        ifstream file(path, ios::out);

        if (!file.good())
        {
            file.close();
            throw exception("<test database> Path to the test database need to be set!");
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

    void test::set_test(const test_data::TestData &test)
    {
        test::check_file(test::test_path);
        test::check_file(test::answers_path);

        stringstream test_line_stream;
        test_line_stream << test.name << "|";
        for (auto &question: test.questions)
        {
            test_line_stream << question.question;
            for (const auto &j: question.answers)
                test_line_stream << "/^" << j;
            for (const auto &j: question.correct_answers)
                test_line_stream << "/;" << j;
            test_line_stream << "|";
        }
        string test_line = test_line_stream.str();

        // check if test already exist
        vector<string> existing_test = test::get_test_names();
        if (find(existing_test.begin(), existing_test.end(), test.name) != existing_test.end())
        {
            // overwrite existing test
            ifstream input(test::test_path);
            vector<string> lines;

            string test_data_read_line;
            while (getline(input, test_data_read_line))
            {
                istringstream testdata_stream(test_data_read_line);

                string read_test_name;
                getline(testdata_stream, read_test_name, '|');
                if (read_test_name == test.name)
                    test_data_read_line = test_line;
                test_data_read_line += "\n";
                lines.push_back(test_data_read_line);
            }
            input.close();

            // insert data to file
            ofstream output(test::test_path);
            for (const auto &i: lines)
                output << i;
            output.close();
        }
        else
        {
            // add new test
            ofstream output(test::test_path, ios_base::app);
            test_line += "\n";
            output << test_line;
            output.close();
        }

        // Update answer database
        vector<string> list_of_users;
        std::map<string, stringstream> students_answers;
        std::map<string, string> reports;

        for (const auto &question: test.questions)
        {
            for (const auto &student_answer: question.students_answers)
            {
                const auto &username = student_answer.first;
                auto &students_answers_stream = students_answers[username];

                students_answers_stream << question.question;
                if (find(list_of_users.begin(), list_of_users.end(), username) == list_of_users.end())
                    list_of_users.push_back(username);
                for (const auto &c: student_answer.second)
                    students_answers_stream << "/" << c;
                students_answers_stream << "|";
            }
        }
        for (const auto &b: test.reported_issues)
            reports[b.first] = b.second;

        std::map<string, string> final_lines;
        for (const auto &b: list_of_users)
        {
            if (reports[b].empty())
                reports[b] = "0";
            stringstream stream;
            stream << b << "|" << test.name << "|" << reports[b] << "|" << students_answers[b].str();
            final_lines[b] = stream.str();
        }

        // Compraring existing data to new
        ifstream input(test::answers_path);
        string test_data_read_line;
        vector<string> lines;
        while (getline(input, test_data_read_line))
        {
            istringstream testdata_stream(test_data_read_line);

            string read_user_name;
            getline(testdata_stream, read_user_name, '|');
            if (find(list_of_users.begin(), list_of_users.end(), read_user_name) != list_of_users.end())
            {
                string read_test_name;
                getline(testdata_stream, read_test_name, '|');
                cout << read_test_name << endl;
                if (read_test_name == test.name)
                {
                    test_data_read_line = final_lines[read_user_name];
                    final_lines.erase(read_user_name);
                }
            }
            test_data_read_line += "\n";
            lines.push_back(test_data_read_line);
        }

        // adding new lines
        for (const auto &i: final_lines)
            lines.push_back(i.second);
        input.close();

        // overwriting file
        ofstream output(test::answers_path);
        for (const auto &i: lines)
            output << i;
        output.close();
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
                std::map<string, int> student_points;
                std::map<string, string> reported_issues;

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
                        istringstream test_data_stream_2(test_data_read_section);

                        // ^answer OR ;correct_answer
                        string read_part;
                        getline(test_data_stream_2, read_part, '/');

                        if (read_part.starts_with('^'))
                        {
                            read_part = read_part.replace(0, 1, "");
                            answers.push_back(read_part);
                        }
                        else if (read_part.starts_with(';'))
                        {
                            read_part = read_part.replace(0, 1, "");
                            // answers.push_back(read_part);

                            correct_answers.push_back(read_part);
                        }
                        else
                            throw exception("<test database>Bad mark in file!");
                    }

                    // get students answers

                    //cout<<"current question: " << read_test_name << ", " << read_question << endl<<endl;
                    std::map<string, vector<string>> students_and_answers;
                    vector<string> students_answers;
                    for (auto &i: answers_file)
                    {
                        // get student username
                        size_t prev_section_pos = 0;
                        size_t section_pos = i.find('|');
                        string ans_cut = i.substr(prev_section_pos, section_pos);
                        string username = ans_cut;

                        // get testname
                        prev_section_pos = section_pos + 1;
                        section_pos = i.find('|', prev_section_pos);
                        ans_cut = i.substr(prev_section_pos, (section_pos - prev_section_pos));

                        if (ans_cut != read_test_name)
                            continue;

                        // get test report
                        prev_section_pos = section_pos + 1;
                        section_pos = i.find('|', prev_section_pos);
                        ans_cut = i.substr(prev_section_pos, (section_pos - prev_section_pos));
                        if (ans_cut != "0")
                            reported_issues[username] = ans_cut;

                        size_t question_end_pos;
                        prev_section_pos = section_pos + 1;
                        do
                        {
                            // get line with question and answers
                            question_end_pos = i.find('|', prev_section_pos);
                            // ans_cut = i.substr(prev_section_pos, (question_end_pos - prev_section_pos));

                            //get question
                            section_pos = i.find('/', prev_section_pos);
                            ans_cut = i.substr(prev_section_pos, (section_pos - prev_section_pos));
                            if (ans_cut != read_question)
                            {
                                question_end_pos = i.find('|', prev_section_pos);
                                prev_section_pos = question_end_pos + 1;
                                continue;
                            }

                            while (section_pos < question_end_pos)
                            {
                                // student answers
                                prev_section_pos = section_pos + 1;
                                section_pos = i.find('/', prev_section_pos);
                                if (section_pos > question_end_pos)
                                    section_pos = question_end_pos;
                                ans_cut = i.substr(prev_section_pos, (section_pos - prev_section_pos));
                                if (ans_cut.find('|') != string::npos)
                                    ans_cut = ans_cut.substr(0, ans_cut.length() - 2);
                                //students_and_answers[username] = students_and_answers[username].push_back(ans_cut);
                                students_answers.push_back(ans_cut);
                                // adding points to student
                                if (find(correct_answers.begin(), correct_answers.end(), ans_cut) != correct_answers.end())
                                    student_points[username]++;
                            }

                            question_end_pos = i.find('|', prev_section_pos);
                            prev_section_pos = question_end_pos + 1;
                        } while (question_end_pos < i.length() - 1);
                        students_and_answers[username] = students_answers;
                        students_answers.clear();
                    }
                    questions.push_back(test_data::Question{read_question, answers, correct_answers, students_and_answers});
                }
                vector<pair<string, string>> reported_issues_v;
                reported_issues_v.resize(reported_issues.size());
                std::copy(reported_issues.begin(), reported_issues.end(), reported_issues_v.begin());

                input.close();
                return {read_test_name, questions, student_points, reported_issues_v};
            }
        }
        input.close();
        throw exception("<test database>Test not found!");
    }

    void test::delete_test(const string &name)
    {
        ifstream input(test::test_path);
        vector<string> lines;
        string test_data_read_line;
        while (getline(input, test_data_read_line))
        {
            istringstream testdata_stream(test_data_read_line);

            string read_test_name;
            getline(testdata_stream, read_test_name, '|');
            if (read_test_name == name)
                continue;
            test_data_read_line += "\n";
            lines.push_back(test_data_read_line);
        }
        input.close();

        ofstream output(test::test_path);
        for (const auto &i: lines)
            output << i;
        output.close();
    }
/*
    void test::delete_report(const string &test_name, const string &username)
    {
        ifstream input(test::answers_path);
        vector<string> lines;
        string test_data_read_line;
        while (getline(input, test_data_read_line))
        {
            istringstream testdata_stream(test_data_read_line);

            string read_username;
            getline(testdata_stream, read_username, '|');
            if (read_username == username)
            {
                string read_test_name;
                getline(testdata_stream, read_test_name, '|');
                if (read_test_name == test_name)
                {
                    string read_report;
                    getline(testdata_stream, read_report, '|');
                    stringstream line_stream;
                    line_stream << username << "|" << test_name << "|0|"
                                << test_data_read_line.substr(read_username.size() + read_username.size() + read_report.size() + 3,
                                                              test_data_read_line.size());
                    test_data_read_line = line_stream.str();
                }
            }
            test_data_read_line += "\n";
            lines.push_back(test_data_read_line);
        }
        input.close();

        ofstream output(test::answers_path);
        for (const auto &i: lines)
            output << i;
        output.close();
    }

 */
}
