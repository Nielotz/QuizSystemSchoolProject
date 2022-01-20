#ifndef SRC_TEST_TEST_H
#define SRC_TEST_TEST_H

#include "test_data/test_data.h"
#include "control/control.h"

namespace test
{
    void handle(const test_data::TestData &test_data, control::test_menu::OptionType open_type, const std::string& username);
};

#endif //SRC_TEST_TEST_H
