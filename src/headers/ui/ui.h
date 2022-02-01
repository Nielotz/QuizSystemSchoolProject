#ifndef SRC_UI_UI_H
#define SRC_UI_UI_H

#include <memory>

#include "../shared/account_type.h"
#include "test_menu/test_menu.h"
#include "test_selector/test_selector.h"
#include "ui.h"
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
        static void set_console_text_color(int text_color);
        static void set_console_text_background_color(int text_color, int background_color);
        static void color_reset();
        static void confirmation(const std::string& question, bool is_no_selected);
        static std::string ask_for(const std::string& what, const std::string& entered_string);
    };
}
#endif //SRC_UI_UI_H

