#ifndef SRC_CONTROL_AUTH_H
#define SRC_CONTROL_AUTH_H

#include <string>

namespace control
{
    class auth
    {
        static std::string get_username(bool is_retry);
        static std::string get_password(const std::string& username, bool is_retry);
    public:
        static std::pair<std::string, std::string> get_auth_data(bool is_retry);
    };
}

#endif //SRC_CONTROL_AUTH_H

