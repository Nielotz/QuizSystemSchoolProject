#ifndef SRC_TEST_H
#define SRC_TEST_H

#include "../../test_data/test_data.h"

namespace control::test
{
    std::string get_new_answer();

    std::string get_new_question();

    std::string get_new_report();

    test_data::TestData take(test_data::TestData test_data, const std::string &username);

    test_data::TestData review(test_data::TestData test_data, const std::string &username);

    test_data::TestData edit(test_data::TestData test_data, const std::string &username);

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
