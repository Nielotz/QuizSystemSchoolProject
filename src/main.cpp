#include "headers/quiz_system.h"

#define MY_TESTS true

int main()
{
    if (MY_TESTS)
        QuizSystem quiz;
    else

        QuizSystem quiz("Test user", "Test user");
    return 0;
}
