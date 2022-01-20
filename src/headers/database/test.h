#ifndef SRC_DATABASE_TEST_H
#define SRC_DATABASE_TEST_H

#include <vector>

#include "../test_data/test_data.h"

using namespace std;

namespace database
{
	namespace test
	{
		const string test_path = "../../../database/database_test.txt";
		const string answers_path = "../../../database/database_student_answers.txt";
		void check_file(const string& path);
		test_data::TestData get_test_data(const string& name);
		vector<string> get_test_names();
		void set_test(const test_data::TestData& test);
		void delete_test(const string& name);
		void delete_report(const string& test_name, const string& username);
	};
}

#endif //SRC_DATABASE_TEST_H
