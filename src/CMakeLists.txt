cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 23)

add_executable(src main.cpp
        # General.
        headers/auth.h auth.cpp
        headers/test_menu.h test_menu.cpp
        headers/test_selector.h test_selector.cpp
        headers/test.h test.cpp
        headers/quiz_system.h quiz_system.cpp

        # Shared.
        headers/shared/user_data.h shared/user_data.cpp

        # test data.
        headers/test_data/test_data.h test_data/test_data.cpp

        # database.
        headers/database/user.h database/user.cpp
        headers/database/test.h database/test.cpp

        # control.
        headers/control/control.h control/control.cpp

        headers/control/auth.h control/auth.cpp

        headers/control/test_selector/test_selector.h
        headers/control/test_selector/student.h control/test_selector/student.cpp
        headers/control/test_selector/teacher.h control/test_selector/teacher.cpp

        headers/control/test_menu/test_menu.h
        headers/control/test_menu/student.h control/test_menu/student.cpp
        headers/control/test_menu/teacher.h control/test_menu/teacher.cpp

        # ui.
        headers/ui/ui.h ui/ui.cpp

        headers/ui/auth.h ui/auth.cpp

        headers/ui/test_menu/test_menu.h
        headers/ui/test_menu/student.h ui/test_menu/student.cpp
        headers/ui/test_menu/teacher.h ui/test_menu/teacher.cpp

        headers/ui/test_selector/test_selector.h
        headers/ui/test_selector/student.h ui/test_selector/student.cpp
        headers/ui/test_selector/teacher.h ui/test_selector/teacher.cpp
        )
 