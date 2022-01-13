#ifndef SRC_TEST_MENU_H
#define SRC_TEST_MENU_H

#include "..\headers\test_data\test_data.h"

namespace UI
{
    namespace TestMenu
    {
        class TestMenu
        {
        public:
            void show(string username, TestData::TestData test_data);
        };
    }
}
#endif //SRC_TEST_MENU_H

