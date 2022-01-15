#ifndef SRC_TEST_DATA_QUESTION_H
#define SRC_TEST_DATA_QUESTION_H

#include <vector>
#include <string>
#include "../test_data/answer.h"

using namespace std;

namespace TestData
{
	class Question
	{
	public:
		string question_;
		vector<Answer> answers_;
		vector<string> correct_answers_;
	};
}
#endif //SRC_TEST_DATA_QUESTION_H

