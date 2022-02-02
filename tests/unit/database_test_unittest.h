#ifndef TESTS_DATABASE_TEST_UNITTEST_H
#define TESTS_DATABASE_TEST_UNITTEST_H

#include "../../src/headers/database/test.h"


bool compare_question(const test_data::Question &question1, const test_data::Question &question2);

bool compare_test_date(const test_data::TestData &test_data1, const test_data::TestData &test_data2);

void run_test_test_database();

#endif //TESTS_DATABASE_TEST_UNITTEST_H
