#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include <string>

using namespace std;

namespace UI
{
    class Auth
    {
    public:
        static void ask_username(bool is_retry);
        static void ask_password(string username, bool is_retry);
    };
}
#endif //SRC_AUTH_H

