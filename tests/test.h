#ifndef TESTS_TEST_H
#define TESTS_TEST_H

#include <string>
#include "../src/headers/test_data/test_data.h"
#include "../src/headers/database/user.h"


namespace test
{
    namespace log_in
    {
        void login(const std::string &username, const std::string &password);
    }
}


#endif //TESTS_TEST_H
