//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_DATABASE_TEST_H
#define SRC_DATABASE_TEST_H

#include <unordered_map>
#include <vector>

#include "../test_data/test_data.h"

using namespace std;

namespace database
{
	class test
	{
	private:
		static unordered_map<string, test_data::TestData> tests_;

	public:
		static test_data::TestData get_test_data(const string& name);
		static vector<string> get_test_names();
		static void set_test(test_data::TestData test);
	};
}

#endif //SRC_DATABASE_TEST_H
