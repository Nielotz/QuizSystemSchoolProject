#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_ANSWER_DATA_H
#define SRC_ANSWER_DATA_H

class AnswerData
{
public:
	string text;
	bool is_correct;
	AnswerData(string text, bool is_correct);
};

#endif //SRC_ANSWER_DATA_H

