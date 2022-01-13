//
// Created by Nielotz on 2021-12-17.
//

#include "../headers/database/test.h"

namespace Database
{
	/* TestData Test::get_test_data(string name_)
	{
		return;
	} */

	vector<string> Test::get_test_names()
	{
		vector<string> v;
		return v;
	}

	void Test::set_test(TestData::TestData test_)
	{

	}

	Test::Test(unordered_map<string, TestData::TestData> tests_)
	{
		this->tests_ = tests_;
	}
}