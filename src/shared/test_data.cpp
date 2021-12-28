#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_TEST_DATA_CPP
#define SRC_TEST_DATA_CPP

#include test_data.h

using namespace std;

namespace TestManagement
{
	TestData::TestData(string name, string question, vector<AnswerData> answers)
	{
		this->name_ = name;
		this->question_ = question;
		this->answers_ = answers;
	}
}

#endif //SRC_TEST_DATA_CPP

