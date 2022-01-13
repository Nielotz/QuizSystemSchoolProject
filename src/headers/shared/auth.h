//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_AUTH_H
#define SRC_AUTH_H

#include "../headers/control/control.h"
#include "../headers/ui/ui.h"
#include "../headers/shared/user_data.h"

using namespace std;

   class Auth
   {
    public:
        Auth();
        UserData attemp_login(Control::Control control);
    };

#endif //SRC_AUTH_H
