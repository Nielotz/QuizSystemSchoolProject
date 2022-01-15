#include <optional>

#include "headers/quiz_system.h"
#include "headers/control/control.h"
#include "headers/auth.h"
#include "headers/database/user.h"

QuizSystem::QuizSystem() : control_(Auth::login().account_type)
{
    int x;
}

void QuizSystem::create_new_test()
{

}

void QuizSystem::exit()
{

}