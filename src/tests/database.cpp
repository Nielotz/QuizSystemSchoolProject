#include <cassert>
#include "../headers/database/user.h"
#include "../headers/database/test.h"

void test_get_user(const std::string &username, const std::string &password)
{
    assert(database::user::get_user(username, password));
}

void test_test()
{
    database::test::check_file(database::test::test_path);

    test_data::TestData test_data = database::test::get_test_data("Test data"));
    assert(!test_data.name.empty());

    database::test::get_test_names();

    database::test::set_test(test_data);
    database::test::delete_test(test_data.name);
}
