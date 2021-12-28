#pragma once
//
// Created by Ula on 2021-12-27.
//

#ifndef SRC_ANSWER_DATA_H
#define SRC_ANSWER_DATA_H

using namespace std;

namespace TestManagement
{
	class AnswerData
	{
	private:
		string text_;
		bool is_correct_;

	public:
		AnswerData(string text_, bool is_correct_);
	};
}
#endif //SRC_ANSWER_DATA_H

