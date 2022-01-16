#include "headers/test_selector.h"
#include "headers/database/test.h"
#include "headers/control/test_selector/test_selector.h"


#include <utility>
#include <vector>


using namespace std;

TestSelector::TestSelector(Control::Control control) : control_(std::move(control))
{}

TestData::TestData TestSelector::select_test()
{
    vector<string> tests_names = Database::Test::get_test_names();
    string selected_test_name = this->control_.test_selector_->control_test_selection(tests_names);
    TestData::TestData test_data = Database::Test::get_test_data(selected_test_name);

    return test_data;
}

string Control::TestSelector::Teacher::control_test_selection(vector<string> tests_data)
{
    return "TestTestTeacher";
}

string Control::TestSelector::Student::control_test_selection(vector<string> tests_data)
{
    return "TestTestStudent";
}
