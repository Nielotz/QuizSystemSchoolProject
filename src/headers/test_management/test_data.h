#ifndef SRC_TEST_DATA_H
#define SRC_TEST_DATA_H

#include <vector>

#include "../headers/test_management/answer_data.h"

using namespace std;

namespace TestManagement
{
	class TestData
	{
	public:
		string name_;
		string question_;
		vector<AnswerData> answers_;
		TestData(string name_, string question_, vector<AnswerData> answers_);
	};
}

#endif //SRC_TEST_DATA_H

