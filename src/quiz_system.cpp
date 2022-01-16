#include "headers/control/control.h"
#include "headers/quiz_system.h"
#include "headers/auth.h"
#include "headers/test_selector.h"

QuizSystem::QuizSystem() : control_(Auth::login().account_type)
{
    TestSelector test_selector(this->control_);
    TestData::TestData selected_test = test_selector.select_test();
}

void QuizSystem::create_new_test()
{

}

void QuizSystem::exit()
{

}