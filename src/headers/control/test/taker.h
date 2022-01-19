#ifndef SRC_CONTROL_TEST_TAKER_H
#define SRC_CONTROL_TEST_TAKER_H

#include <string>
#include <vector>

#include "../../test_data/test_data.h"

namespace Control
{
    namespace Test
    {
        class Taker
        {
            std::pair<std::vector<std::string>, std::vector<std::string>> take(test_data::TestData test_data);

            void handle_user_action();
        };
    }
}

#endif //SRC_CONTROL_TEST_TAKER_H
