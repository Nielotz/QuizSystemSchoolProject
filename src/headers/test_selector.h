#ifndef SRC_TEST_SELECTOR_H
#define SRC_TEST_SELECTOR_H

#include "ui/ui.h"
#include "control/control.h"
#include "test_data/test_data.h"

using namespace std;

namespace test_selector
{
    test_data::TestData select_test(const control::Control& control);
};

#endif //SRC_TEST_SELECTOR_H
