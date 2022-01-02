#ifndef SRC_ANSWER_DATA_H
#define SRC_ANSWER_DATA_H

#include <string>

namespace TestManagement
{
	class AnswerData
	{
	private:
		std::string text_;
		bool is_correct_;

	public:
		AnswerData(std::string text_, bool is_correct_);
	};
}
#endif //SRC_ANSWER_DATA_H

