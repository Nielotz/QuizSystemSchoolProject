#include "../headers/test_management/test_data.h"

namespace TestManagement
{
	TestData::TestData(string name, string question, vector<AnswerData> answers)
	{
		this->name_ = name;
		this->question_ = question;
		this->answers_ = answers;
	}
}

