#ifndef SRC_TEST_DATA_TEST_DATA_H
#define SRC_TEST_DATA_TEST_DATA_H

#include <vector>
#include <utility>
#include <string>

#include "../test_data/question.h"
#include "../test_data/answers.h"
#include "../shared/user_data.h"

using namespace std;

namespace TestData
{
	struct TestData
	{
	public:
		std::string name;
		vector<Questions> questions;
		vector<pair<std::string, Answers>> students_answers;
		vector <std::string, std::string> reported_issues;
	};
}

#endif //SRC_TEST_DATA_TEST_DATA_H

