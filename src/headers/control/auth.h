#ifndef SRC_CONTROL_AUTH_H
#define SRC_CONTROL_AUTH_H

#include <string>

using namespace std;

namespace Control
{
    class Auth
    {
        static string get_username();
        static string get_password();
    public:
        static pair<string, string> get_auth_data();
    };
}

#endif //SRC_CONTROL_AUTH_H

