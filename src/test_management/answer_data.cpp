#include "../headers/test_management/answer_data.h"

using namespace std;

namespace TestManagement
{
	AnswerData::AnswerData(string text_, bool is_correct_)
	{
		this->text_ = text_;
		this->is_correct_ = is_correct_;
	}
}