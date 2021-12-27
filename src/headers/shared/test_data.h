#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_TEST_DATA_H
#define SRC_TEST_DATA_H

#include <vector>
#include answer_data.h

class TestData
{
public:
	string name;
	string question;
	std::vector<AnswerData> answers;
	TestData(string name, string question, std::vector<AnswerData> answers);
};

#endif //SRC_TEST_DATA_H

