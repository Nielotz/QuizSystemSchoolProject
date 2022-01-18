#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include <string>

using namespace std;

namespace ui
{
    class Auth
    {
    public:
        static void ask_username(bool is_retry, const string& entered_username);
        static void ask_password(const string& username, bool is_retry, int amount_of_entered_chars);
    };
}
#endif //SRC_AUTH_H

