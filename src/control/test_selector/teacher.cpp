#include "../../headers/control/test_selector/teacher.h"
#include "../../headers/ui/ui.h"

namespace control::test_selector
{
    std::string Teacher::control_test_selection(std::vector<std::string> tests_names)
    {
        std::string selected_test;

        if (!tests_names.empty())
            selected_test = tests_names[0];

        ui::UI::get().test_selector_->ask_select_test(tests_names, selected_test);


        // #TODO: control test selection - user input.

        return "TestTestTeacher";
    }
}
