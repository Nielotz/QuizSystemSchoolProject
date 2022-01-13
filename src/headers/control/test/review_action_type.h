#ifndef SRC_CONTROL_TEST_REVIEW_ACTION_TYPE_H
#define SRC_CONTROL_TEST_REVIEW_ACTION_TYPE_H

namespace Control
{
	namespace Test
	{
		enum class ReviewActionType
		{
			kReport,
			kPrevious,
			kNext,
			kQuit,
		};
	}
}

#endif //SRC_CONTROL_TEST_REVIEW_ACTION_TYPE_H