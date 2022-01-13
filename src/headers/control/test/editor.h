#ifndef SRC_CONTROL_TEST_EDITOR_H
#define SRC_CONTROL_TEST_EDITOR_H

#include "../../test_data/test_data.h"

namespace Control
{
	namespace Test
	{
		class Editor
		{
			TestData::TestData edit(TestData::TestData test_data);
			void handle_user_action();
		};
	}
}

#endif //SRC_CONTROL_TEST_EDITOR_H