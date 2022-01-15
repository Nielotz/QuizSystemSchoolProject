#ifndef SRC_CONTROL_TEST_TAKER_H
#define SRC_CONTROL_TEST_TAKER_H

#include <string>
#include <vector>

#include "../../test_data/test_data.h"

using namespace std;

namespace Control
{
    namespace Test
    {
        class Taker
        {
            pair<vector<string>, vector<string>> take(TestData::TestData test_data);

            void handle_user_action();
        };
    }
}

#endif //SRC_CONTROL_TEST_TAKER_H
