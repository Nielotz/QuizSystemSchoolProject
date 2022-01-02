//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include <utility>

#include "../headers/auth/control.h"
#include "../headers/auth/ui.h"
#include "../headers/shared/user_data.h"

using namespace std;

namespace Auth
{
    class Auth
    {
    private:
        UI auth_ui_;
        Control auth_control_;
        pair <string, string> ask_data();
        UserData check_data();

    public:
        Auth();
        UserData attemp_login();
    };
}

#endif //SRC_AUTH_H
