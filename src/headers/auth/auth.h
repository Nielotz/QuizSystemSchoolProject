//
// Created by Nielotz on 2021-12-17.
//

#ifndef SRC_AUTH_H
#define SRC_AUTH_H


namespace Auth
{
    class UI
    {
    public:
        UI();
        void ask_username();
        void ask_password();
    };

    class Control
    {

    };

    class Auth
    {
        UI ui;
        Control control;

    };
}


#endif //SRC_AUTH_H
