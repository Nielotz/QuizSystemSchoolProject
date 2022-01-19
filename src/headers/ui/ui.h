#ifndef SRC_UI_UI_H
#define SRC_UI_UI_H

#include <memory>

#include "../shared/account_type.h"
#include "../ui/test_menu/test_menu.h"
#include "../ui/test_selector/test_selector.h"
#include "../../headers/ui/test.h"

namespace ui
{
    class UI
    {
        explicit UI();
        static AccountType account_type_;
    public:
        static bool initialized;
        std::shared_ptr<test_selector::TestSelector> test_selector_;
        std::shared_ptr<test_menu::TestMenu> test_menu_;

        static void init(AccountType account_type);
        static ui::UI get();

        static void print_logo();
    };

    namespace test
    {
        void show_edit_question(string question, vector<string> answers, vector<string> correct_answers);

        void show_review_question(string question, vector<string> answers, vector<string> correct_answers, vector<string> marked_answers);

        void show_take_question(string question, vector<string> answers, vector<string> marked_answers);
    }
}
#endif //SRC_UI_UI_H

