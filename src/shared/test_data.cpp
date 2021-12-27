#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_TEST_DATA_CPP
#define SRC_TEST_DATA_CPP

#include test_data.h

TestData::TestData(string name, string question, std::vector<AnswerData> answers)
{
	this->name = name;
	this->question = question;
	this->answers = answers;
}

#endif //SRC_TEST_DATA_CPP

