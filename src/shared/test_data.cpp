#include "../headers/test_data/test_data.h"

using namespace std;

	TestData::TestData(std::string name, string question, vector<AnswerData> answers)
	{
		this->name_ = name;
		this->question_ = question;
		this->answers_ = answers;
	}

