#include "headers/quiz_system.h"
#include "headers/database/test.h"

int main()
{
    //QuizSystem();
    test_data::TestData tescik;
    tescik = database::test::get_test_data("testname1");
    tescik.name = "newtest3";
    //tescik.questions[0].question = "question 1";
    //tescik.questions = {};
    database::test::set_test(tescik);
    //database::test::delete_test("testname2");
    //database::test::delete_report("test", "stud");
    return 0;
}
