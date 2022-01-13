#ifndef SRC_CONTROL_TEST_REVIEWER_H
#define SRC_CONTROL_TEST_REVIEWER_H

#include "../../test_data/test_data.h"

namespace Control
{
	namespace Test
	{
		class OptionType
		{
			void review(TestData::TestData test_data);
			void handle_user_action();
		};
	}
}

#endif //SRC_CONTROL_TEST_REVIEWER_H

