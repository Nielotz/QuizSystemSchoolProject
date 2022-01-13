#ifndef SRC_TEACHER_H
#define SRC_TEACHER_H

#include "../test_selector/test_selector.h"

using namespace std;

namespace Control
{
    namespace TestSelector
    {
        class Teacher : public TestSelector
        {
        public:
            string control_test_selection(vector<string> tests_data);
        };
    }
}

#endif //SRC_TEACHER_H