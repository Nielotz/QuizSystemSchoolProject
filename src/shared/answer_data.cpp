#include "../headers/shared/answer_data.h"

using namespace std;

AnswerData::AnswerData(string text, bool is_correct)
{
	this->text = text;
	this->is_correct = is_correct;
}
