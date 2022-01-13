#ifndef SRC_CONTROL_AUTH_H
#define SRC_CONTROL_AUTH_H

#include <string>

using namespace std;

namespace Control
{
    class Auth
    {
    public:
        string get_username();
        string get_password();
    };
}

#endif //SRC_CONTROL_AUTH_H

