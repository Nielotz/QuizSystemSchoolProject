//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_TEST_H
#define SRC_TEST_H

#include <unordered_map>
#include <vector>
#import test_data.h

#import test/test_data.h

using namespace std;

class Test
{
	private:
		unordered_map<string, TestData> tests_;

	public:
		TestDatabase();
		get_test_data(string name_);
		vector<string> get_test_names();
		set_test(string name_, TestData test_);
		Test(unordered_map<string, TestData> tests_);
};

#endif //SRC_TEST_H
