#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include <string>

namespace ui::auth
{
    static void ask_username(bool is_retry, const std::string &entered_username);

    static void ask_password(const std::string& username, bool is_retry, size_t amount_of_entered_chars);
}
#endif //SRC_AUTH_H

