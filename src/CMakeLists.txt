cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 23)

add_executable(src main.cpp
        quiz_system.cpp headers/quiz_system.h
        auth/auth.cpp headers/auth/auth.h
        auth/ui.cpp headers/auth/ui.h
        auth/control.cpp headers/auth/control.h
        shared/account_type.cpp headers/shared/account_type.h
        shared/user_data.cpp headers/shared/user_data.h
        database/user.cpp headers/database/user.h
        database/test.cpp headers/database/test.h)
