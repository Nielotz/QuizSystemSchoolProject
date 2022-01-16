cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 23)

add_executable(src main.cpp
        headers/shared/user_data.h shared/user_data.cpp
        headers/quiz_system.h quiz_system.cpp
        headers/auth.h auth.cpp
        headers/test_menu.h

        headers/test_data/test_data.h test_data/test_data.cpp

        headers/control/control.h control/control.cpp
        headers/control/auth.h control/auth.cpp
        headers/ui/auth.h ui/auth.cpp

        headers/database/user.h database/user.cpp
        )
