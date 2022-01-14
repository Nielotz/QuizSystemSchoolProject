cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 23)

add_executable(src main.cpp
        headers/shared/user_data.h shared/user_data.cpp
        headers/shared/quiz_system.h shared/quiz_system.cpp
        headers/shared/auth.h shared/auth.cpp

        headers/control/control.h control/control.cpp
        headers/control/auth.h control/auth.cpp

        headers/database/user.h database/user.cpp
        )
