#ifndef SRC_TEST_H
#define SRC_TEST_H

#include "../headers/test_management/test_menu.h"
#include "../headers/shared/user_data.h"
#include "../headers/test_management/test_data.h"

using namespace std;

namespace TestManagement
{
    class Test
    {
    private:
        TestData test_data_;
        TestMenu test_menu_;

    public:
        Test(TestData test_data);
        void handle_test_menu();
    };
}

#endif //SRC_TEST_H
