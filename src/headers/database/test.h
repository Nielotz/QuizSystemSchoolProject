#ifndef SRC_DATABASE_TEST_H
#define SRC_DATABASE_TEST_H

#include <unordered_map>
#include <vector>

#include "../test_data/test_data.h"

using namespace std;

namespace database
{
	namespace test
	{
		test_data::TestData get_test_data(const string& name);
		vector<string> get_test_names();
		void set_test(test_data::TestData test);
	};
}

#endif //SRC_DATABASE_TEST_H
