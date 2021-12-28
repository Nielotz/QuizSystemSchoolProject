#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_ANSWER_DATA_CPP
#define SRC_ANSWER_DATA_CPP

#include answer_data.h

using namespace std;

namespace TestManagement
{
	AnswerData::AnswerData(string text, bool is_correct)
	{
		this->text_ = text;
		this->is_correct_ = is_correct;
	}
}
#endif //SRC_ANSWER_DATA_CPP