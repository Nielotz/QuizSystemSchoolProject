#ifndef SRC_TEST_H
#define SRC_TEST_H

#include "../../test_data/test_data.h"

namespace control::test
{
    test_data::TestData take(test_data::TestData test_data);

    void review(const test_data::TestData& test_data);

    test_data::TestData edit(test_data::TestData test_data);

    enum class TakeActionType
    {
        kSelect,
        kNext,
        kPrevious,
        kQuit,
    };

    enum class ReviewActionType
    {
        kReport,
        kPrevious,
        kNext,
        kQuit,
    };
    enum class EditActionType
    {
        kEdit,
        kNext,
        kPrevious,
        kQuit,
    };
}


#endif //SRC_TEST_H
