#include "../headers/shared/answer_data.h"

using namespace std;

AnswerData::AnswerData(string text_, bool is_correct_)
{
	this->text_ = text_;
	this->is_correct_ = is_correct_;
}
