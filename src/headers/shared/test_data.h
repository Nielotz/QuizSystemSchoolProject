#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_TEST_DATA_H
#define SRC_TEST_DATA_H

#include <vector>
#include answer_data.h

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

