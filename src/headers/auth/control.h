//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_CONTROL_H
#define SRC_CONTROL_H

#include <string>

namespace Auth
{
    class Control
    {
    public:
        Control();
        std::string get_username();
        std::string get_password();
    };
}

#endif //SRC_CONTROL_H
