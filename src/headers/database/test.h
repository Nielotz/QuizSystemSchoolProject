//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <unordered_map>
#include <vector>

#include "../test_data/test_data.h"

using namespace std;

namespace Database
{
	class Test
	{
	private:
		unordered_map<string, TestData::TestData> tests_;

	public:
		TestData::TestData get_test_data(string name_);
		vector<string> get_test_names();
		void set_test(TestData::TestData test_);
		Test(unordered_map<string, TestData::TestData> tests_);
	};
}

#endif //SRC_TEST_H
