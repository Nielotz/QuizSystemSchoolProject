#ifndef SRC_UI_UI_H
#define SRC_UI_UI_H

#include <memory>

#include "../shared/account_type.h"
#include "../ui/test_menu/test_menu.h"
#include "../ui/test_selector/test_selector.h"
#include "test/test.h"

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
        static void set_console_text_color(const int text_color);
        static void set_console_text_background_color(const int text_color, const int background_color);
        static void color_reset();
        static std::string ask_for(const std::string &what, const std::string &entered_string);
    };

    namespace test
    {
        void show_edit_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers);

        void show_review_question(std::string question, std::vector<std::string> answers, std::vector<std::string> correct_answers, std::vector<std::string> marked_answers);

        void show_take_question(std::string question, std::vector<std::string> answers, std::vector<std::string> marked_answers);
    }
}
#endif //SRC_UI_UI_H

