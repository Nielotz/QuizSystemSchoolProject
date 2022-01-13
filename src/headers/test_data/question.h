#ifndef SRC_TEST_DATA_QUESTION_H
#define SRC_TEST_DATA_QUESTION_H

#include <vector>
#include <string>
#include "../test_data/answers.h"

using namespace std;

namespace TestData
{
	class Questions
	{
	public:
		string question_;
		vector<Answers> answers_;
		vector<string> correct_answers_;
	};
}
#endif //SRC_TEST_DATA_QUESTION_H

