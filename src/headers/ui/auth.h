#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include <string>

using namespace std;

namespace UI
{
    class Auth
    {
    public:
        static void ask_username(bool is_retry, string entered_username);
        static void ask_password(string username, bool is_retry, int ammount_of_entered_chars);
    };
}
#endif //SRC_AUTH_H

